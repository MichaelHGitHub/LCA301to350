#include "header.h"

bool increasingTriplet2(vector<int>& nums)
{
    // The following algurathism indicates that there is always a number
    // before c2 that is less than c2, which might or might not be c1

    bool result = false;
    int c1 = INT_MAX, c2 = INT_MAX;

    for (int x : nums)
    {
        if (x <= c1)
        {
            c1 = x;
        }
        else if (x <= c2)
        {
            c2 = x;
        }
        else
        {
            result = true;;
        }
    }
    return result;
}