CC = g++
CFLAGS = -g -Wall -Werror -std=c11
LDFLAGS = -fsanitize=undefined -fsanitize=address -g
LIBS += -lm

TARGETS = run
SOURCES = src/main.cpp src/stack.cpp src/defines.cpp
HEADERS = src/templates.hpp src/stack.hpp src/defines.hpp
OBJECTS = $(SOURCES: .c=.o)

all: run

run : $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@ $(LIBS)

include deps.make

deps.make : $(SOURCES) $(HEADERS)
	$(CC) -MM $(SOURCES) > deps.make

clean:
	-rm -f $(TARGETS) *.o deps.make