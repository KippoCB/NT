#include <QtWidgets/QApplication>

#include <cbui/window.h>
#include <cbui/widget.h>
#include <cbui/button.h>
#include <cbui/layoutH.h>

int main(int argc, char *argv[]) {
    //
    // Create app
    QApplication app(argc, argv);

    //
    // Create window 
    Window window(640, 480, "Installer");

    //
    // Create central widget 
    Widget central(WT_BEVEL);

    //
    // Create layout for central 
    LayoutH mainL;
    mainL.setParent(central);
    
    //
    // Make a button 
    Button button("Ok");
    button.setParent(central);

    button.onClick([&window] {
            window.close();
    });

    //
    // Make the widget central 
    window.setCentral(central);

    //
    // Show window and run loop
    window.show();

    return app.exec();
}   
