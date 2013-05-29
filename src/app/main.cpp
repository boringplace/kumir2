#include <QtCore>
#include <QtGui>

#include "extensionsystem/pluginmanager.h"

#ifdef Q_OS_MAC
#  define PLUGINS_PATH QDir(QApplication::applicationDirPath()+"/../PlugIns").canonicalPath()
#  define SHARE_PATH "/../Resources"
#else
#  define PLUGINS_PATH QDir(QApplication::applicationDirPath()+"/../"+IDE_LIBRARY_BASENAME+"/kumir2/plugins").canonicalPath()
#  define SHARE_PATH "/../share/kumir2"
#endif


void GuiMessageOutput(QtMsgType type, const char *msg)
{
    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s\n", msg);
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s\n", msg);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s\n", msg);
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s\n", msg);
        abort();
    default:
        break;
    }
}

void ConsoleMessageOutput(QtMsgType type, const char *msg)
{
    switch (type) {
    case QtDebugMsg:
//        fprintf(stderr, "Debug: %s\n", msg);
        break;
    case QtWarningMsg:
//        fprintf(stderr, "Warning: %s\n", msg);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s\n", msg);
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s\n", msg);
        abort();
    default:
        break;
    }
}

void showErrorMessage(const QString & text)
{
    bool gui = true;
#ifdef Q_WS_X11
    gui = gui && getenv("DISPLAY")!=0;
#endif

    if (gui) {
        QMessageBox::critical(0, "Kumir 2 Launcher", text);
    }
    else {
        qCritical("%s", qPrintable(text));
    }
}

QString getLanguage()
{
    return "ru"; // TODO implement sometime in future...
}


class Application
        : public QApplication
{
public:
    inline explicit Application(int & argc, char **argv, bool gui)
        : QApplication(argc, argv, gui)
        , timerId_(-1)
        , splashScreen_(nullptr)
        , started_(false)
    {}
    inline bool notify(QObject * receiver, QEvent * event) {
        bool result = false;
        try {
            result = QApplication::notify(receiver, event);
        }
        catch (...) {
            qDebug() << "Exception caught in QApplication::notify!!!";
            if (arguments().contains("--debug"))
                abort();
        }
        return result;
    }

    inline void setSplashScreen(QSplashScreen * s) {
        splashScreen_ = s;
    }

    inline void initialize() {
        if (started_) {
            return;
        }
        started_ = true;
        bool gui = true;
#ifdef Q_WS_X11
        gui = gui && getenv("DISPLAY")!=0;
#endif
        const QString sharePath = QDir(applicationDirPath()+SHARE_PATH).canonicalPath();
        QDir translationsDir(sharePath+"/translations");
        QStringList ts_files = translationsDir.entryList(QStringList() << "*_"+getLanguage()+".qm");
        foreach (QString tsname, ts_files) {
            tsname = tsname.mid(0, tsname.length()-3);
            QTranslator * tr = new QTranslator(this);
            if (tr->load(tsname, sharePath+"/translations")) {
                installTranslator(tr);
            }
        }

        setProperty("sharePath", sharePath);

        QSettings::setDefaultFormat(QSettings::IniFormat);
        addLibraryPath(PLUGINS_PATH);
        ExtensionSystem::PluginManager * manager = new ExtensionSystem::PluginManager;
        QObject::connect (this, SIGNAL(aboutToQuit()), manager, SLOT(shutdown()));
        manager->setPluginPath(PLUGINS_PATH);
        manager->setSharePath(SHARE_PATH);
        QString error;

    #ifdef CONFIGURATION_TEMPLATE
        const QString defaultTemplate = CONFIGURATION_TEMPLATE;
    #else
    #error No default configuration passed to GCC
    #endif
        QString templ = defaultTemplate;
        for (int i=1; i<argc(); i++) {
            QString arg = QString::fromLocal8Bit(argv()[i]);
            if (arg.startsWith("[") && arg.endsWith("]")) {
                templ = arg.mid(1, arg.length()-2);
            }
        }
        error = manager->loadPluginsByTemplate(templ);
        if (!gui && manager->isGuiRequired()) {
            if (splashScreen_)
                splashScreen_->finish(0);
            showErrorMessage("Requires X11 session to run this configuration");
            exit(1);
        }

        qInstallMsgHandler(manager->isGuiRequired()
                           ? GuiMessageOutput
                           : ConsoleMessageOutput);

        if (!error.isEmpty()) {
            if (splashScreen_)
                splashScreen_->finish(0);
            showErrorMessage(error);
            exit(1);
        }
        error = manager->initializePlugins();
        if (!error.isEmpty()) {
            if (splashScreen_)
                splashScreen_->finish(0);
            showErrorMessage(error);
            exit(property("returnCode").isValid()
                    ? property("returnCode").toInt() : 1);
        }
        // GUI requirement may be changed as result of plugins initialization,
        // so check it again
        if (!gui && manager->isGuiRequired()) {
            showErrorMessage("Requires X11 session to run this configuration");
            exit(property("returnCode").isValid()
                    ? property("returnCode").toInt() : 1);
        }
        if (splashScreen_)
            splashScreen_->finish(0);
        error = manager->start();
        if (!error.isEmpty()) {
            if (splashScreen_)
                splashScreen_->finish(0);
            showErrorMessage(error);
            exit(property("returnCode").isValid()
                    ? property("returnCode").toInt() : 1);
        }
        if (!manager->isGuiRequired()) {
            quit();
        }
    }

    inline void timerEvent(QTimerEvent * event) {        
        event->accept();
        initialize();
    }

    inline int main() {
        timerId_ = startTimer(250);
        int ret = exec();
        killTimer(timerId_);
        if (ret == 0) {
            return property("returnCode").isValid()
                    ? property("returnCode").toInt() : 0;
        }
        else {
            return ret;
        }
    }
private:
    int timerId_;
    QSplashScreen * splashScreen_;
    bool started_;
};

