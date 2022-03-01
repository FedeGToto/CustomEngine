# CustomEngine
A custom game engine by Federico Giorgi

## Prerequisites
- CMake
- SDL 2

## Installation
- [Download SDL 2 here](https://www.libsdl.org/release/SDL2-devel-2.0.20-VC.zip)
- Create a new file in the root folder of SDL, called `sdl2-config.cmake`
- Copy and paste the following script in the new file 
```
set(SDL2_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/include")

# Support both 32 and 64 bit builds
if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
	set(SDL2_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2.lib;${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2main.lib")
else ()
	set(SDL2_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2.lib;${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2main.lib")
endif ()

string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)
```
- Open CMake (we're using CMake GUI on this guide)
- Set source and build folder
- Click Configure
- Under `SDL2_LIB` put the root folder of SDL 2
- Click Configure until you have no more red errors
- Click Generate
- Start working with this engine
