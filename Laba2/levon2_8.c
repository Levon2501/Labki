#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float eps()
{
  double e = 1.0;
  while(1.0 + e/2.0 > 1.0)
    {
      e /= 2;
    }
  return e;
}

float p(float n, int k)
{
  float e = eps();
  if(fabs(n) < e  &&  n == 0)
    {
      printf("Error\n");
      exit(-1);
    }
  if(k == 0) return 1.0;
  if(k < 0)
    {
      return 1.0/(n*(p(n, abs(k)-1)));
    }
  return n*p(n,k-1);
  
}

int main()
{
  int k;
  float n;
  printf("Enter numbers: ");
  scanf("%f %d",&n,&k);
  printf("%f \n", p(n,k));
}