int main(int argc, char **argv)
{ 
    QString gitHash = QString::fromAscii(GIT_HASH);
    QString gitTag = QString::fromAscii(GIT_TAG);
    QString gitBranch = QString::fromAscii(GIT_BRANCH);
    QDateTime gitTimeStamp = QDateTime::fromTime_t(GIT_TIMESTAMP);


    bool gui = true;
#ifdef Q_WS_X11
    gui = gui && getenv("DISPLAY")!=0;
#endif
    Application * app = new Application(argc, argv, gui);
    QLocale russian = QLocale("ru_RU");
    QLocale::setDefault(russian);
#ifdef Q_OS_WIN32
    app->addLibraryPath(app->applicationDirPath());
#endif
#ifndef Q_OS_WIN32
    app->addLibraryPath(QDir::cleanPath(app->applicationDirPath()+"/../"+IDE_LIBRARY_BASENAME+"/kumir2/"));
#endif

    app->setApplicationVersion(gitTag.length() > 0
                               ? gitTag : gitBranch + "/" + gitHash);
    app->setProperty("gitTimeStamp", gitTimeStamp);
    QSplashScreen * splashScreen = 0;

    const QString sharePath = QDir(app->applicationDirPath()+SHARE_PATH).canonicalPath();

#ifdef SPLASHSCREEN
    if (gui) {
        QString imgPath = sharePath+QString("/")+SPLASHSCREEN;
        splashScreen = new QSplashScreen();
        QImage img(imgPath);
        QPainter p(&img);
        p.setPen(QColor(Qt::black));
        p.setBrush(QColor(Qt::black));
        QFont f = p.font();

        f.setPixelSize(12);
        p.setFont(f);
        QString v = qApp->applicationVersion();
        if (app->property("gitHash").isValid()) {
            v += " (GIT "+app->property("gitHash").toString()+")";
        }
        int tw = QFontMetrics(f).width(v);
        int th = QFontMetrics(f).height();
        int x = img.width() - tw - 8;
        int y = 8;
        p.drawText(x, y, tw, th, 0, v);
        p.end();
        QPixmap px = QPixmap::fromImage(img);
        splashScreen->setPixmap(px);
        splashScreen->show();
        qApp->processEvents();
        app->setSplashScreen(splashScreen);
    }
#endif
    return app->main();
}

