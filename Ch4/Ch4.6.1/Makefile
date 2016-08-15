GCC=g++
CFLAGS=-g -Wall -std=c++14
TARGET=main
SOURCES:=main.cpp
DEPS:=include/complex.h
# Math libraries
# MATH:=-lm
OBJECTS:=$(SOURCES:.cpp=.o)

%.o: %.cpp
	$(GCC) $(CFLAGS) -c $< -o $@

.PHONY: all
all: $(OBJECTS)
	$(GCC) $(CFLAGS) $(OBJECTS) -o $(TARGET) 
	@./main

.PHONY:
test: 
	c++ -O3 $(CFLAGS) -DNDEBUG test.cpp  -o test

.PHONY: clean
clean:
	rm $(TARGET) $(OBJECTS)
