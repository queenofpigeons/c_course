CC = gcc
CFLAGS = -g -Wall -Werror -std=gnu11
LDFLAGS = -fsanitize=undefined -fsanitize=address -g
LIBS += -lm

TARGETS = run
SOURCES = src/main.c src/func.c src/test.c
HEADERS = src/header.h
OBJECTS = $(SOURCES: .c=.o)

all: run

run : $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@ $(LIBS)

include deps.make

deps.make : $(SOURCES) $(HEADERS)
	$(CC) -MM $(SOURCES) > deps.make

clean:
	-rm -f $(TARGETS) *.o deps.make