#include <stdio.h>

#define ARR_LENGTH 9

#define BACKWARD_LENGTH_EQUATION (ARR_LENGTH - (a + 1))

void printArr(int *arr)
{
    printf(" \n Arr = [ ");
    int a;
    for (a = 0; a < ARR_LENGTH; a++)
    {
        printf("%d ", arr[a]);
    }
    printf("] \n");
}

double averageArr(int *arr)
{
    double avg = 0.0;
    int a;
    for (a = 0; a < ARR_LENGTH / 2; a++)
    {
        avg = avg + ((double)arr[a] / ARR_LENGTH) + ((double)arr[BACKWARD_LENGTH_EQUATION] / ARR_LENGTH);
    }

    return avg;
}

void copyArr(int *arrp, int *arr2p)
{
    int a;
    for (a = 0; a < ARR_LENGTH / 2; a++)
    {
        arr2p[BACKWARD_LENGTH_EQUATION] = arrp[BACKWARD_LENGTH_EQUATION];
        arr2p[a] = arrp[a];
    }

    printf("\n \n ARRAY 2");
    printArr(arr2p);
}

int main(void)
{

    int arr[ARR_LENGTH];
    arr[0] = 0;
    int a;
    for (a = 1; a < ARR_LENGTH; a++)
    {
        arr[a] = a;
    }

    //1
    printf("\n \n ARRAY 1");
    printArr(arr);

    //2
    printf("\n The Average of arr is -- %0.2f --", averageArr(arr));

    //3
    int arr2[ARR_LENGTH];
    copyArr(arr, arr2);

    return 0;
}