#include <QApplication>
#include "mainwindow.hpp"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("QtProject");
    QCoreApplication::setApplicationName("Application Example");
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);

    MainWindow mainWin;
    mainWin.show();
    return app.exec();
}
