VulkanViewer
======================
<!-- [![Build Status](https://travis-ci.com/hiergaut/VulkanViewer.svg?branch=main)](https://travis-ci.com/hiergaut/VulkanViewer) -->
![example workflow name](https://github.com/hiergaut/VulkanViewer/workflows/CI/badge.svg)

3D experimental viewer with Vulkan

***Supported platforms:***

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

***Supported compilers:***

 <!-- * Clang 3.3 and above -->
 <!-- * GCC 5 and above -->
 * GCC 10 and above
 <!-- * VS2017 and above -->
 * MSVC 19 and above

Building
-------------

```
git clone --recurse-submodules -j8 https://github.com/hiergaut/VulkanViewer.git
cd VulkanViewer
mkdir build && cd build
cmake ..
cmake --build .
```
