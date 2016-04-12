
//  REGULAR ROW BASED MATRIX MULTIPLICATION
//  BY: ARMIN MEHRABIAN

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


#define MIN(A,B) (((A)<(B))?(A):(B))

int main (int argc, char *argv[])
{

int thread_number, nthreads, i, j, k, ii, jj, kk, sum;

// DECLERATIONS BELOW PASS VARIABLES FROM SHELL TO MAIN AT THE RUNTIME

int number_of_rows_A      = atoi(argv[1]);
int number_of_columns_A   = atoi(argv[2]);
int number_of_columns_B   = atoi(argv[3]);
int block_size             = atoi(argv[4]);
// IN A SINGLE RUN IMPLEMENTATION THE COMMENTED OUT LINES BELOW ASK THE USER TO INSERT THE MATRIX DIMENSIONS AND THE TILE SIZE.

// printf("Print number of rows in matrix A: ");
// scanf("%d",&number_of_rows_A);

// printf("Print number of columns in matrix B: ");
// scanf("%d",&number_of_columns_A);

// printf("Print number of columns in matrix C: ");
// scanf("%d",&number_of_columns_B);

// printf("Print size of the tile: ");
// scanf("%d",&block_size);

double  A[number_of_rows_A][number_of_columns_A],           // INPUT MATRIX  A DECLARED
        B[number_of_columns_A][number_of_columns_B],        // INPUT MATRIX  B DECLARED
        C[number_of_rows_A][number_of_columns_B];           // OUTPUT MATRIX C DECLARED


// EXPLICITLY DEFINING A PARALLE SPACE TO EMBRACE ALL VARIABLES
#pragma omp parallel shared(A,B,C,nthreads,block_size) private(thread_number,i,j,k)
  {
  thread_number = omp_get_thread_num();
  if (thread_number == 0)
    {
    nthreads = omp_get_num_threads();
    printf("Initializing matrices on %d threads.\n",nthreads);
    }
  // INITIALIZE MATRICES 
  #pragma omp for schedule (static, block_size)
  for (i=0; i<number_of_rows_A; i++)
    for (j=0; j<number_of_columns_A; j++)
      A[i][j]= i+j;
  #pragma omp for schedule (static, block_size)
  for (i=0; i<number_of_columns_A; i++)
    for (j=0; j<number_of_columns_B; j++)
      B[i][j]= i-j;
  #pragma omp for schedule (static, block_size)
  for (i=0; i<number_of_rows_A; i++)
    for (j=0; j<number_of_columns_B; j++)
      C[i][j]= 0;

  //STARTING THE MATRIX MULTIPLY WITH PRAGMA FOR SCHEDULE BASED ON TILE_SIZE
  printf("Thread %d has started the multiply process.\n",thread_number);
  
        #pragma omp for schedule (static, block_size) 
        for (i=0; i<number_of_rows_A; i++){
          for(j=0; j<number_of_columns_B; j++)
            for (k=0; k<number_of_columns_A; k++)
        C[i][j] += A[i][k] * B[k][j];
    }
  } 
printf("CALCULATION COMPLETED!!\n");

// PRINTING OUT THE RESULTS
printf("################################## BLOCK SIZE: %d ################################\n",block_size);

printf("................................ INPUT MATRIX A: ................................\n");
for (i=0; i<number_of_rows_A; i++)
  {
  for (j=0; j<number_of_columns_B; j++)
    printf("%6.2f   ", A[i][j]);
  printf("\n");
  }
printf(".................................................................................\n");
printf("................................ INPUT MATRIX B: ................................\n");
for (i=0; i<number_of_rows_A; i++)
  {
  for (j=0; j<number_of_columns_B; j++)
    printf("%6.2f   ", B[i][j]);
  printf("\n");
  }
printf(".................................................................................\n");

printf("................................ RESULT MATRIX: ................................\n");
for (i=0; i<number_of_rows_A; i++)
  {
  for (j=0; j<number_of_columns_B; j++)
    printf("%6.2f   ", C[i][j]);
  printf("\n");
  }
printf(".................................................................................\n");
printf ("\n");
printf ("\n");
printf ("\n");

}


