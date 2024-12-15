##############################################################
#
## Author: Ali Umar
## Date: 2024-11-30
## Remarks: This is a Makefile used for implementing build scripts 
## for my 3d-particles project. It's provided as-is. Incremental build
## and directory traversal will be added as this project grows
#
##############################################################

# EDIT ME
PROJECT_PATH = C:\dev\repos\3d-particles
RAYLIB_PATH = -LC:\dev\software\raylib-5.5_win64_mingw-w64\lib
RAYLIB_INCLUDE = -IC:\dev\software\raylib-5.5_win64_mingw-w64\include
SRC_FOLDER=src
DIST = bin

# DON'T EDIT ME
INCLUDE = $(RAYLIB_INCLUDE) -I$(PROJECT_PATH)\include

# opengl32 and windows multi media library
WINDOWS_DEPENDENCIES = -lgdi32 -lwinmm
DEPENDENCIES = -lraylib $(WINDOWS_DEPENDENCIES)

SRC_FILES = $(SRC_FOLDER)/main.c \
						$(SRC_FOLDER)/global.c \
						$(SRC_FOLDER)/particle.c \
						$(SRC_FOLDER)/util.c \
						$(SRC_FOLDER)/logger.c 

#TODO(Ali): Add incremental build 
#TODO(Ali): Add recursive directory file search

run: build
	cd $(DIST) && particles.exe

build:
	gcc $(SRC_FILES) $(INCLUDE) $(RAYLIB_PATH) $(DEPENDENCIES) -o $(DIST)/particles.exe 

clean: 
	rm bin/particles.exe
