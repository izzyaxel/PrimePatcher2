@echo OFF

:choosetype
set /P buildtype="Debug[D] / Release[R]: "
if /I "%buildtype%"=="D" goto :debug
if /I "%buildtype%"=="R" goto :release
goto :choosetype

:debug
cmake ../ -DCMAKE_BUILD_TYPE=Debug -G "MinGW Makefiles"
PAUSE
goto :make

:release
cmake ../ -DCMAKE_BUILD_TYPE=Release -G "MinGW Makefiles"
PAUSE

:make
cls
mingw32-make

del /S CMakeCache.txt
del /S cmake_install.cmake
del /S Makefile
rd /S /Q CMakeFiles
PAUSE