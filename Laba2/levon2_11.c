#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define N 10
int swap(int* x,int* y)
{
  int t = *y;
  *y = *x;
  *x = t;
}
  
int main()
{
  int A[N];
  int max = -11,min = 11,max_index,min_index,i;
  srand(time(NULL));
  for(i = 0;i < N;i++)
    {
      A[i] = (rand()%21)-10;
      printf("%d ",A[i]);
      if(A[i] > max)
	{
	  max = A[i];
	  max_index = i;
	}
      if(A[i] < min)
	{
	  min = A[i];
	  min_index = i;
	}
    }
  printf("\n max =  %d  min =  %d\n",max,min);
  swap(&A[max_index],&A[min_index]);

  for(i = 0;i < N;i++)
    {
      printf("%d ",A[i]);
    }
  printf("\n");
  return 0;
}
