#please use 'make clean' to clean the directory of intermediate build files and the executable
#simply typing 'make' will compile all source code files to object files .o, and then link all
#object files into an executable
#we are using a lot of makefile macros

#changing platform dependant stuff, do not change this
# Linux (default)
LDFLAGS= -lGL -lGLU -lglut
CFLAGS=-g -Wall -std=c++11
CCX=g++
EXEEXT=
RM=rm

# Windows (cygwin)
ifeq "$(OS)" "Windows_NT"
	EXEEXT=.exe #on windows applications must have .exe extension
	RM=rm #rm command for windows powershell
    LDFLAGS = -lfreeglut -lglu32 -lopengl32
else
# OS X
	OS := $(shell uname)
	ifeq ($(OS), Darwin)
	        LDFLAGS = -framework Carbon -framework OpenGL -framework GLUT
	endif
endif

PROGRAM_NAME=main

run: $(PROGRAM_NAME)
	./$(PROGRAM_NAME)$(EXEEXT)

$(PROGRAM_NAME): main.o HUD.o camera.o board.o shapes/shape.o shapes/cube.o utils/mazeGen.o utils/fileManager.o utils/colour.o utils/material.o utils/mathLib3D.o shapes/ball.o utils/PPM.o
	$(CCX) -o $@ $^ $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) *.o ./utils/*.o ./shapes/*.o $(PROGRAM_NAME)$(EXEEXT)
