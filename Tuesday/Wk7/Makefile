
CC = gcc
CFLAGS = -Wall -Werror -std=c11 -g

EXERCISE_FILE = breadthFirstSearch.c
COMMON = Graph.c Queue.c

SRC_FILES = $(TEST_DRIVER) $(EXERCISE_FILE) $(COMMON)

all: breadthFirstSearch

testBreadthFirstSearch: $(SRC_FILES)
	$(CC) $(CFLAGS) -o breadthFirstSearch $(SRC_FILES)

clean:
	rm -f breadthFirstSearch

