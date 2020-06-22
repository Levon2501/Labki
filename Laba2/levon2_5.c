#include<stdio.h>
#include<ctype.h>

char* str(char* s, char* pstr)
{
  char* s_ = s;
  char* s__ = pstr;
  while(*s != '\0')
    {
      if(isdigit(*s))
	{
	  *s__ = *s;
	  s__++;
	  *s__ = '\0';
	}
      *s++;
    }
  s = s_;
  while(*s != '\0')
    {
      if(isalpha(*s))
	{
	  *s__ = *s;
	  s__++;
	  *s__ = '\0';
	}
      *s++;
    }
  s = s_;
  while(*s != '\0')
    {
      if((!isalpha(*s))  &&  (!isdigit(*s)))
	{
	  *s__ = *s;
	  s__++;
	  *s__ = '\0';
	}
      *s++;
    }
}

int main()
{
  char string[BUFSIZ] = "ibt8btb 76g,;lktuy;lhk,.;/ gbyuv98 b5w6bhpobtrb y6ti,m:";
  char pstr[BUFSIZ];
  
  str(string,pstr);
  
  printf("New size : %s\n",pstr);
  return 0;
}
