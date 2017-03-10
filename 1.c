#include "stdlib.h"
#include "stdio.h"
#include "omp.h"

static long numSteps = 100000;
double step;

int main(){
  int i;
  double x, pi, sum = 0.0;

  step = 1.0/(double)numSteps;

  double start = omp_get_wtime();

  for(i = 0; i < numSteps ; i++){
    x = (i + 0.5) * step;
    sum += 4.0/(1.0 + x * x);
  }
  pi = step * sum;

  double end = omp_get_wtime();

  printf("time elapsed: %f seconds\n", end-start);

  printf("pi = %1.16f\n", pi);
}
