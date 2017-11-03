all: dirstuff.c
	gcc -o dir dir.c
run: dirstuff
	./dir