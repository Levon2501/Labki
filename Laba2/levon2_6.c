#include<stdio.h>
#include<stdlib.h>

void str(char *string1,char *string2)
{
  while(*string1++ != '\0');
  string1--;
  while(*string2 != '\0')
    {
      *string1++ = *string2++;
    }
  *string1 = '\0';
}


int main()
{
  char string_1[BUFSIZ] = "abc";
  char string_2[BUFSIZ] = "def";

  str(string_1,string_2);
  
  printf("New string : %s\n", string_1);
  return 0;
}
