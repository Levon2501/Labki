#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
#include<math.h>

double gmean(int num,...)
{
  va_list args;
  float res;
  int temp = 1;
  int n;
  int i = 0;
  va_start(args, num);
  if(num == 0)
    {
      printf("Error\n");
      exit(-1);
    }
  for(i = 0; i<num; i++)
    {
      n = va_arg(args, double);
      temp *= n;
    }
  res = pow(temp, 1.0/num);
  va_end(args);
  
  return res;
}
int main()
{
  double result = gmean(5,2.0,3.0,4.0,5.0,6.0);
  printf("Result = %lf\n", result);
  return 0;
}
