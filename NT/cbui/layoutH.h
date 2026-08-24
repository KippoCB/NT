//========= Coypright (C) CBDE, 2026, All Rights Reserved ==========
//
// File:
//      LayoutH.h 
//
// Purpose:
//      This is the horizontal layout implementation for cbui.
//
// Author:
//      Vilho Salokannel <github.com/KippoCB>
//
// Edits:
//      24-08-26: Create | Vilho Salokannel <github.com/KippoCB>
//
//==================================================================

#pragma once 

#include <memory>

#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>

#include <cbui/widget.h>
#include <cbui/label.h>

class LayoutH {
public: 
    LayoutH();
    ~LayoutH();

    //
    // Set the parent 
    void setParent(Widget &parent);

    //
    // Add a stretch to the layout
    void addStretch();

    //
    // Get the native Qt handle 
    QHBoxLayout *qtNativeHandle();

    //
    // add widget
    void addWidget(Widget &widget);

    //
    // add layout (h/v)
    void addLayoutH(LayoutH &lyt);

    //
    // add label 
    void addLabel(Label &label);
private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};
