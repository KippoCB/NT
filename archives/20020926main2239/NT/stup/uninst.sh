#!/data/data/com.termux/files/usr/bin/bash

echo "Uninstall CBDE NT"
echo "_________________"
echo

INSTALLDIR="/data/data/com.termux/files/NT"
BOOTFILE="/data/data/com.termux/files/usr/bin/boot.sh"

echo "Do you want to uninstall CBDE NT? (Y/N)"
read -r answer

if [ "$answer" = "Y" ] || [ "$answer" = "y" ]; then
    echo "Removing CBDE NT..."

    rm -rf "$INSTALLDIR"
    rm -f "$BOOTFILE"

    echo "CBDE NT has been uninstalled."
else
    echo "Your system has not been modified."
fi
