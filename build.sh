#!/bin/sh
cd "$(dirname "$0")"
x86_64-w64-mingw32-g++ -static -o bin-x64-static/sc.exe main.cpp
i686-w64-mingw32-g++ -static -o bin-x86-static/sc.exe main.cpp

