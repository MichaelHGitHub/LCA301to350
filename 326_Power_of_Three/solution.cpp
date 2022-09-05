#include "header.h"

bool isPowerOfThree(int n)
{
    if (n == 1)
    {
        return true;
    }

    int power = 3;
    while (power <= n / 3)
    {
        if (n == (power *= 3))
        {
            break;
        }
    }

    return power == n;
}