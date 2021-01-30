VulkanViewer
======================
[![Build Status](https://travis-ci.com/hiergaut/VulkanViewer.svg?branch=main)](https://travis-ci.com/hiergaut/VulkanViewer)

3D experimental viewer with Vulkan

<!-- Supported platforms: -->
Tested platforms:

 <!-- * Android (14+, ARM, x86, MIPS) -->
 <!-- * asm.js/Emscripten (1.25.0) -->
 * FreeBSD
 <!-- * iOS (iPhone, iPad, AppleTV) -->
 * Linux
 <!-- * MIPS Creator CI20 -->
 <!-- * OSX (10.12+) -->
 <!-- * PlayStation 4 -->
 * RaspberryPi
 <!-- * Windows (XP, Vista, 7, 8, 10) -->
 * Windows (10)
 <!-- * UWP (Universal Windows, Xbox One) -->

Tested compilers:

 * Clang 3.3 and above
 * GCC 5 and above
 * VS2017 and above

Dependencies
-------------

Linux :
 * Vulkan


Building
-------------

```
git clone https://github.com/hiergaut/VulkanViewer.git
cd VulkanViewer
git submodule update --init --recursive
mkdir build && cd build
cmake ..
cmake --build .
```
