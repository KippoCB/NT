#
# Download all dependencies needed to run CBDE NT 
echo "Do you want to install the required dependencies to run CBDE NT? [y/n]"
echo $1

if [[$1 == "y" ]]; then
    pkg install qt5-qtbase openbox tigervnc x11-repo
else
    echo "Continuing install..."
fi
