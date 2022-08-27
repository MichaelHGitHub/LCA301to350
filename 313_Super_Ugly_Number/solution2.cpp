#include "header.h"

int nthSuperUglyNumber2(int n, vector<int>& primes)
{
    vector<int> uglis(n, 0);
    vector<int> indices(primes.size(), 0);

    uglis[0] = 1;

    for (int i = 1; i < n; i++)
    {
        int ugly = INT_MAX;

        for (int j = 0; j < primes.size(); j++)
        {
            long long temp = (long long)primes[j] * uglis[indices[j]];
            ugly = ugly > temp ? (int)temp : ugly;
        }

        uglis[i] = ugly;

        for (int j = 0; j < primes.size(); j++)
        {
            long long temp = (long long)primes[j] * uglis[indices[j]];

            if (uglis[i] == temp)
            {
                indices[j]++;
            }
        }
    }
    return uglis[n - 1];
}