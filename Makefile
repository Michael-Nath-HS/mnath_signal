signal.out: main.c
	gcc -o signal.out main.c
run: signal.out
	./signal.out
