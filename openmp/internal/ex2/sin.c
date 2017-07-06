#include <omp.h>
#include <stdio.h>
#include <math.h>

int main ()
{
	long i;
	long n=100000;

	double X[n],Y[n]; 

	for (i=0;i<n;i++)
		X[i]=(double)i;

	double wstart = omp_get_wtime();

	#pragma omp parallel for
	for (i=0;i<n;i++)
		Y[i]= sin(X[i])+cos(X[i]);

	printf("Time %f\n",omp_get_wtime()-wstart);
}
