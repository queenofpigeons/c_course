CC = gcc
TEST_CFLAGS = -Og -g -Wall -std=c11
RELEASE_CFLAGS = -O3 -Wall -Werror -std=c11
LIBS += -lm

TEST_TARGET = test
RELEASE_TARGET = stack
SOURCES = src/*.c
HEADERS = inc/*.h

TARGETDIR = bin
OBJECTS = $(SOURCES: .c=.o)

all: build build_test

$(TARGETDIR)/$(RELEASE_TARGET) : $(OBJECTS)
	-mkdir -p $(TARGETDIR)
	$(CC) $(RELEASE_CFLAGS) $^ $(RELEASE_TARGET).c -o $@ $(LIBSS)

$(TARGETDIR)/$(TEST_TARGET) : $(OBJECTS)
	-mkdir -p $(TARGETDIR)
	$(CC) $(TEST_CFLAGS) $^ $(TEST_TARGET).c -o $@ $(LIBS)

include deps.make

deps.make : $(SOURCES) $(HEADERS)
	$(CC) -MM $(SOURCES) > deps.make

build: $(TARGETDIR)/$(RELEASE_TARGET)

build_test: $(TARGETDIR)/$(TEST_TARGET)

test: $(TARGETDIR)/$(TEST_TARGET)
	./$^

stack: $(TARGETDIR)/$(RELEASE_TARGET)
	./$^

distclean:
	-rm -f deps.make

clean:
	-rm -rf $(TARGETDIR) deps.make
