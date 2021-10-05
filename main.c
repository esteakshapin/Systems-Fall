#include <stdio.h>
/* assignment1.c:  My first C program on a Linux */
int main(void)
{

    // 1
    int num1 = 1;
    long longNum = 9223372036854775807;
    char char1 = 'a';

    //2
    printf("\n int -- hex: %x decimal: %d \n", &num1, &num1);
    printf("\n long -- hex: %x decimal: %d \n", &longNum, &longNum);
    printf("\n char -- hex: %x decimal: %d \n", &char1, &char1);

    //3
    int *num1p = &num1;
    long *longNump = &longNum;
    char *char1p = &char1;

    //4
    printf("\n int using pointer -- %d \n", *num1p);
    printf("\n long using pointer -- %ld \n", *longNump);
    printf("\n char using pointer -- %c \n", *char1p);

    //5
    *num1p = 21;
    *longNump = 50000000000000000000000;
    *char1p = 'B';

    printf("\n New char value using pointer: %d \n", *num1p);
    printf("\n New int value using pointer: %ld \n", *longNump);
    printf("\n New long value using pointer: %c \n", *char1p);

    //6
    unsigned int n = 50;
    unsigned int *np = &n;
    char *np2 = &n;

    //7
    printf("\n np: %p\t np points to %u \n", np, *np);
    printf("\n np2: %p\t np2 points to %u \n", np2, *np2);

    //8
    printf("\n int n in hex: %x\n", n);
    printf("\n int n in decimal: %u\n", n);

    //9
    int a;
    for (a = 0; a < 4; a++)
    {
        printf("\n byte %d of unsigned integer %d: %hhx \n", a + 1, n, *(np + a));
    }

    //10
    for (a = 0; a < 4; a++)
    {
        printf("\n byte %d of unsigned integer %d + 1 \n hex: %hhx \t decimal: %hhu \n", a + 1, n, *(np + a) + 1, *(np + a) + 1);
    }

    //11
    for (a = 0; a < 4; a++)
    {
        printf("\n byte %d of unsigned integer %d + 16 \n hex: %hhx \t decimal: %hhu \n", a + 1, n, *(np + a) + 16, *(np + a) + 16);
    }

    return 0;
}