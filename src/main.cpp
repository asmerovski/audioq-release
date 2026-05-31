#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    app.setApplicationName("AudioQ");
    app.setApplicationVersion("1.0");
    app.setOrganizationName("AudioQ");
    MainWindow w;
    w.show();
    return app.exec();
}
