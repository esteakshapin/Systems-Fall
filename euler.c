
// Problem 1
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

// Problem 5
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

// Problem 6
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