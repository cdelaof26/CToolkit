#!/bin/bash

if [ -z "$1" ]; then
    echo "No utility name provided. Usage: $0 utility"
    exit 1
fi

if [ ! -d "$1" ]; then
    echo "Utility directory does not exist. Usage: $0 utility"
    exit 1
fi

if [ "$1" = "node" ]; then
    gcc testing/t$1.c $1/*.c str/*.c -o t && ./t
    exit 0
fi

gcc testing/t$1.c $1/*.c -o t && ./t
