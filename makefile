all:
	gcc -fopenmp 1.c -o question1.out
	gcc -fopenmp 2.c -o question2.out

clean:
	rm -f *.out
