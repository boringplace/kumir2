/*
DO NOT EDIT THIS FILE!

This file is autogenerated from "--update" and will be replaced
every build time

*/

// Self includes
#include "drawmodulebase.h"
#include "drawplugin.h"

// Kumir includes
#include <kumir2-libs/extensionsystem/kplugin.h>

// Qt includes
#include <QtCore>
#include <QtGui>

namespace ActorDraw {

DrawModuleBase::DrawModuleBase(ExtensionSystem::KPlugin* parent)
    : QObject(parent)
{
    bool hasGui = true;
#ifdef Q_OS_LINUX
    hasGui = getenv("DISPLAY")!=0;
#endif
    if (hasGui) {
        static const QString currentLocaleName = QLocale().name();
        
        m_menuDraw = new QMenu();
        if (currentLocaleName=="ru_RU") {
            m_menuDraw->setTitle(QString::fromUtf8("Чертежник"));
        }
        else {
            m_menuDraw->setTitle(QString::fromLatin1("Draw"));
        }
        
        m_actionDrawLoadDrawing = m_menuDraw->addAction("");
        if (currentLocaleName=="ru_RU") {
            m_actionDrawLoadDrawing->setText(QString::fromUtf8("Загрузить чертеж..."));
        }
        else {
            m_actionDrawLoadDrawing->setText(QString::fromLatin1("Load Drawing..."));
        }
        
        m_actionDrawSaveDrawing = m_menuDraw->addAction("");
        if (currentLocaleName=="ru_RU") {
            m_actionDrawSaveDrawing->setText(QString::fromUtf8("Сохранить чертеж..."));
        }
        else {
            m_actionDrawSaveDrawing->setText(QString::fromLatin1("Save Drawing..."));
        }
        
        
    }
}

/* protected */ const ExtensionSystem::CommandLine& DrawModuleBase::commandLineParameters() const
{
    DrawPlugin * plugin = qobject_cast<DrawPlugin*>(parent());
    return plugin->commandLineParameters_;
}

/* public virtual */ void DrawModuleBase::handleGuiReady()
{
}

/* public virtual */ QString DrawModuleBase::initialize(const QStringList &configurationParameters, const ExtensionSystem::CommandLine & runtimeParameters)
{
    Q_UNUSED(configurationParameters);
    Q_UNUSED(runtimeParameters);

    // Return error text or an empty string on successfull  initialization
    return QString();
}

/* public virtual */ bool DrawModuleBase::isSafeToQuit()
{
    return true;
}

/* public virtual slot */ void DrawModuleBase::loadActorData(QIODevice * source)
{
    Q_UNUSED(source);  // By default do nothing

}



/* public */ QList<QMenu*> DrawModuleBase::moduleMenus() const
{
    bool hasGui = true;
#ifdef Q_OS_LINUX
    hasGui = getenv("DISPLAY")!=0;
#endif
    if (hasGui) {
        QList<QMenu*> result;
        result.push_back(m_menuDraw);
        
        return result;
    }
    else {
        return QList<QMenu*>();
    }
}

/* protected */ void DrawModuleBase::msleep(unsigned long msecs)
{
    DrawPlugin* plugin = qobject_cast<DrawPlugin*>(parent());
    plugin->msleep(msecs);
}

/* public */ QDir DrawModuleBase::myResourcesDir() const
{
    DrawPlugin* plugin = qobject_cast<DrawPlugin*>(parent());
    return plugin->myResourcesDir();
}

/* public */ ExtensionSystem::SettingsPtr DrawModuleBase::mySettings() const
{
    DrawPlugin* plugin = qobject_cast<DrawPlugin*>(parent());
    return plugin->mySettings();
}





/* protected */ void DrawModuleBase::setError(const QString & errorText)
{
    DrawPlugin* plugin = qobject_cast<DrawPlugin*>(parent());
    plugin->errorText_ = errorText;
}

/* protected */ void DrawModuleBase::sleep(unsigned long secs)
{
    DrawPlugin* plugin = qobject_cast<DrawPlugin*>(parent());
    plugin->sleep(secs);
}

/* public virtual */ QVariantList DrawModuleBase::templateParameters() const
{
    DrawPlugin * plugin = qobject_cast<DrawPlugin*>(parent());
    return plugin->defaultTemplateParameters();
}

/* protected */ void DrawModuleBase::usleep(unsigned long usecs)
{
    DrawPlugin* plugin = qobject_cast<DrawPlugin*>(parent());
    plugin->usleep(usecs);
}



} // namespace ActorDraw
