#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NO_ARGS_ERR -101
#define INPUT_FILE_ERR -102
#define OUTPUT_FILE_ERR -103

typedef struct Student
{
	unsigned id;
	char* surname;
	char* name;
	char* groop;
} Student;


typedef struct StudentArray
{
	Student* students;
	size_t size;
} StudentArray;

int err_code = 0;

void ReadFileToSpace(FILE* file, char** dst);
void SortById(StudentArray* myStudent);
void SortByName(StudentArray* myStudent);
void SortBySurname(StudentArray* myStudent);
void SortByGroop(StudentArray* myStudent);



int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		err_code = NO_ARGS_ERR;
		perror("No arguments were passed!");
		exit(err_code);
	}

	const char* inputFileName = argv[1];

	FILE* fin;

	if (!(fin = fopen(inputFileName, "r")))
	{
		err_code = INPUT_FILE_ERR;
		perror("Input file can not be opened!");
		exit(err_code);
	}

	StudentArray array = {NULL, 0};

	while (!feof(fin))
	{
		array.students = (Student*)realloc(array.students, ++(array.size) * sizeof(Student));
		fscanf(fin, "%d ", &(array.students[array.size - 1]).id);
		ReadFileToSpace(fin, &(array.students[array.size - 1].name));
		ReadFileToSpace(fin, &(array.students[array.size - 1].surname));
		ReadFileToSpace(fin, &(array.students[array.size - 1].groop));
		fgetc(fin);
	}

	fclose(fin);

	int sort;

	printf("How to sort :\n 1. Id\n 2. Name\n 3. Surname\n 4. Groop\n");
	scanf("%d",&sort);

	if(sort == 1)
	{
		SortById(&array);
	}
	else if(sort == 2)
	{
		SortByName(&array);
	}
	else if(sort == 3)
	{
		SortBySurname(&array);
	}
	else if(sort == 4)
	{
		SortByGroop(&array);
	}

	return EXIT_SUCCESS;
}


void ReadFileToSpace(FILE* file, char** dst)
{
	char c;
	size_t length = 1;

	(*dst) = (char*)malloc(sizeof(char));
	(*dst)[0] = '\0';

	while ((c = fgetc(file)) != ' ')
	{
		(*dst) = (char*)realloc((*dst), ++length * sizeof(char));
		(*dst)[length - 2] = c;
		(*dst)[length - 1] = '\0';
	}
}


void SortById(StudentArray* myStudent)
{
	unsigned Id_;

	printf("")

	for (int i = 1; i < myStudent->size; i++)
	{
		if(myStudent->students[i].id == Id_)
		{
			printf("%d %s %s %s \n",    				myStudent->students[i].id,
										myStudent->students[i].name,
										myStudent->students[i].surname,
										myStudent->students[i].groop);
		}
	}
}


void SortByName(StudentArray* myStudent)
{
	char c;
	size_t length = 1;
	char* str;

	*str = (char*)malloc(sizeof(char));
	*str = '\0';

	printf("Write name: \n");
	while((c = getchar()) != '\0')
	{
		*str = (char*)realloc((*str), ++length * sizeof(char));
		*str = c;
		str++;
		*str = '\0';
	}
	for (int i = 1; i < myStudent->size; i++)
	{
		if(strcmp(myStudent->students[i].name,str))
		{
			printf("%d %s %s %s \n",    				myStudent->students[i].id,
										myStudent->students[i].name,
										myStudent->students[i].surname,
										myStudent->students[i].groop);
		}
	}
}


void SortBySurname(StudentArray* myStudent)
{
	char c;
	size_t length = 1;
	char* str;

	*str = (char*)malloc(sizeof(char));
	*str = '\0';

	printf("Write surname: \n");
	while((c = getchar()) != '\0')
	{
		*str = (char*)realloc((*str), ++length * sizeof(char));
		*str = c;
		str++;
		*str = '\0';
	}
	for (int i = 1; i < myStudent->size; i++)
	{
		if(strcmp(myStudent->students[i].surname,str))
		{
			printf("%d %s %s %s \n",    myStudent->students[i].id,
										myStudent->students[i].name,
										myStudent->students[i].surname,
										myStudent->students[i].groop);
		}
	}
}


void SortByGroop(StudentArray* myStudent)
{
	char c;
	size_t length = 1;
	char* str;

	*str = (char*)malloc(sizeof(char));
	*str = '\0';

	printf("Write groop: \n");
	while((c = getchar()) != '\0')
	{
		*str = (char*)realloc((*str), ++length * sizeof(char));
		*str = c;
		str++;
		*str = '\0';
	}
	for (int i = 1; i < myStudent->size; i++)
	{
		if(strcmp(myStudent->students[i].groop,str))
		{
			printf("%d %s %s %s \n",    myStudent->students[i].id,
										myStudent->students[i].name,
										myStudent->students[i].surname,
										myStudent->students[i].groop);
		}
	}
} 
