#include <omp.h>
#include <stdio.h>

int main()
{
	#pragma omp parallel
	{

		#pragma omp master
		{
			printf("Hello world from %d \n", omp_get_thread_num());
		}

		#pragma omp single  // code will be barrieried automatically 
		{
			printf("Hello world from %d \n", omp_get_thread_num());
		}

		#pragma omp barrier
		printf("Number of threads %d \n", omp_get_num_threads());
	}
}
