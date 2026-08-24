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
                "   background-color: #d4d0c8;"
                "   border-left: 3px solid white;"
                "   border-top: 3px solid white;"
                "   border-right: 2px solid black;"
                "   border-bottom: 2px solid black;"
                "}"
        );      
    } else if (widgetType == WT_INSET) {
        impl->widget.setStyleSheet(
                "QWidget {"
                "   background-color: white;"
                "   border-left: 2px solid black;"
                "   border-top: 2px solid black;"
                "   border-right: 3px solid white;"
                "   border-bottom: 3px solid white;"
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
