#include<stdio.h>
#include<ctype.h>

int f(char* s)
{
  int i = 0;
  while(*s != '\0')
    {
      if(i % 2 == 0)
	{
	  *s = toupper(*s);
	}
      i++;
      s++;
    }
}

int main()
{
  char string[BUFSIZ] = "abcd";
  f(string);
  printf("SIZE = %s\n", string);
  return 0;
}
