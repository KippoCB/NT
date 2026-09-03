#include "welcomePage.h"

WelcomePage::WelcomePage() :
    rootWidget(WT_BEVEL),
    layoutMain(),
    layoutTop(),
    layoutBottom(),
    titleText("Welcome to the CBDE setup program."),
    infoText("This program will guide you through the installation process."),
    copyrightText("Copyright (C) CBDE 2026"),
    next("next"),
    cancel("cancel")
{
    //
    // Set backround image 
    this->rootWidget.setBackground("res/setupbg.jpg"); 

    //
    // Place elements 
    widgetAddLayoutV(this->rootWidget, this->layoutMain);
    this->layoutMain.addLayoutV(this->layoutTop);
    this->layoutMain.addStretch();
    this->layoutMain.qtNativeHandle()->addLayout(this->layoutBottom.qtNativeHandle());
 
    //
    // Set spacing for top layout 
    layoutTop.qtNativeHandle()->setSpacing(8);
    
    //
    // Make the top layout align items to the center
    layoutTop.alignCenter();
 
    //
    // Resize the texts 
    titleText.resize(32);
    infoText.resize(16);

    layoutTop.addLabel(titleText);
    layoutTop.addLabel(infoText);

    layoutBottom.alignCenter();
    layoutBottom.addButton(cancel);
    layoutBottom.addButton(next);
}

WelcomePage::~WelcomePage() = default;

void WelcomePage::show() {
    this->rootWidget.show();
}

void WelcomePage::hide() {
    this->rootWidget.hide();
}
