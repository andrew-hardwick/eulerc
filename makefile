build: clean main.o p001_020.o
	gcc -o euler.exe main.o p001_020.o
	rm ./*.o
main.o:
	gcc -c main.c
p001_020.o:
	gcc -c p001_020.c
clean:
	rm euler.exe
