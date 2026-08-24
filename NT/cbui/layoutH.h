#pragma once 

#include <memory>

#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>

#include <cbui/widget.h>

class LayoutH : public QWidget {
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
private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};
