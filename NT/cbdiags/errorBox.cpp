#include "errorBox.h"

ErrorBox::ErrorBox(std::string message) :
    errBoxWindow(332, 332, "Error"),
    central(WT_BEVEL),
    ok("ok"),
    errDiag(message),
    main()
{
    //
    // Place elements 
    widgetAddLayoutV(central, main);
    main.alignCenter();

    main.addLabel(errDiag);

    main.addStretch();
    main.addButton(ok);

    ok.onClick([this]() { handleClose (); });
}

void ErrorBox::handleClose() {
    this->errBoxWindow.close();
}

void ErrorBox::show() {
    this->errBoxWindow.show();
}
