//#include "../shared/qstd.h"

#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //const string GENES = "12345";
    //const string TARGET = "2048";


    MainWindow w;
    w.show();
    return app.exec();
}
