//========= Coypright (C) CBDE, 2026, All Rights Reserved ==========
//
// File:
//      widget.cpp 
//
// Purpose:
//      This is the cbui widget class. It abstracts qt away via 
//      PImpl and exposes Qt functionality through qtNativeHandle 
//      which returns the pointer to the QWidget.
//
// Author:
//      Vilho Salokannel <github.com/KippoCB>
//
// Edits:
//      23-08-26: Create | Vilho Salokannel <github.com/KippoCB>
//      24-08-26: Add show/hide methods | Vilho Salokannel <github.com/KippoCB>
//
//==================================================================

#include "widget.h"

struct Widget::Impl {
    QWidget widget;
};  

QWidget* Widget::qtNativeHandle() {
    return &impl->widget;
}

Widget::Widget(int widgetType) :
    impl(std::make_unique<Impl>())
{
        
    //
    // Check what widget type it is to style it 
    if (widgetType == WT_BEVEL) {
        impl->widget.setStyleSheet(
                "QWidget {"
                "   background-color: white;"
                "   border: #003593;"
                "   border-radius: 6px;"
                "}"
        );      
    } else if (widgetType == WT_INSET) {
        impl->widget.setStyleSheet(
                "QWidget {"
                "   background-color: white;"
                "   border: #003593;"
                "   border-radius: 6px;"
                "}"        
        );
    }
}

Widget::~Widget() = default;

//
// Reparent the widget
void Widget::setParent(Widget &parent) {
    impl->widget.setParent(parent.qtNativeHandle());
}

//
// Set the width
void Widget::setWidth(int w) {
    impl->widget.setFixedWidth(w);
}

//
// Set the height
void Widget::setHeight(int h) {
    impl->widget.setFixedHeight(h);
}

//
// Show the widget 
void Widget::show() {
    impl->widget.show();
}

//
// Hide the widget 
void Widget::hide() {
    impl->widget.hide();
}

//
// Set the background image 
void Widget::setBackground(std::string path) {
    //
    // Set the background image to auto fill 
    impl->widget.setObjectName("bgWidget");
    impl->widget.setStyleSheet(
            "#bgWidget {"
            "   background-image: url(" + QString::fromStdString(path) + ");"
            "}"
    );
}
