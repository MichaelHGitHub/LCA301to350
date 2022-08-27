#include "header.h"
#include <unordered_set>

bool isUglyNum(vector<int>& primes, std::unordered_set<int>& ugly_set, std::unordered_set<int>& pretty_set, int candidate);

int nthSuperUglyNumber(int n, vector<int>& primes)
{
    std::unordered_set<int> ugly_set;
    std::unordered_set<int> pretty_set;

    for (int i = 0; i < primes.size(); i++)
    {
        ugly_set.insert(primes[i]);
    }

    int count = 1;
    int candidate = 1;
    int ugly_number = candidate;

    while (count < n)
    {
        if(isUglyNum(primes, ugly_set, pretty_set, candidate))
        {
            ugly_number = candidate;
            ++count;
        }
        ++candidate;
    }

    return ugly_number;
}

bool isUglyNum(vector<int>& primes, std::unordered_set<int>& ugly_set, std::unordered_set<int>& pretty_set, int candidate)
{
    bool isUgly = false;

    if (ugly_set.find(candidate) != ugly_set.end())
    {
        isUgly = true;
    }
    else if (pretty_set.find(candidate) != pretty_set.end())
    {
        isUgly = false;
    }
    else
    {
        for (int i = 0; i < primes.size(); i++)
        {
            if (candidate % primes[i] == 0)
            {
                isUgly = isUglyNum(primes, ugly_set, pretty_set, candidate / primes[i]);
                break;
            }
        }

        if (isUgly)
        {
            ugly_set.insert(candidate);
        }
        else
        {
            pretty_set.insert(candidate);
        }
    }

    return isUgly;
}