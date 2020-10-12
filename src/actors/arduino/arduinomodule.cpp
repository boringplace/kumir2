// Self include
#include "arduinomodule.h"

// Qt includes
#include <QtCore>
#if QT_VERSION >= 0x050000
#   include <QtWidgets>
#else
#   include <QtGui>
#endif

namespace ActorArduino {

ArduinoModule::ArduinoModule(ExtensionSystem::KPlugin * parent)
    : ArduinoModuleBase(parent)
{
    // Module constructor, called once on plugin load
    // TODO implement me
}

/* public static */ QList<ExtensionSystem::CommandLineParameter> ArduinoModule::acceptableCommandLineParameters()
{
    // See "src/shared/extensionsystem/commandlineparameter.h" for constructor details
    return QList<ExtensionSystem::CommandLineParameter>();
}

/* public slot */ void ArduinoModule::changeGlobalState(ExtensionSystem::GlobalState old, ExtensionSystem::GlobalState current)
{
    // Called when changed kumir state. The states are defined as enum ExtensionSystem::GlobalState:
    /*
    namespace ExtensionSystem {
        enum GlobalState {
            GS_Unlocked, // Edit mode
            GS_Observe, // Observe mode
            GS_Running, // Running mode
            GS_Input,  // User input required
            GS_Pause  // Running paused
        };
    }
    */
    // TODO implement me
    using namespace ExtensionSystem;  // not to write "ExtensionSystem::" each time in this method scope
    Q_UNUSED(old);  // Remove this line on implementation
    Q_UNUSED(current);  // Remove this line on implementation
}

/* public slot */ void ArduinoModule::loadActorData(QIODevice * source)
{
    // Set actor specific data (like environment)
    // The source should be ready-to-read QIODevice like QBuffer or QFile
    Q_UNUSED(source);  // By default do nothing

}





/* public slot */ void ArduinoModule::reloadSettings(ExtensionSystem::SettingsPtr settings, const QStringList & keys)
{
    // Updates setting on module load, workspace change or appliyng settings dialog.
    // If @param keys is empty -- should reload all settings, otherwise load only setting specified by @param keys
    // TODO implement me
    Q_UNUSED(settings);  // Remove this line on implementation
    Q_UNUSED(keys);  // Remove this line on implementation
}

/* public slot */ void ArduinoModule::reset()
{
    // Resets module to initial state before program execution
    // TODO implement me
}



/* public slot */ void ArduinoModule::terminateEvaluation()
{
    // Called on program interrupt to ask long-running module's methods
    // to stop working
    // TODO implement me
}


/* private */  Shared::ActorInterface::FunctionList ArduinoModule::dynamicFunctionList() const
{
    Shared::ActorInterface::FunctionList result;

//    /* алг функция */
//    result.push_back(Shared::ActorInterface::Function());
//    result.last().id = result.size() - 1;
//    result.last().accessType = Shared::ActorInterface::PublicFunction;
//    result.last().asciiName = QByteArray("function");
//    result.last().localizedNames[QLocale::Russian] = QString::fromUtf8("функция");
//    result.last().returnType = Shared::ActorInterface::Void;

    return result;
}


} // namespace ActorArduino
