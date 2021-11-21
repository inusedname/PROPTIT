# This is makefile for SFML C++

path = D:/bin/sfml
INCLUDE = "$(path)/include"
LIBRARY = "$(path)/lib"
SOURCE = src/*.cpp
OBJ = *.o
TARGET = build/main
SFML_INCLUDE = -lsfml-graphics -lsfml-window -lsfml-system
#=======================================================================================#
all: $(TARGET) clean

$(TARGET): compile
	g++ $(OBJ) -o $@ -L $(LIBRARY) $(SFML_INCLUDE)
compile: 
	g++ -c $(SOURCE) -I $(INCLUDE)
clean: 
	del *.o 