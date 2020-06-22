#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct String
{
    char*   text;
    size_t  length;
} String;

void CreateString(String* string, char* value);
void DeleteString(String* string);
int CompareString(String* str1, String* str2);
void ConcatenationString(String* str1, String* str2);
void DublicateString(String* src, String* dst);

int main()
{
    String str1;
    String str2;

    CreateString(&str1, "Hello, World!\n");
    CreateString(&str2, "I am a string!\n");

    ConcatenationString(&str1, &str2);

    printf("%s", str1.text);

    DeleteString(&str1);
    DeleteString(&str2);

    return EXIT_SUCCESS;
}


void CreateString(String* string, char* value)
{
    string->text = (char*)malloc((strlen(value) + 1) * sizeof(char));
    string->length = strlen(value);
    strcpy(string->text, value);
}


void DeleteString(String* string)
{
    free(string->text);
    string->length = 0;
}


int CompareString(String* str1, String* str2)
{
    char* pstr1 = str1->text;
    char* pstr2 = str2->text;

    while (*pstr1 && (*pstr1 == *pstr2))
    {
        pstr1++, pstr2++;
    }

    return *pstr1 - *pstr2;
}


void ConcatenationString(String* str1, String* str2)
{
    str1->text = (char*)realloc(str1->text, (str1->length + str2->length + 1) * sizeof(char));
    strcpy(str1->text + str1->length, str2->text);
    str1->length += (str2->length + 1);
}


void DublicateString(String* src, String* dst)
{
    dst->text = (char*)malloc((src->length + 1) * sizeof(char));
    dst->length = src->length;
    strcpy(dst->text, src->text);
}


