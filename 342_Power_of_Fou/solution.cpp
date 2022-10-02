#include "header.h"

bool isPowerOfFour(int n)
{
    bool result = false;

    while (n > 1)
    {
        if (n % 4 > 0)
        {
            result = false;
            break;
        }
        else
        {
            n = n >> 2;
        }
    }

    if (n == 1)
    {
        result = true;
    }

    return result;
}