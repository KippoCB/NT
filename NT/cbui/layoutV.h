#pragma once 

#include <memory>

#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>

#include <cbui/widget.h>

class LayoutV : public QWidget {
public: 
    LayoutV(Widget parent);
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
private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};
