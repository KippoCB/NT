#pragma once

#include <memory>

#include <QtWidgets/QGridLayout>

#include <cbui/widget.h>

class GridLayout : public QWidget {
public:
    //
    // Create grid layout 
    GridLayout();
    ~GridLayout();

    //
    // Set alignment
    void setSpacing(int spacing);

    //
    // Get the native qt handle 
    QGridLayout *qtNativeHandle();

    //
    // Add widget 
    void addWidget(Widget widget);
private:
    struct Impl;
    std::unique_ptr<Impl>impl;
};
