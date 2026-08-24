#include "dsktp.h"

Desktop::Desktop() {
    //
    // Create desktop root window
    this->rootWindow = Window(CW_USEDEFAULT, CW_USEDEFAULT, "If this shows, its a bug");

    //
    // Set window flags
    this->rootWindow.
}
