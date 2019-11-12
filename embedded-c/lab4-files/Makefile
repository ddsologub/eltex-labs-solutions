CC=gcc
CCFLAGS=-g -Wall -std=gnu99
LDFLAGS=
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
TARGET=./changechar

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS) 

%.o: %.c %.h
	$(CC) $(CCFLAGS) -c $<

%.o: %.c
	$(CC) $(CCFLAGS) -c $<
	
test:
	$(TARGET) imdb250.txt ' '

clean:
	rm -f *.o $(TARGET)
