CC=gcc
CFLAGS=-I.
DEPS = SortedList.h PCTimer.h
OBJ = SortedList.o fileListFunctions.o testSortedList.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

SortedList: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)