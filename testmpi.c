#include <stdio.h> 
#include "mpi.h" 
int main(int argc, char **argv) 
{ 
 int ntasks, rank;
 MPI_Init(&argc, &argv); 
 MPI_Comm_size(MPI_COMM_WORLD, &ntasks); 
 MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
 printf ("Ntasks=%d, My rank=%d\n", ntasks, rank); 
 MPI_Finalize(); 
}
