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
    this->rootWidget.qtNativeHandle()->setLayout(this->layoutMain.qtNativeHandle());
    this->layoutMain.addLayoutV(this->layoutBottom);
    this->layoutMain.addLayoutV(this->layoutTop);

    //
    // Set spacing for top layout 
    layoutTop.qtNativeHandle()->setSpacing(8);

    //
    // Make the top layout align items to the center
    layoutTop.qtNativeHandle()->setAlignment(Qt::AlignCenter);

    //
    // Resize the texts 
    titleText.resize(40);
    infoText.resize(24);

    layoutTop.addLabel(titleText);
    layoutTop.addLabel(infoText);
}

WelcomePage::~WelcomePage() = default;

void WelcomePage::show() {
    this->rootWidget.show();
}

void WelcomePage::hide() {
    this->rootWidget.hide();
}
