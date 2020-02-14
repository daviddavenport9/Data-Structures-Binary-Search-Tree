CC = g++
DEBUG = -g
CFLAGS = -Wall -std=c++14 $(DEBUG) -O0 -pedantic-errors
LFLAGS = -Wall $(DEBUG)

main: ItemType.h BinaryTree.h main.cpp ItemType.cpp BinaryTree.cpp
	$(CC) $(CFLAGS) -o main main.cpp ItemType.cpp BinaryTree.cpp
clean:
	rm -rf main
	rm -rf *.o
