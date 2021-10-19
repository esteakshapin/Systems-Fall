#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "namegen.h"

struct teacher
{
    char *name;
    int grade;
    int numberOfClasses;
};

void printTeacher(struct teacher *teacher)
{
    printf("%s is a grade %d teacher who currently teaches %d classes. \n", teacher->name, teacher->grade, teacher->numberOfClasses);
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

    char *s = NameGen();

    int counter = 0;
    while (counter < 5)
    {
        struct teacher *t = createTeacher(NameGen(), (rand() % 12), (rand() % 6));

        //printing teacher
        printTeacher(t);

        //freeing teahce name heap memory
        free(t->name);

        //freeing teacher heap memory
        free(t);

        counter++;
    }

    return 0;
}