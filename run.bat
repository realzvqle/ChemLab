@echo off

xmake build chemlab
copy raylib.dll "build/windows/x64/release/"
xmake run chemlab