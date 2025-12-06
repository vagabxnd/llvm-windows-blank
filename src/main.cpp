#include "config.h"
#include <iostream>

int main() {
    std::cout << "Project: " << PROJECT_NAME << std::endl;
    std::cout << "Version: " << PROJECT_VERSION << std::endl;
    std::cout << "C++ Standard: " << __cplusplus << std::endl;
    
    std::cout << "Compiler: ";
    
    #if defined(__clang__)
        // Clang/LLVM
        std::cout << "Clang/LLVM " << __clang_major__ << "." 
                  << __clang_minor__ << "." << __clang_patchlevel__ << std::endl;
        std::cout << "Clang version string: " << __clang_version__ << std::endl;
        
    #elif defined(__GNUC__) || defined(__GNUG__)
        // GNU GCC
        std::cout << "GCC " << __GNUC__ << "." 
                  << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__ << std::endl;
        
    #elif defined(_MSC_VER)
        // Microsoft Visual C++
        std::cout << "MSVC " << _MSC_VER << std::endl;
        
    #elif defined(__INTEL_COMPILER)
        // Intel Compiler
        std::cout << "Intel " << __INTEL_COMPILER << std::endl;
        
    #elif defined(__MINGW32__) || defined(__MINGW64__)
        // MinGW
        std::cout << "MinGW ";
        #if defined(__MINGW64__)
            std::cout << "64-bit ";
        #else
            std::cout << "32-bit ";
        #endif
        std::cout << __MINGW32_MAJOR_VERSION << "." 
                  << __MINGW32_MINOR_VERSION << std::endl;
        
    #else
        std::cout << "Unknown compiler" << std::endl;
    #endif
    
    #ifdef __clang__
        #ifdef __apple_build_version__
            std::cout << "Apple Clang build: " << __apple_build_version__ << std::endl;
        #endif
        
        #ifdef __llvm__
            std::cout << "LLVM backend" << std::endl;
        #endif
        
        #if __cplusplus >= 202606L
            std::cout << "Status: C++26 FULL support" << std::endl;
        #elif __has_feature(cxx26)
            std::cout << "Status: C++26 partial/experimental support" << std::endl;
        #else
            std::cout << "Status: C++26 not supported" << std::endl;
        #endif
        
    #elif defined(__GNUC__)
        #if __GNUC__ >= 14
            std::cout << "Status: C++26 partial support (GCC 14+)" << std::endl;
        #elif __GNUC__ >= 13
            std::cout << "Status: C++23 with some C++26 features" << std::endl;
        #else
            std::cout << "Status: Older C++ standard" << std::endl;
        #endif
    #endif
    
    std::cout << "Platform: ";
    #ifdef _WIN32
        std::cout << "Windows";
        #ifdef _WIN64
            std::cout << " 64-bit";
        #else
            std::cout << " 32-bit";
        #endif
    #elif __linux__
        std::cout << "Linux";
    #elif __APPLE__
        std::cout << "macOS";
    #elif __unix__
        std::cout << "Unix";
    #else
        std::cout << "Unknown";
    #endif
    std::cout << std::endl;
    
    std::cout << "Compiled on: " << __DATE__ << " at " << __TIME__ << std::endl;
    
    #if __cplusplus >= 202606L
        std::cout << "\nC++26 features check:" << std::endl;
        std::cout << "--------------------" << std::endl;
        
        #ifdef __cpp_if_consteval
            std::cout << "if consteval" << std::endl;
        #endif
        
        #ifdef __cpp_multidimensional_subscript
            std::cout << "Multidimensional subscript" << std::endl;
        #endif
        
        #ifdef __cpp_range_based_for_initializer
            std::cout << "Range-based for with initializer" << std::endl;
        #endif
        
        #if __cpp_if_consteval >= 202211L
            constexpr auto test_feature = []() {
                if consteval {
                    return 1;
                } else {
                    return 2;
                }
            };
            std::cout << "if consteval test: " << test_feature() << std::endl;
        #endif
        
    #else
        std::cout << "\nNote: Not using C++26 (actual standard: " << __cplusplus << ")" << std::endl;
    #endif
    
    return 0;
}