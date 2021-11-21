# This is makefile for SFML C++

path = D:\bin\sfml
INCLUDE = "$(path)\include"
LIBRARY = "$(path)\lib"
CXXFLAGS =
SFMLFLAGS =
SOURCE = main.cpp
OBJ = main.o
SFML_INCLUDE = -lsfml-graphics -lsfml-window -lsfml-system
#=======================================================================================#

all: compile link
compile:
	g++ -c $(SOURCE) -I $(INCLUDE)
link:
	g++ $(CXXFLAGS) $(OBJ) -o main -L $(LIBRARY) $(SFMLFLAGS) $(SFML_INCLUDE)