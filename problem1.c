
#include <stdio.h>
int sumMultiple3(int max)
{
    int x = 1;
    int sum = 0;
    while (x < max)
    {
        if (x % 3 == 0)
        {
            sum = sum + x;
        }
        x = x + 1;
    }
    return sum;
}

int sumMultiple5(int max)
{
    int x = 1;
    int sum = 0;
    while (x < max)
    {
        if (x % 5 == 0 && x % 3 != 0)
        {

            sum = sum + x;
        }
        x = x + 1;
    }
    return sum;
}

int main()
{
    printf("%d", sumMultiple3(1000) + sumMultiple5(1000));

    return 0;
}
