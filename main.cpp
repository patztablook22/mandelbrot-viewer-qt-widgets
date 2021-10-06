#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setApplicationName("Mandelbrot Viewer");
    MainWindow w;
    w.setWindowTitle("");
    w.show();
    return a.exec();
}
