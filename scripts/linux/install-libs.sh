#!/bin/bash

#Update git submodules
cd ../../ext
rm -r raygui
rm -r raylib
cd ../
git submodule update

#Install raylib
cd ext/raylib/src/
make clean
make PLATFORM=PLATFORM_DESKTOP
make install
cd ../../../

#Move raygui
cp ext/raygui/src/raygui.h src/libs/raygui/raygui.h
cp ext/raygui/src/icons src/libs/raygui/icons
cp ext/raygui/src/extras src/libs/raygui/extras
