GCC=g++
CFLAGS=-g -v -Wall -std=c++14
TARGET=main
SOURCES:=main.cpp
#DEPS:=include/complex.h
# Math libraries
# MATH:=-lm
OBJECTS:=$(SOURCES:.cpp=.o)

%.o: %.cpp
	$(GCC) -Iinclude $(CFLAGS) -c $< -o $@

.PHONY: all
all: $(OBJECTS)
	$(GCC) -Iinclude $(CFLAGS) $(OBJECTS) -o $(TARGET) 
	@./main

.PHONY:
test: 
	c++ -Iinclude -O3 $(CFLAGS) -DNDEBUG test.cpp  -o test

.PHONY: clean
clean:
	rm $(TARGET) $(OBJECTS)
