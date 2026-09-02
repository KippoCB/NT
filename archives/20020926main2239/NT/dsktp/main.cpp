#include <QtWidgets/QApplication>

#include "dsktp.h"

int main(int argc, char *argv[]) {
    //
    // Create app
    QApplication app(argc, argv);

    //
    // Create desktop 
    Desktop desktop;

    return app.exec();
}
