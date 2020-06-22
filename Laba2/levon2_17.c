#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int	find(double eps, double a, double *array, int n)
{
	for (int i = 0; i < n; i++)
		if (fabs(array[i] - a) <= eps)
			return 1;
	return 0;
}

void check1(double eps, int base, double a)
{
	double *array;
	double temp;
	int	size;
	int	n = 0;

	printf("%lf: ", a);
	size = 10;
	array = (double*)malloc(sizeof(double) * size);
	array[n++] = a;
	while(a > eps)
	{
		a *= base;
		a = modf(a, &temp);
		if (find(eps, a, array, n))
		{

			printf("no\n");
			free(array);
			return;
		}
		array[n] = a;
		n++;
	}
	printf ("yes\n");
	free(array);
}

void check(int base, int n, ...)
{
	va_list	ptr;

	va_start(ptr, n);
	for (int i = 0; i < n; i++)
		check1(0.000000001, base, va_arg(ptr, double));
	va_end(ptr);	
}

int	main()
{
	check(2, 4, 0.123, 0.234, 0.3, 0.5);
	return 0;
}
