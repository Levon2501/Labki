#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int	change(int n, ...)
{
	va_list	ptr;
	int	result = 0, x, k;

	va_start(ptr, n);

	x = va_arg(ptr, int);
	k = va_arg(ptr, int);

	for (int i = k; i >= 0; i--)
	{
		result = result + va_arg(ptr,int)*pow(x,i);
	}
	va_end(ptr);
	return result;
}

int	main()
{
	printf("%d\n", change(6, 2, 3, 3, 3, 2, 2));
}
