#include "stdlib.h"
#include "stdio.h"
#include "omp.h"

static long numSteps = 100000;
double step;

int main(int argc, char* argv[]){
  argc--; argv++;
  int numthreads = 4;
  if(argc > 0) numthreads = atoi(argv[0]);

  int i;
  double pi, sum = 0.0;
  double partialsum[numSteps];

  step = 1.0/(double)numSteps;

  omp_set_num_threads(numthreads);
  double start = omp_get_wtime();

  #pragma omp parallel for reduction (+:sum)
  for(i = 0; i < numSteps ; i++){
    double x = (i + 0.5) * step;
    sum += 4.0/(1.0 + x * x);
  }

  pi = step * sum;

  double runtime = omp_get_wtime() - start;

  printf("pi = %f in %f seconds (%i threads)\n", pi, runtime, numthreads);
}
