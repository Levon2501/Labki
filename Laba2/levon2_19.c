#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define N 10

int main()
{
  int A[N];
  int B[N];
  int i,j,l = 0;
  bool flag = false;
  srand(time(NULL));
  for (i = 0; i < N; i++)
    {
      A[i] = rand()%10;
      printf("%d ", A[i]);
    }
  B[0] = A[0];
  l++;
  for(i = 1; i<N; i++)
    {
      flag = false;
      for(j = 0; j<N; j++)
	{
	  if(A[i] == B[j])
	    {
	      flag = true;
	    }
	}
      if(flag == false)
	{
	  B[l] = A[i];
	  l++;
	}
    }
  printf("\n");
  
  for(i = 0;i < l;i++)
    printf("%d ",B[i]);
  printf("\n");
  return 0;
}
