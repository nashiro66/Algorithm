@echo off

cd %~dp0
if not exist build (
    mkdir build
)

cmake -S . -B build -G "Visual Studio 16 2019" -A x64

pause