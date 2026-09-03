#include "addLayout.h"

void widgetAddLayoutV(Widget& widget, LayoutV& layout) {
    //
    // Add the layout 
    widget.qtNativeHandle()->setLayout(layout.qtNativeHandle());
}

void widgetAddLayoutH(Widget& widget, LayoutH& layout) {
    widget.qtNativeHandle()->setLayout(layout.qtNativeHandle());
}
