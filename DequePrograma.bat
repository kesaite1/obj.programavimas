@echo off

cd build
cmake ..
cmake --build .

cd "C:\Users\Dell\Documents\VU MIF\Objektinis programavimas\obj.programavimas\build\deque\Debug"
DequeProgram.exe

pause