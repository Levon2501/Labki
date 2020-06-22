#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int	dotriangle(int **matrix,int n)
{
	int mnoj;

	mnoj = 1;
	for (int diag = 0; diag < n - 1; diag++)
	{
		for (int i = diag + 1; i < n; i++)
		{
			for (int j = diag + 1; j < n; j++)
				matrix[i][j] = matrix[diag][diag] * matrix[i][j] - matrix[i][diag] * matrix[diag][j];
			mnoj *= matrix[diag][diag];
			matrix[i][diag] = 0;
		}		  		
	}
	return (mnoj);
}

int	det(int **matrix, int n)
{
	int det;
	int temp;
	int res;
	temp = dotriangle(matrix,n);
	det = 1;
	for (int i = 0; i < n; i++)	
		det *= matrix[i][i];
	res = (det / temp);
	printf("det = %d\n", res);
	return res;
}

int	main()
{
	int **matrix;
	int n,i,j;

	printf("Enter size: \n");
	scanf("%d",&n);


	srand(time(NULL));

	matrix = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)  
	{
		matrix[i] = (int*)malloc(n * sizeof(int));
	    for (j = 0; j < n; j++)  
	    {
	      matrix[i][j] = rand()%31 - 15;
	      printf("%d ", matrix[i][j]);
	    }
	    printf("\n");
	}
	printf("\n");


	det(matrix,n);

	for(i = 0;i < n;i++)
		free(matrix[i]);
	free(matrix);
	return 0;
}
