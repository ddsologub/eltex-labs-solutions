CC=gcc
CCFLAGS=-g -Wall -std=gnu99
LDFLAGS=

all: changechar changestring

changechar: changechar.o
	$(CC) -o $@ $^ $(LDFLAGS) 

changestring: changestring.o
	$(CC) -o $@ $^ $(LDFLAGS) 

%.o: %.c %.h
	$(CC) $(CCFLAGS) -c $<

%.o: %.c
	$(CC) $(CCFLAGS) -c $<
	
test:
	changechar imdb250.txt ' '
	changestring imdb250.txt The

clean:
	rm -f *.o changechar changestring
