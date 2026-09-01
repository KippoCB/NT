#!/data/data/com.termux/files/usr/bin/bash

CBDE="/data/data/com.termux/files/NT/CBDE"

export LD_LIBRARY_PATH="$CBDE:${LD_LIBRARY_PATH:-}"

exec "$CBDE/desktop"
