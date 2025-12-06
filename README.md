# LLVM/Clang Blank Project for Windows

A minimal starter template for working with LLVM/Clang on Windows.

# Setup with CMake

Change **LLVM_PATH** in build.cmd file and start it

### Prerequisites

#### Required Tools
1. **CMake** - Version 3.20 or higher (minimum 3.20)
2. **Ninja** - Version 1.11.1 or higher
   - Alternative: You can use **MSVC** build system instead
3. **LLVM/Clang** - Version 21.1.7
4. **Git** - For version control

#### Optional Tools
- **MSYS2/MinGW** - Alternative Unix-like environment
- **Visual Studio 2022** - For MSVC builds (optional)

# Setup with premake5

You can also use premake5 for create project. 

- Start install-premake.cmd, it should create premake5 folder in toolchain directory
- Now you can use build-premake.cmd

## Issues
```
- *Error:* ...windows-blank/toolchain/premake5/premake-ninja/ninja.lua:111: attempt to call a nil value (field 'shell')
```

Just change os.shell into os.host
