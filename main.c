#include "euler.h"
#include <stdio.h>

int main()
{

    printf(" \n problem 1 \n %d", sumMultiple3(1000) + sumMultiple5(1000));

    printf(" \n problem 5 \n %d", evenDiv(20, 20));

    int testValue = 100;
    printf(" \n problem 6 \n %d \n", squareOfSum(testValue) - sumOfSquares(testValue));
}