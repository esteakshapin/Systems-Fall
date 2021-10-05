#include <stdio.h>
#include <time.h>

#define ARR_LENGTH 10

#define BACKWARD_LENGTH_EQUATION (ARR_LENGTH - (a + 1))

int main(void)
{

    //1
    int arr[ARR_LENGTH];

    //2
    arr[0] = 0;

    //3
    srand(time(NULL));
    int a;
    for (a = 1; a < ARR_LENGTH; a++)
    {
        arr[a] = rand();
    }

    //4
    printf("\n arr = {");

    for (a = 0; a < ARR_LENGTH; a++)
    {
        printf("%d, ", arr[a]);
    }

    printf("} \n");

    //5
    int arr2[ARR_LENGTH];

    //6
    int *arrp = arr;
    int *arr2p = arr2;

    //7
    for (a = 0; a < ARR_LENGTH / 2; a++)
    {
        arr2p[a] = arrp[BACKWARD_LENGTH_EQUATION];
        arr2p[BACKWARD_LENGTH_EQUATION] = arrp[a];
    }

    printf("\n arr2 = {");

    for (a = 0; a < ARR_LENGTH; a++)
    {
        printf("%d, ", arr2[a]);
    }

    printf("} \n");

    return 0;
}