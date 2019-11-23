all: obj/*.o
	gcc -o bin/manager obj/manager.o
	gcc -o bin/worker obj/worker.o
obj/*.o : src/*.c bin obj
	gcc -std=c99 -o obj/manager -c src/manager.c
	gcc -std=c99 -o obj/worker -c src/worker.c
bin obj:
	mkdir -p bin
	mkdir -p obj
clean:
	rm -rf bin obj
