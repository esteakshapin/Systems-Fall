
#include <stdio.h>
int sumOfSquares(int upperLimit)
{
    int sum = 0;
    while (upperLimit > 0)
    {
        sum = sum + upperLimit * upperLimit;
        upperLimit = upperLimit - 1;
    }
    return sum;
}

int squareOfSum(int upperLimit)
{
    int sum = 0;
    while (upperLimit > 0)
    {
        sum = sum + upperLimit;
        upperLimit = upperLimit - 1;
    }

    return sum * sum;
}
int main()
{
    int testValue = 100;
    printf("%d /n", squareOfSum(testValue) - sumOfSquares(testValue));

    return 0;
}
