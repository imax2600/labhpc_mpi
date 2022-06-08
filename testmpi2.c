#include <stdio.h>
#include "mpi.h"
#include <math.h>
#include <stdlib.h>
float sumgen(int rank);
int main(int argc, char **argv)
{
 int ntasks, rank; 
 MPI_Init(&argc, &argv);
 MPI_Comm_size(MPI_COMM_WORLD, &ntasks);
 MPI_Comm_rank(MPI_COMM_WORLD, &rank);
 float s = 0;
 s = sumgen(rank);
 if (rank != 0)
	MPI_Send(&s, 1, MPI_FLOAT, 0, 0, MPI_COMM_WORLD);
 else
 {
	MPI_Status st;
	float sum = 0, sum2 = 0;
	int i = 0;
	while (i < ntasks)
	{
	if (i == 0)
		printf("Rank[%d] my sum is %f\n", rank, s);
	else
        {
	MPI_Recv(&sum, 1, MPI_FLOAT, MPI_ANY_SOURCE, 0,MPI_COMM_WORLD, &st);
	printf("Rank[%d] got sum from [%d] = %f\n", rank, st.MPI_SOURCE, sum);
        }
	sum2 += sum;
	i++;
	}
	printf("Total sum is %f , expected sum is %f\n", sum2, 1000000 * 0.5 * ntasks);
 }
 
 MPI_Finalize();
}

float sumgen(int rank)
{
    int n = 1000000, i = 0; 
    float sum = 0.0;
    srandom(time(NULL)+ rank);
    while (i < n) {
    	double r = (double)random()/RAND_MAX;
    	sum += r;
    	i++;
    }
    return sum;
}

