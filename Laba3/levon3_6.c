#include <stdlib.h>
#include <stdio.h>


#define NO_ARGS_ERR -101
#define INPUT_FILE_ERR -102
#define OUTPUT_FILE_ERR -103

typedef struct Student
{
	char* surname;
	char* name;
	char* patronymic;
	char* group;
	int Evaluation[5];
	double srSum;
} Student;


typedef struct StudentArray
{
	Student* students;
	size_t size;
} StudentArray;

int err_code = 0;

void ReadFileToSpace(FILE* file, char** dst);

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		err_code = NO_ARGS_ERR;
		perror("No arguments were passed!");
		exit(err_code);
	}

	const char* inputFileName = argv[1];
	const char* outputFileName = "output.txt";

	FILE* fin;
	FILE* fout;

	if (!(fin = fopen(inputFileName, "r")))
	{
		err_code = INPUT_FILE_ERR;
		perror("Input file can not be opened!");
		exit(err_code);
	}

	StudentArray array = {NULL, 0};

	double allSrSum = 0;

	while (!feof(fin))
	{
		array.students = (Student*)realloc(array.students, ++(array.size) * sizeof(Student));
		ReadFileToSpace(fin, &(array.students[array.size - 1].surname));
		ReadFileToSpace(fin, &(array.students[array.size - 1].name));
		ReadFileToSpace(fin, &(array.students[array.size - 1].patronymic));
		ReadFileToSpace(fin, &(array.students[array.size - 1].group));
		for(int i = 0;i < 5;i++)
		{
			array.students[array.size - 1].srSum = .0;
			fscanf(fin, "%d", &(array.students[array.size - 1].Evaluation[i]));
			array.students[array.size - 1].srSum = array.students[array.size - 1].srSum +array.students[array.size - 1].Evaluation[i];
		}
		array.students[array.size - 1].srSum = array.students[array.size - 1].srSum/5.0;
		allSrSum = allSrSum + array.students[array.size - 1].srSum;
		fgetc(fin);
	}

	allSrSum = allSrSum/(array.size*1.0);

	fclose(fin);

	int isSorted = 0;
	Student tmp;



	if (!(fout = fopen(outputFileName, "w")))
	{
		err_code = OUTPUT_FILE_ERR;
		perror("Output file can not be opened!");
		exit(err_code);
	}

	for (int i = 0; i < array.size; i++)
	{
		fprintf(fout, "%s %s %s %s %f\n",  array.students[i].surname,
										array.students[i].name,
										array.students[i].patronymic,
										array.students[i].group,
										array.students[i].srSum);
	}

	fclose(fout);

	for (int i = 0; i < array.size; i++)
	{
		if(allSrSum <= array.students[i].srSum)
		{
			printf("%s %s %s %s %f\n",   array.students[i].surname,
											array.students[i].name,
											array.students[i].patronymic,
											array.students[i].group,
											array.students[i].srSum);
		}
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
