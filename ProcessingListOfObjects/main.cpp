#include "processingobjects.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include "group.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "processing-list-of-objects_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    ManagerGroup mg;
    ProcessingObjects w(nullptr, mg);
    
    w.show();

    return a.exec();
}
