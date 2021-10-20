#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "teacher.h"

struct teacher *insert_front(struct teacher *teacherList, struct teacher *newTeacher)
{
    newTeacher->nextTeacher = teacherList;
    return newTeacher;
}

struct teacher *remove_node(struct teacher *teacherList, struct teacher *oldTeacher)
{

    struct teacher *prevTeacher = NULL;
    struct teacher *currentTeacher = teacherList;

    while (currentTeacher)
    {
        printf("%s \n", teacherList->name);
        printf("%s \n", currentTeacher->name);
        printf("%s \n", oldTeacher->name);

        if (strcmp(currentTeacher->name, oldTeacher->name) == 0 &&
            currentTeacher->grade == oldTeacher->grade &&
            currentTeacher->numberOfClasses == oldTeacher->numberOfClasses &&
            currentTeacher->nextTeacher == oldTeacher->nextTeacher)
        {
            printf("removing \n");
            printf("match \n");
            if (prevTeacher)
            {
                prevTeacher->nextTeacher = currentTeacher->nextTeacher;
            }
            if (currentTeacher == teacherList) //removing the node if its in the beginning
            {
                teacherList = currentTeacher->nextTeacher;
            }

            free(currentTeacher);
            return teacherList;
        }
        prevTeacher = currentTeacher;
        currentTeacher = currentTeacher->nextTeacher;
    }
    return teacherList;
}

void print_list(struct teacher *teacherList)
{
    printf("[\n");
    int n = 0;
    while (teacherList)
    {
        printf("%d: \t", n);
        printTeacher(teacherList);
        teacherList = teacherList->nextTeacher;
        n++;
    }
    printf("]\n");
}

struct teacher *free_list(struct teacher *teacherList)
{
    struct teacher *temp;
    while (teacherList)
    {
        temp = teacherList->nextTeacher;
        free(teacherList);
        teacherList = temp;
    }

    return teacherList;
}
