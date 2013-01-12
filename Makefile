CC          =	gcc
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-Wall -ansi -pedantic -g

#Directories where the compiler can find things
INCLUDES    = -Iinclude
#all .c files
TREE        = src/balancedTree.c
QUEUE       = src/priorityQueue.c
QTEST       = src/queueTest.c
TREET       = src/testTree.c
INPUT		= src/inputImplementation.c
TODO        = src/todoImplementation.c
MAIN        = src/todoListManager.c

all: treeTest queueTest todoList

todoList:
	gcc $(CFLAGS) $(TODO) $(INPUT) $(TREE) $(QUEUE) $(MAIN) -o bin/a3 -Iinclude

queueTest:
	gcc $(CFLAGS) $(TODO) $(INPUT) $(TREE) $(QUEUE) $(QTEST) -o bin/qTest -Iinclude

treeTest:
	gcc $(CFLAGS) $(TODO) $(TREE) $(INPUT) $(TREET) -o bin/tTest -Iinclude


clean:
	@ rm bin/*

run:
	./bin/a3 ./todo.txt

tTest:
	./bin/tTest

qTest:
	./bin/qTest