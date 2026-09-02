#
# Set background to blue and text to white
bluebg="$printf( '\033[48;5;21m')"
echo "\033[38;5;231m"

#
# Print welcome message
echo "Welcome to the CBDE NT pre install script"
echo "_________________________________________"

#
# Options
echo "Do you wish to install(1) uninstall(2) repair(3) or update(4) CBDE NT"
echo $1

if [[ $1 == "1" ]]; then 
    exec ddeps.sh
fi
if [[ $1 == "2" ]]; then 
    exec uninst.sh 
fi 
if [[ $1 == "3" ]]; then 
    echo "WIP"
fi 
if [[ $1 == "4" ]]; then 
    echo "WIP"
fi

#
# Reset colors 
echo "\033[0m"
