all:
	gcc -fopenmp 1.c -o question1.out
	gcc -fopenmp 2.c -o question2.out
	gcc -fopenmp 6.c -o question6.out
	gcc -fopenmp matmul.c -o matmul.out

clean:
	rm -f *.out
