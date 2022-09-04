#include "header.h"

int bulbSwitch2(int n)
{
    int count = 0;
    for (int i = 1; i * i <= n; i++)
    {
        ++count;
    }
    return count;
}