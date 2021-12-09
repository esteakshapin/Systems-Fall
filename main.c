#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#define SIZE 10

void errorHandle(int result, char *errMessage)
{
    if (result < 0)
    {
        printf("error: %s -> \t %s \n", errMessage, strerror(errno));
        exit(-1);
    }
}
int *randomInts(int size)
{
    // creating extra space to have a zero at the end
    int *arr = calloc(size + 1, sizeof(int));
    int randomFile = open("/dev/random", O_RDONLY, 0);

    errorHandle(randomFile, "opening dev/random");

    int rdResult = read(randomFile, arr, size * sizeof(int));

    errorHandle(rdResult, "reading dev/random");

    //closing dev file
    int closeRes = close(randomFile);
    errorHandle(closeRes, "closing dev/random");
    return arr;
}

void printArr(int *arr)
{
    int counter = 0;
    while (*(arr + counter))
    {
        printf("\t random number[%d]: \t %d \n", counter, *(arr + counter));
        counter++;
    }
}

int main(void)
{
    int *randomNumbers = randomInts(SIZE);

    printf("Generating random Numbers: \n");
    printArr(randomNumbers);

    printf("Writing random Numbers to file... \n");
    int writeFile = open("rand.txt", O_WRONLY | O_CREAT, 0644);

    errorHandle(writeFile, "opening write file");

    int writeRes = write(writeFile, randomNumbers, SIZE * sizeof(int));
    errorHandle(writeRes, "writing numbers to file");
    //closing rand file
    int closeRes = close(writeFile);
    errorHandle(closeRes, "closing rand.txt writing");

    printf("Reading random Numbers to file... \n");
    int readFile = open("rand.txt", O_RDONLY, 0);
    errorHandle(readFile, "opening rand.txt(read)");

    int arr2[SIZE];
    int readRes = read(readFile, arr2, SIZE * sizeof(int));
    errorHandle(readRes, "reading rand.txt");

    printf("Verification that written values were the same: \n");
    printArr(arr2);
    return 0;
}