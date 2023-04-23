CC=gcc
CFLAGS=-lm

euler: euler.o toolbox.o
	$(CC) -o euler euler.o toolbox.o $(CFLAGS)

euler.o: euler.c toolbox.h
	$(CC) -c euler.c $(CFLAGS)

toolbox.o: toolbox.c toolbox.h
	$(CC) -c toolbox.c $(CFLAGS) 

clean:
	rm -f euler *.o
