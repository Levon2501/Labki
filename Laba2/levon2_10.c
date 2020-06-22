#include<stdio.h>
#include<ctype.h>

int str(char* s)
{
  int n = 0;
  while(*s != '\0')
    {
      if(isalpha(*s))
	n++;
      s++;
    }
  return n;
}

int main(int argc, char **argv) 
{
  
  FILE *file_1;
  FILE *file_2;

  char c;
  int n;
  char string[BUFSIZ];
  char* pstr = string;

  
  if ((file_1 = fopen(argv[1], "r")) == NULL)
    {
      perror(argv[1]);
    }
  if ((file_2 = fopen("levon2__10_2.txt", "w")) == NULL)
    {
      perror("levon2__10_2.txt");
    }
  while(!feof(file_1))
    {
      c = fgetc(file_1);
      if((c != '\n')  &&  (c != EOF))
	{
	  *pstr = c;
	  pstr++;
	  *pstr = '\0';
	}
      else
	{
	  fprintf(file_2,"%d\n",str(string));
	  pstr = string;
	  *pstr = '\0';
	}
    }
  fclose(file_1);
  fclode(file_2);
  return 0;
}
