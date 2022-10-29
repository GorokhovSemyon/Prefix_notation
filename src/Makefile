CC=gcc
CFLAGS=-c
LDFLAGS=-o
FLAGS=-Wall -Werror -Wextra
BUILD=../build/graph

all: graph

graph: list.o stack.o graph.o io_standart_polsk.o polsk_calculate.o parse_string.o
	$(CC) $(LDFLAGS) $(BUILD) stack.o list.o graph.o io_standart_polsk.o polsk_calculate.o parse_string.o -lm

stack.o: stack.c
	$(CC) $(CFLAGS) $(FLAGS) stack.c

list.o: list.c
	$(CC) $(CFLAGS) $(FLAGS) list.c

graph.o: graph.c
	$(CC) $(CFLAGS) $(FLAGS) graph.c

parse_string.o: parse_string.c
	$(CC) $(CFLAGS) $(FLAGS) parse_string.c

io_standart_polsk.o: io_standart_polsk.c
	$(CC) $(CFLAGS) $(FLAGS) io_standart_polsk.c

polsk_calculate.o: polsk_calculate.c
	$(CC) $(CFLAGS) $(FLAGS) polsk_calculate.c

clean:
	rm -rf *.o

rebuild: clean all
