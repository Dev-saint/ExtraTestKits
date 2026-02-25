@echo off
:: choose generator, override with environment variable if needed
if "%CMAKE_GENERATOR%"=="" (
    set "CMAKE_GENERATOR=MinGW Makefiles"
)
echo Using CMake generator: %CMAKE_GENERATOR%
cmake -S . -B build -G "%CMAKE_GENERATOR%"
cmake --build build