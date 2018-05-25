# A simple makefile for Sort project

NAME=sort
CC=g++
CXXFLAGS=-std=c++11 -g
OBJS=src/misc.o src/sort.o src/time.o

all: $(NAME)

$(NAME): src/misc.o src/sort.o src/time.o
	$(CC) $(CXXFLAGS) -o $(NAME) src/main.cpp $(OBJS)

src/misc.o: src/misc.h

src/sort.o: src/sort.h

src/time.o: src/time.h

clean: 
	rm -f testfiles/* src/*.o $(NAME)


