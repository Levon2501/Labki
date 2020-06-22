#include<stdio.h>
int str(char* s)
{
  char* s_ = s;

  while(*s++ != '\0');
  s--;
  
  return s - s_;
}

int main()
{
  char *string = "abcdefghij";
  printf("String : %s\nSIZE = %d\n",string,str(string) );
  return 0;
}
