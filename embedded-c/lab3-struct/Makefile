CC=gcc
CCFLAGS=-Wall -std=gnu99
LDFLAGS=
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
TARGET=./bookstore

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS) 

%.o: %.c %.h
	$(CC) $(CCFLAGS) -c $<

%.o: %.c
	$(CC) $(CCFLAGS) -c $<
	
test:
	$(TARGET) < books.txt

clean:
	rm -f *.o $(TARGET)
