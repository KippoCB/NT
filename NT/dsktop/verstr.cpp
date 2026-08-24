#include "verstr.h"

#include <base/cfgd/ipccli.h>

Verstr::Verstr(std::string title) :
    label(title),
    lytH()
{
    IpcApi ipc;
    //
    // Get version information from version.h
    std::string text = CBDE_SYSNAME;

    if (CBDE_EVALUATION == true) 
        text += "\nEvaluation copy.";

    if (CBDE_SHOWVERSION == true)
    {
        text += "Version ";
        text += CBDE_VERSION;
        text += " ";
        text += CBDE_CONFIGURATION;
    }

    text += "\n";
    text += "/CBDE";

    //
    // Set text 
    this->label.setText(text);

    //
    // Set layout as parent
    //
    // We have to do this via the raw qt handles as cbui does 
    // not yet support having a layout as a parent instead of 
    // an widget.
    this->lytH.addStretch();
    this->lytH.qtNativeHandle()->addItem(
        (QLayoutItem)this->label.qtNativeHandle()
    );
}
