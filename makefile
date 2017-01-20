build: clean main.o p001_020.o common_math.o
	gcc -o euler.exe main.o p001_020.o common_math.o -lm
	rm -f ./*.o
main.o:
	gcc -c main.c
p001_020.o:
	gcc -c p001_020.c
common_math.o:
	gcc -c common_math.c
clean:
	rm -f euler.exe
	rm -f ./*.o
