#include <mpi.h>
#include <rsf.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int myid;
	char message[30];
	MPI_Status mpi_status;

	sf_init (argc, argv);
	MPI_Init(&argc,&argv); 
	MPI_Comm_rank(MPI_COMM_WORLD,&myid); 
	if (myid==0)
	{
		strcpy(message,"Hello processor 1!");
		MPI_Send(message, strlen(message), MPI_CHAR, 1, 99, MPI_COMM_WORLD);
	}
	else if(myid == 1)
	{
		MPI_Recv(message, 30, MPI_CHAR, 0, 99, MPI_COMM_WORLD, &mpi_status);
		fprintf(stderr, "received: %s\n", message);
	}

	MPI_Finalize(); 
	exit(0);
}
