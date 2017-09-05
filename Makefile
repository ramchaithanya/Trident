#OBJS    = trident/src/tridentmain.o
CC      = g++
LINK	= -c
DEBUG   = -g
CFLAGS  = -Wall -c $(DEBUG)
LIBFLAGS	= `wx-config --cxxflags`
LIBFLAGS	+= `pkg-config --cflags opencv`
LIBS	= `wx-config --libs`
LIBS	+= `pkg-config --libs opencv`

#This finds all your cc files and places then into SRC. It's equivalent would be
# SRC = src/main.cc src/folder1/func1.cc src/folder1/func2.cc src/folder2/func3.cc

SRC = $(shell find . -name *.cpp)

#This tells Make that somewhere below, you are going to convert all your source into 
#objects, so this is like:
# OBJ =  src/main.o src/folder1/func1.o src/folder1/func2.o src/folder2/func3.o

OBJ = $(SRC:%.cpp=%.o)

#Tells make your binary is called artifact_name_here and it should be in bin/
BIN = trident/bin/trident

# all is the target (you would run make all from the command line). 'all' is dependent
# on $(BIN)
all: $(BIN)

#$(BIN) is dependent on objects
$(BIN): $(OBJ)
	$(CC)  $(LIBS) $^ -o $(BIN)

#each object file is dependent on its source file, and whenever make needs to create
# an object file, to follow this rule:
%.o: %.cpp
	$(CC) $(CFLAGS) $(LIBFLAGS) -c $^ -o $@

clean:
	\rm -rvf $(OBJ) $(BIN)
