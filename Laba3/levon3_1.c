#include <stdio.h>

int to_base(int num, int r) 
{
	int pw = 1 << r; //сдвиг влево на r байт 
	
	char result[80];
	int i = 0;
	int remainder;
	while (num != 0) 
	{
		remainder = num & (~-pw); //num и не pw
		if (remainder > 9) 
		{
			for (int j = 0; j < 9; j++) 
			remainder = ~-remainder;	
	
		result[i] = 64 | remainder;
		}
		
		else 
			result[i] = 48 | remainder;
	
		i++;
		num = num >> r; //сдвиг вправо 
	} 
	for (int j = i-1; j >= 0; j--) 
	{
		printf("%c", result[j]);
		
	}
	printf("\n");
	return *result;
}

int main() 
{
	int r;
	int num;
	printf("enter number: ");
	scanf("%d", &num);
	printf("enter degree: ");
	scanf("%d", &r);
	to_base(num, r);
	return 0;
}
