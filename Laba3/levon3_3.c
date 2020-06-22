#include <stdlib.h>
#include <stdio.h>

#pragma warning(disable:4996)

#define NO_ARGS_ERR -101
#define INPUT_FILE_ERR -102
#define OUTPUT_FILE_ERR -103

typedef struct Employee
{
    unsigned        id;
    char*           surname;
    char*           name;
    unsigned        salary;
} Employee;


typedef struct EmployeeArray
{
    Employee*       employees;
    size_t          size;
} EmployeeArray;

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

    EmployeeArray array = {NULL, 0};

    while (!feof(fin))
    {
        array.employees = (Employee*)realloc(array.employees, ++(array.size) * sizeof(Employee));
        fscanf(fin, "%d ", &(array.employees[array.size - 1]).id);
        ReadFileToSpace(fin, &(array.employees[array.size - 1].name));
        ReadFileToSpace(fin, &(array.employees[array.size - 1].surname));
        fscanf(fin, "%d", &(array.employees[array.size - 1].salary));
        fgetc(fin);
    }

    fclose(fin);

    int isSorted = 0;
    Employee tmp;

    while (!isSorted)
    {
        isSorted = 1;

        for (int i = 1; i < array.size; i++)
        {
            if (array.employees[i].salary < array.employees[i - 1].salary)
            {
                tmp = array.employees[i];
                array.employees[i] = array.employees[i - 1];
                array.employees[i - 1] = tmp;
                isSorted = 0;
            }
        }
    }

    if (!(fout = fopen(outputFileName, "w")))
    {
        err_code = OUTPUT_FILE_ERR;
        perror("Output file can not be opened!");
        exit(err_code);
    }

    for (int i = 0; i < array.size; i++)
    {
        fprintf(fout, "%d %s %s %d\n",  array.employees[i].id, 
                                        array.employees[i].surname, 
                                        array.employees[i].name, 
                                        array.employees[i].salary
        );
    }

    fclose(fout);
    
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
