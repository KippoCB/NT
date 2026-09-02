#!/data/data/com.termux/files/usr/bin/bash

echo "CBDE NT Installer"
echo "_________________"
echo

# Install directory
INSTALLDIR="/data/data/com.termux/files/NT"

# Prerelease warning
echo "This is prerelease software. Everything is subject to change!"
echo

# Ask if we want to install
echo "Do you want to install CBDE NT to $INSTALLDIR ? (Y/N)"
read -r answer

if [ "$answer" = "Y" ] || [ "$answer" = "y" ]; then

    echo "Creating installation directories..."
    mkdir -p "$INSTALLDIR/CBDE"
    mkdir -p "$INSTALLDIR/User/Desktop"

    echo "Copying installation files onto your system..."

    cp -r "../cbui/libcbui.so" \
          "../dsktp/desktop" \
          "../public/version.h" \
          "../dsktp/res/img0.jpg" \
          "$INSTALLDIR/CBDE/"

    echo "Copying boot.sh to Termux bin..."
    cp "./boot.sh" \
       "/data/data/com.termux/files/usr/bin/"

    echo
    echo "CBDE NT installed successfully!"

else
    echo
    echo "Your system has not been modified."
fi
