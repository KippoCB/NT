#!/bin/bash

set -e

BUILD_FILE="build.inc"
SYSTEM_INF="../base/cfgd/init/system.inf"
VERSION_HEADER="../public/version.h"

SYSNAME="CBDE NT"

WALLPAPER=""

mkdir -p cfgd/init
mkdir -p public

# Create build counter if needed
if [ ! -f "$BUILD_FILE" ]; then
    echo "0" > "$BUILD_FILE"
fi

BUILD=$(cat "$BUILD_FILE")
BUILD=$((BUILD + 1))
echo "$BUILD" > "$BUILD_FILE"

DATE=$(date +%d%m%y)
TIME=$(date +%H%M)

# Get git branch
if git rev-parse --is-inside-work-tree >/dev/null 2>&1; then
    BRANCH=$(git branch --show-current)
else
    BRANCH="nogit"
fi

echo
echo "======================================="
echo "       CBDE Build Generator"
echo "======================================="
echo
echo "Channel:"
echo " 1) Developer Release"
echo " 2) Beta"
echo " 3) Release Candidate"
echo " 4) Stable"
echo

read -rp "> " CH

case "$CH" in
    1)
        CHANNEL="Developer Release"
        EVAL=true
        SHOW=true
        ;;
    2)
        CHANNEL="Beta"
        EVAL=true
        SHOW=true
        ;;
    3)
        CHANNEL="Release Candidate"
        EVAL=true
        SHOW=true
        ;;
    4)
        CHANNEL="Stable"
        EVAL=false
        SHOW=false
        ;;
    *)
        echo "Invalid option."
        exit 1
        ;;
esac

echo
echo "Configuration:"
echo " 1) Debug"
echo " 2) Release"
echo

read -rp "> " CFG

case "$CFG" in
    1) CONFIG="Debug" 
        WALLPAPER="/data/data/com.termux/files/cbde/CBDE/longhornalt.jpg"
        ;;
    2) CONFIG="Release" 
        WALLPAPER="/data/data/com.termux/files/cbde/CBDE/longhorn.jpg"
        ;;
    *)
        echo "Invalid option."
        exit 1
        ;;
esac

VERSION="${BUILD}.${DATE}-${BRANCH}-${TIME}"

###############################################################################
# Generate system.inf
###############################################################################

cat > "$SYSTEM_INF" <<EOF
[System]
cbde.system.core.sysname="$SYSNAME"
cbde.system.core.channel="$CHANNEL"
cbde.system.core.configuration="$CONFIG"
cbde.system.core.evaluation="$EVAL"

cbde.system.core.version="$VERSION"
cbde.system.core.showversion="$SHOW"

cbde.system.core.basedir="/data/data/com.termux/files/cbde"
cbde.system.core.sysdir="/data/data/com.termux/files/cbde/CBDE"
cbde.system.core.appdir="/data/data/com.termux/files/cbde/user/Desktop"
cbde.system.core.bdirshort="/CBDE"

[Desktop]
cbde.system.desktop.wp="$WALLPAPER"
EOF

###############################################################################
# Generate version.h
###############################################################################

cat > "$VERSION_HEADER" <<EOF
#pragma once

#define CBDE_SYSNAME "$SYSNAME"

#define CBDE_CHANNEL "$CHANNEL"
#define CBDE_CONFIGURATION "$CONFIG"

#define CBDE_VERSION "$VERSION"

#define CBDE_BUILD $BUILD
#define CBDE_BUILD_DATE "$DATE"
#define CBDE_BUILD_TIME "$TIME"
#define CBDE_GIT_BRANCH "$BRANCH"

#define CBDE_EVALUATION $EVAL
#define CBDE_SHOWVERSION $SHOW
EOF

echo
echo "======================================="
echo "Build Information"
echo "======================================="
echo "Product : $SYSNAME"
echo "Channel : $CHANNEL"
echo "Config  : $CONFIG"
echo "Branch  : $BRANCH"
echo "Version : $VERSION"
echo "======================================="
echo
echo "Generated:"
echo "  $SYSTEM_INF"
echo "  $VERSION_HEADER"
echo
