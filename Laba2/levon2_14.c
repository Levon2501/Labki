#include <stdio.h>
#include <math.h>

double epsilon()
{
  double e = 1.0;
  while(1.0 + e/2.0 > 1.0)
    {
      e/=2.0;
    }
  return e;
}

double f(double x)
{
  return x - 2 - sin(1/x);
}

double dihotom(double a, double b, double e, double (*func)(double x))
{
  double c;
  
  while(fabs(a - b) > e)
    {
      c = (a + b)/2;
      if(func(b) * func(c) < e)
	{
	  a = c;
	}
      else
	{
	  b = c;
	}
    }
  return c;
}

int main() 
{
  
  double a, b, x;
  double e = epsilon();
  printf("enter 1 piece: ");
  scanf("%lf", &a);
  printf("enter 2 piece: ");
  scanf("%lf", &b);
  printf("\naccuracy = %f\npiece = [%f,%f]\nX = %f\n",e, a,b, dihotom(a, b, e, f));
  printf("\n");
  return 0;
}
