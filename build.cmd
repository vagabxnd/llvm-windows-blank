@echo off
setlocal enabledelayedexpansion

set "LLVM_PATH=C:\Program Files\LLVM"
set "NINJA_PATH=%cd%\toolchain\ninja.exe"
set "CMAKE_MAKE_PROGRAM=%cd%\toolchain\ninja.exe"

echo Setting environment variables...
set "CC=%LLVM_PATH%\bin\clang.exe"
set "CXX=%LLVM_PATH%\bin\clang++.exe"

echo Checking tools...
if not exist "%LLVM_PATH%\bin\clang++.exe" (
    echo Error: LLVM not found at %LLVM_PATH%
    pause
    exit /b 1
)

if not exist "%NINJA_PATH%" (
    echo Error: Ninja not found at %NINJA_PATH%
    echo Please download ninja.exe and place it in toolchain folder
    pause
    exit /b 1
)

echo Creating build directory...
if not exist "build" mkdir build

cd build

echo Configuring with CMake...
cmake .. -G Ninja ^
    -DCMAKE_C_COMPILER="%LLVM_PATH%\bin\clang.exe" ^
    -DCMAKE_CXX_COMPILER="%LLVM_PATH%\bin\clang++.exe" ^
    -DCMAKE_MAKE_PROGRAM="%CMAKE_MAKE_PROGRAM%"

if %errorlevel% neq 0 (
    echo CMake configuration failed!
    cd ..
    pause
    exit /b 1
)

echo Building with Ninja...
"%NINJA_PATH%"

if %errorlevel% equ 0 (
    echo Build successful!
    echo Executable: %cd%/%PROJECT_NAME%.exe
) else (
    echo Build failed!
)

cd ..
pause