#include <stdio.h> 
#include "mpi.h" 
int main(int argc, char **argv) 
{ 
 int ntasks, rank;
 MPI_Init(&argc, &argv); 
 MPI_Comm_size(MPI_COMM_WORLD, &ntasks); 
 MPI_Comm_rank(MPI_COMM_WORLD, &rank);

 if (rank == 0)
 {
 	printf ("Ntasks=%d, My rank=%d\n", ntasks, rank);
 } 
 if (rank != 0)
 {
	MPI_Recv(&ntasks, 1, MPI_INT, rank-1, 0,
             MPI_COMM_WORLD, MPI_STATUS_IGNORE);
 	printf ("Ntasks=%d, My rank=%d\n", ntasks, rank);
 }
 if (rank + 1 < ntasks )
	MPI_Send(&ntasks, 1, MPI_INT, rank+1, 0, MPI_COMM_WORLD);
 MPI_Finalize(); 
}
