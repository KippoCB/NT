//========= Coypright (C) CBDE, 2026, All Rights Reserved ==========
//
// File:
//      widget.h 
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

#pragma once 

#include <memory>

#include <QtWidgets/QWidget>

//
// Widget types
#define WT_BEVEL 0x1
#define WT_INSET 0x2

class Widget : public QWidget {
public:
    //
    // Widget size
    int width, height;

    //
    // Create new widget 
    Widget(int widgetType);
    ~Widget();

    //
    // Reparent
    void setParent(Widget &parent);

    //
    // Get the widgets native handle 
    QWidget *qtNativeHandle();

    //
    // Set width
    void setWidth(int w);

    //
    // Set height
    void setHeight(int h);

    //
    // Show widget 
    void show();

    //
    // Hide widget 
    void hide();

    //
    // Set background image
    void setBackground(std::string path);
private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};
