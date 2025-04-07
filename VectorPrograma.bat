@echo off

cd build
cmake ..
cmake --build .

cd "C:\Users\Dell\Documents\VU MIF\Objektinis programavimas\obj.programavimas\build\vektoriai\Debug"
VectorProgram.exe

pause