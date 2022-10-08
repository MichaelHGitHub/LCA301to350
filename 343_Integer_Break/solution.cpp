#include "header.h"

int maxProduct(int n);

// If n > 4, the product of its factors will be larger than n itself
// therefore, the factors should not be larger than 4.
int integerBreak(int n)
{
    int max_product = 0;
    int f = min(4, n);

    for (int i = 1; i < f; i++)
    {
        max_product = max(max_product, i * maxProduct(n - i));
    }
    return max_product;
}


int maxProduct(int n)
{
    int max_product = n;

    int f = min(4, n);

    for (int i = 2; i < f; i++)
    {
        max_product = max(max_product, i * maxProduct(n - i));
    }

    return max_product;
}