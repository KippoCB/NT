#include "tskbnd.h"

Taskband::Taskband() :
    taskBand(WT_BEVEL),
    taskBLayout()
{
    //
    // Make taskbar 40px high
    this->taskBand.setHeight(40);

    //
    // Set layout parent
    this->taskBLayout.setParent(this->taskBand);
}
