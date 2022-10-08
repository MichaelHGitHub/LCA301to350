#include "header.h"

// We should get as many 3(factors) as possible
int integerBreak2(int n)
{
    int product = 1;

    if (n == 2)
    {
        product = 1;
    }
    else if (n == 3)
    {
        product = 2;
    }
    else
    {
        while (n > 4)
        {
            product *= 3;
            n -= 3;
        }
        product *= n;
    }

    return product;
}