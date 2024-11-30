# 3d particles

## Description
This is a small little project to implement a 3d particles engine using C language. 

## Project setup

#### Prerequisites:
        GNU Make
        GNU C Compiler 
        Raylib library for graphics and general multimedia

#### My environment:
    Windows 11
    MinGW 64 GCC 12.3.0
    GNU Make 4.4.1 build for MinGW 64
    Statically linked raylib.a

#### Linker dependencies
    -lwinmm  # windows multimedia
    -lgdi32  # windows graphics device interface
    -lraylib # raylib

#### How do build and run this project?

1. Make sure you have a C Compiler 
2. Acquire raylib library, you may download prebuild binaries or build from source
        https://github.com/raysan5/raylib
3. Edit the Makefile and put the path to your library file (raylib.a) in $RAYLIB_PATH variable
4. Edit the Makefile put the path to your raylib include file (raylib.h) in $RAYLIB_INCLUDE varibble
5. (Optional) Add the paths to .clangd for auto-complete and LSP info
6. run

        make

7. You should get a window popup! Congratulations. You were able to run the software.

