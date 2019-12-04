CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++1y -ggdb
JUST_COMPILE := -c

BIN		:= bin
SRC		:= src
INCLUDE	:= include 
LIB		:= lib

LIBRARIES	:= -pthread
EXECUTABLE	:= RoundRobin.out 


all: $(BIN)/$(EXECUTABLE)


run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)


clean:
	-rm $(BIN)/*
