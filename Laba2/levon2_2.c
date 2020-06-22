#include<stdio.h>
#include<stdlib.h>

#define N 128

int main()
{
  FILE *file;

  int j = 0,i = 0;
  int a[N];
  int b[N];
  
  file = fopen("levon2_2.txt", "r");
  if(!file)
    {
      printf("aaaaa");
      exit(1);
    }
  
  while(!feof(file))
    {
      fscanf(file, "%d ", &a[i]);
      printf("%d ", a[i]);
      if(a[i] % 2 == 0)
	{
	  b[j] = a[i];
	  j++;
	}
      i++;
    }
  printf("\n");
  for(i = 0; i < j; i++)
    printf("%d ", b[i]);
  printf("\n");
  fclose(file);
  return 0;
}
