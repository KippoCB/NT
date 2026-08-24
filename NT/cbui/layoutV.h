//========= Coypright (C) CBDE, 2026, All Rights Reserved ==========
//
// File:
//      LayoutV.h 
//
// Purpose:
//      This is the vertical layout implementation for cbui.
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
#include <QtWidgets/QVBoxLayout>

#include <cbui/widget.h>
#include <cbui/label.h>

class LayoutV : public QWidget {
public: 
    class LayoutH;

    LayoutV();
    ~LayoutV();

    //
    // Set the parent 
    void setParent(Widget &parent);

    //
    // Add a stretch to the layout
    void addStretch();

    //
    // Get the native Qt handle 
    QVBoxLayout *qtNativeHandle();

    //
    // Add widget 
    void addWidget(Widget &widget);

    //
    // Add layout (h/v)
    void addLayoutV(LayoutV &lyt);

    //
    // Add a label 
    void addLabel(Label &label);
private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};
