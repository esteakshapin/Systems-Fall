
#include <stdio.h>
int evenDiv(int increment, int currentIndex)
{

    while (0 == 0)
    {
        int counter = increment - 1;

        while (counter > 0)
        {
            if (currentIndex % counter != 0)
            {
                break;
            }
            counter = counter - 1;
        }
        if (counter == 0)
        {
            return currentIndex;
        }

        currentIndex = currentIndex + increment;
    }
}
int main()
{
    printf("%d /n", evenDiv(20, 20));

    return 0;
}
