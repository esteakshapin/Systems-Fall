#include <stdio.h>

struct teacher
{
    char *name;
    int grade;
    int numberOfClasses;

    struct teacher *nextTeacher;
};
void printTeacher(struct teacher *teacher)
{
    if (teacher->nextTeacher)
    {
        printf("%s is a grade %d teacher who currently teaches %d classes. The next teacher in the list is %s\n", teacher->name, teacher->grade, teacher->numberOfClasses, teacher->nextTeacher->name);
    }
    else
    {
        printf("%s is a grade %d teacher who currently teaches %d classes.\n", teacher->name, teacher->grade, teacher->numberOfClasses);
    }
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