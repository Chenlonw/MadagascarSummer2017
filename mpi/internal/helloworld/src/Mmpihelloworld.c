#include <mpi.h>
#include <rsf.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int myid, numprocs;
	int namelen;
	char processor_name[MPI_MAX_PROCESSOR_NAME];
	sf_init (argc, argv);
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&myid);
	MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
	MPI_Get_processor_name(processor_name,&namelen);
	fprintf(stderr,"Hello World! Process %d of %d on %s\n", myid, numprocs, processor_name);
	MPI_Finalize();
	exit(0);
}

