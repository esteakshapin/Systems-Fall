#include <stdio.h>
/* assignment1.c:  My first C program on a Linux */
int main(void)
{

    int num1 = 1;
    int num2 = 2;

    long longNum = 12354;

    float floatNum = 12345.678;

    double doubleNum = 2416.1514;

    char testChar = 'E';

    char firstName[] = "Esteak";
    char lastName[] = "Shapin";

    printf("Hello My name is %s %s! The numbers of the day are: \n %d \n %d \n %ld \n %f \n %lf \n and last but not least my favorite letter %c",
           firstName, lastName, num1, num2, longNum, floatNum, doubleNum, testChar);

    return 0;
}