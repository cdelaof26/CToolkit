#!/bin/bash

if [ -z "$1" ]; then
    echo "No utility name provided. Usage: $0 utility"
    exit 1
fi

if [ ! -d "$1" ]; then
    echo "Utility directory does not exist. Usage: $0 utility"
    exit 1
fi

gcc testing/t$1.c $1/*.c -o t && ./t
