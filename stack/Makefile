CC = gcc
CFLAGS = -E -g -Wall -Werror -std=c11
LDFLAGS = -g
LIBS += -lm

TARGETS = run
SOURCES = src/*.c
HEADERS = src/*.h
OBJECTS = $(SOURCES: .c=.o)

all: $(TARGETS)

$(TARGETS) : $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@ $(LIBS)

include deps.make

deps.make : $(SOURCES) $(HEADERS)
	$(CC) -MM $(SOURCES) > deps.make

clean:
	-rm -f $(TARGETS) deps.make
