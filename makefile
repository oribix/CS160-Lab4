all:
	gcc -fopenmp 1.c -o question1.out

run: all
	./question1.out

clean:
	rm -f *.out
