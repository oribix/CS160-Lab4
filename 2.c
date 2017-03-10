#include "stdlib.h"
#include "stdio.h"
#include "omp.h"

static long numSteps = 100000;
double step;

int main(){
  int i;
  double pi, sum = 0.0;
  double partialsum[numSteps];

  step = 1.0/(double)numSteps;

  omp_set_num_threads(4);
  double start = omp_get_wtime();

  #pragma omp parallel
  {
    #pragma omp for private(i)
    for(i = 0; i < numSteps ; i++){
      double x = (i + 0.5) * step;
      partialsum[i] = 4.0/(1.0 + x * x);
    }
  }

  for(i = 0; i < numSteps; i++)
    sum += partialsum[i];

  pi = step * sum;

  double end = omp_get_wtime();

  printf("time elapsed: %f seconds\n", end-start);

  printf("pi = %1.16f\n", pi);
}
