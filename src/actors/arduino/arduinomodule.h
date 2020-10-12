#ifndef ARDUINOMODULE_H
#define ARDUINOMODULE_H

// Base class include
#include "arduinomodulebase.h"

// Kumir includes
#include <kumir2-libs/extensionsystem/kplugin.h>

// Qt includes
#include <QtCore>
#if QT_VERSION >= 0x050000
#   include <QtWidgets>
#else
#   include <QtGui>
#endif

namespace ActorArduino {


class ArduinoModule
    : public ArduinoModuleBase
{
    Q_OBJECT
public /* methods */:
    ArduinoModule(ExtensionSystem::KPlugin * parent);
    static QList<ExtensionSystem::CommandLineParameter> acceptableCommandLineParameters();
public Q_SLOTS:
    void changeGlobalState(ExtensionSystem::GlobalState old, ExtensionSystem::GlobalState current);
    void loadActorData(QIODevice * source);
    void reloadSettings(ExtensionSystem::SettingsPtr settings, const QStringList & keys);
    void reset();
    void terminateEvaluation();

    /* ======== ARDUINO METHODS ======== */
    bool runDigitalRead(const int pin);
    void runDigitalWrite(const int pin, const bool value);
    int runAnalogRead(const int pin);
    void runAnalogWrite(const int pin, const int value);

    /* ========= CLASS PRIVATE ========= */
private:
    Shared::ActorInterface::FunctionList dynamicFunctionList() const;

};


} // namespace ActorArduino

#endif // ARDUINOMODULE_H
