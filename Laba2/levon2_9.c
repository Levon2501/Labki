#include<stdio.h>
#include<stdlib.h>


void revers(char *s1)
{
  char* s2 = s1;
  char t;
  while(*s2++ != '\0');
  s2 -= 2;
  while(s2 > s1)
    {
      t = *s2;
      *s2 = *s1;
      *s1 = t;
      s2--;
      s1++;
    }
}

int main()
{
  char string[BUFSIZ] = "abcdeghij";
  
  revers(string);
  
  printf("New string : %s\n",string);
  return 0;
}
