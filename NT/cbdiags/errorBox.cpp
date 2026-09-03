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
    
}

void ErrorBox::handleClose() {
    this->errBoxWindow.close();
}
