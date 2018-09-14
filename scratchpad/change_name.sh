#!/usr/bin/env bash

if [[ $# -ne 1 ]]; then
    echo "Missing name of file to change to!"
    exit 0
fi
mv *.cpp $1.cpp
