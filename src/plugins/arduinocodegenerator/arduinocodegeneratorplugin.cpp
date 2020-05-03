#include <QtCore> // include it before STL to avoid MSVC-specific errors
#include <sstream>
#include <cstdlib>
#include <kumir2-libs/stdlib/kumirstdlib.hpp>
#include <kumir2-libs/vm/variant.hpp>
#include <kumir2-libs/vm/vm_bytecode.hpp>
#include "generator.h"
#include "arduinocodegeneratorplugin.h"
#include <kumir2-libs/extensionsystem/pluginmanager.h>

using namespace ArduinoCodeGenerator;
using namespace Bytecode;

static const QString MIME_ARDUINO_C_SOURCE = QString::fromLatin1("text/plain");

ArduinoCodeGeneratorPlugin::ArduinoCodeGeneratorPlugin()
    : KPlugin()
    , d(new Generator(this))
    , textMode_(false)
{
}

QList<ExtensionSystem::CommandLineParameter>
ArduinoCodeGeneratorPlugin::acceptableCommandLineParameters() const
{
    using ExtensionSystem::CommandLineParameter;
    QList<CommandLineParameter> result;
    result << CommandLineParameter(
                  false,
                  's', "assembly",
                  tr("Generate bytecode assemby text instead of executable code")
                  );
    result << CommandLineParameter(
                  false,
                  'g', "debuglevel",
                  tr("Generate code with debug level from 0 (nothing) to 2 (maximum debug information)"),
                  QVariant::Int, false
                  );
    return result;
}

QString ArduinoCodeGeneratorPlugin::initialize(const QStringList &/*configurationArguments*/,
                                             const ExtensionSystem::CommandLine &runtimeArguments)
{    
    textMode_ = runtimeArguments.hasFlag('s');
    DebugLevel debugLevel = LinesOnly;
    if (runtimeArguments.value('g').isValid()) {
        int level = runtimeArguments.value('g').toInt();
        level = qMax(0, level);
        level = qMin(2, level);
        debugLevel = DebugLevel(level);
    }
    setDebugLevel(debugLevel);
    return QString();
}

void ArduinoCodeGeneratorPlugin::setOutputToText(bool flag)
{
    textMode_ = false;
}

void ArduinoCodeGeneratorPlugin::createPluginSpec()
{
    _pluginSpec.name = "ArduinoCodeGenerator";
    _pluginSpec.provides.append("Generator");
    _pluginSpec.gui = false;
}

void ArduinoCodeGeneratorPlugin::setDebugLevel(DebugLevel debugLevel)
{
    d->setDebugLevel(debugLevel);
}

void ArduinoCodeGeneratorPlugin::start()
{

}

void ArduinoCodeGeneratorPlugin::stop()
{

}

void ArduinoCodeGeneratorPlugin::generateExecutable(
        const AST::DataPtr tree,
        QByteArray & out,
        QString & mimeType,
        QString & fileSuffix
        )
{
    Data data;

    QList<AST::ModulePtr> & modules = tree->modules;

    d->reset(tree, &data);
    AST::ModulePtr userModule, teacherModule;
    AST::ModulePtr linkedModule = AST::ModulePtr(new AST::Module);
    for (int i=0; i<modules.size(); i++) {
        AST::ModulePtr mod = modules[i];
        if (mod->header.type == AST::ModTypeUserMain) {
            userModule = mod;
        }
        else if (mod->header.type == AST::ModTypeTeacherMain) {
            teacherModule = mod;
        }
        else {
            d->addModule(tree->modules[i]);
        }
    }    
    linkedModule->impl.globals = userModule->impl.globals;
    linkedModule->impl.initializerBody = userModule->impl.initializerBody;
    linkedModule->impl.algorhitms = userModule->impl.algorhitms;
    linkedModule->header.algorhitms = userModule->header.algorhitms;
    modules.removeAll(userModule);
    if (teacherModule) {
        linkedModule->impl.globals += teacherModule->impl.globals;
        linkedModule->impl.initializerBody += teacherModule->impl.initializerBody;
        linkedModule->impl.algorhitms += teacherModule->impl.algorhitms;
        linkedModule->header.algorhitms += teacherModule->header.algorhitms;
        modules.removeAll(teacherModule);
    }
    modules.push_back(linkedModule);
    d->addModule(linkedModule);
    d->generateConstantTable();
    d->generateExternTable();
    modules.pop_back();
    modules.push_back(userModule);
    if (teacherModule) {
        modules.push_back(teacherModule);
    }

    data.versionMaj = 2;
    data.versionMin = 0;
    data.versionRel = 90;
    std::list<char> buffer;

    std::ostringstream stream;
    Bytecode::bytecodeToTextStream(stream, data);
    const std::string text = stream.str();
    out = QByteArray(text.c_str(), text.size());
    mimeType = MIME_ARDUINO_C_SOURCE;
    fileSuffix = ".kumir.c";
    qDebug() << QString::fromLatin1(out);
}


#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN(ArduinoCodeGeneratorPlugin)
#endif
