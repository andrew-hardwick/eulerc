build: clean main.o p001_020.o common_utls.o
	gcc -o euler.exe main.o p001_020.o common_utls.o -lm
	rm -f ./*.o
main.o:
	gcc -c main.c
p001_020.o:
	gcc -c p001_020.c
common_utls.o:
	gcc -c common_utls.c
clean:
	rm -f euler.exe
	rm -f ./*.o
