#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int main()
{
  int **a;
  int **b;
  int **c;
  int i, j, k, N1, M1, N2, M2;
  printf("Enter number first matrix : ");
  scanf("%d %d",&N1,&M1);
  printf("Enter number second matrix : ");
  scanf("%d %d",&N2,&M2);
  if(N1 <= 0 || M1 <= 0 || N2 <= 0 || M2 <= 0)
    {
      printf("Error\n");
      exit(-1);
    }
  if(M2 != N1)
    {	
      printf("Error\n");
      exit(-1);
    }
  
  printf("Matrix А : \n");
  
  a = (int**)malloc(N1 * sizeof(int*));
  for (i = 0; i < N1; i++)  
    {
      a[i] = (int*)malloc(M1 * sizeof(int));
    for (j = 0; j < M1; j++)  
    {
      a[i][j] = (rand()%101) - 50;
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  printf("Matrix В : \n");
  
  b = (int**)malloc(N2 * sizeof(int*));
  for (i = 0; i < N2; i++)  
  {
    b[i] = (int*)malloc(M2 * sizeof(int));
    for (j = 0; j < M2; j++) 
    {
      b[i][j] = -rand()%100;
      printf("%d ", b[i][j]);
    }
    printf("\n");
  }
  printf("Matrix С : \n");
  c = (int**)malloc(N1 * sizeof(int*));
  for (i = 0; i < N1; i++ )
    {
      c[i] = (int*)malloc(M2 * sizeof(int));
      for(j = 0; j < M2; j++)
	{
	  c[i][j] = 0;
	  for(k = 0; k< N2; k++)
	    {
	      c[i][j]+=a[i][k]*b[k][j];
	    }
	}
    }
  for(i=0; i < N1; i++)
    {
      for(j = 0; j < M2; j++)
	{
	  printf("%d ", c[i][j]);
	}
      printf("\n");
    }
  
  for (i = 0; i < N1; i++) 
    free(a[i]);  
  free(a);
  for (i = 0; i < M1; i++)
    free(b[i]);
  free(b);
  for(i = 0; i < N1; i++)
    free(c[i]);
  free(c);
  return 0;
}
