#include "header.h"

int bulbSwitch(int n)
{
    vector<int> bulbs(n, true);

    for (int r = 2; r <= n; r++)
    {
        for (int i = r - 1; i < n; i += r)
        {
            bulbs[i] = !bulbs[i];
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (bulbs[i])
        {
            ++count;
        }
    }
    return count;
}