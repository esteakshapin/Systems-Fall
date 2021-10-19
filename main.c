#include <stdio.h>
#include <stdlib.h>
#include "namegen.h"

struct teacher
{
    char *name;
    int grade;
    int numberOfClasses;
};

void printTeacher(struct teacher *teacher)
{
    printf("%s is a grade %d teacher who currently teaches %d classes.", teacher->name, teacher->grade, teacher->numberOfClasses);
}

struct teacher *createTeacher(char *name, int grade, int numberOfClasses)
{
    struct teacher *newTeacher;

    newTeacher = malloc(sizeof(struct teacher));

    newTeacher->name = name;
    newTeacher->grade = grade;
    newTeacher->numberOfClasses = numberOfClasses;

    return newTeacher;
}

int main()
{

    //creating 1st teacher
    struct teacher *john = createTeacher("john", 5, 2);

    //printng out first teacher
    printTeacher(john);

    //freeing first teacher
    free(john);

    //creting random teachers with random values

    //initializing random
    srand(time(NULL));

    char firstTeacherName[21];
    char secondTeacherName[21];
    char thirdTeacherName[21];

    struct teacher *firstTeacher = createTeacher(NameGen(firstTeacher), )

        return 0;
}