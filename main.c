#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "namegen.h"
#include "teacher.h"
#include "nodeList.h"

int main()
{

    struct teacher *teacherList = NULL;

    //initializing random
    srand(time(NULL));

    int counter = 0;
    struct teacher *t;
    struct teacher *f;

    while (counter < 5)
    {
        t = createTeacher(NameGen(), (rand() % 12), (rand() % 6), NULL);

        if (counter == 3)
        {
            f = t;
        }

        //adding teacher to list
        teacherList = insert_front(teacherList, t);

        counter++;
    }

    //printing teachers
    print_list(teacherList);

    //testing removing node
    teacherList = remove_node(teacherList, f); //removing 3rh node
    print_list(teacherList);                   //printing new list

    //testing free list
    teacherList = free_list(teacherList);
    print_list(teacherList);

    return 0;
}