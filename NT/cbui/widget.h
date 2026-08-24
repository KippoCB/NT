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
private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};
