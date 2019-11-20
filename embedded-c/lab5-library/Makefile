all: static-linked dynamic-linked

static-linked:
	gcc -c src/main.c -o bin/main.o
	gcc -c src/mean.c -o bin/static/mean.o
	ar rc bin/static/libmean.a bin/static/mean.o
	ranlib bin/static/libmean.a
	gcc bin/main.o -Lbin/static -lmean -o bin/static-linked

dynamic-linked:
	gcc -c src/main_w_dl.c -o bin/main.o
	gcc -c -fPIC src/mean.c -o bin/shared/mean.o
	gcc -shared bin/shared/mean.o -o bin/shared/libmymean.so
	gcc bin/main.o -Lbin/shared -ldl -lmymean -o bin/shared-used
	LD_LIBRARY_PATH=bin/shared
	export LD_LIBRARY_PATH
