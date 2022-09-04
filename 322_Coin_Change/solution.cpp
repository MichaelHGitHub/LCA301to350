#include "header.h"

int leastCoin(vector<int>& coins, int pos, int amount);

int coinChange(vector<int>& coins, int amount)
{
    return leastCoin(coins, coins.size() - 1, amount);
}


int leastCoin(vector<int>& coins, int pos, int amount)
{
    int least_num = -1;

    if (amount == 0)
    {
        least_num = 0;
    }
    else if (amount > 0 && pos >= 0)
    {
        int count = amount / coins[pos];
        int num = 0;
        for (int i = count; i >= 0; i--)
        {
            num = leastCoin(coins, pos - 1, amount - i * coins[pos]);
            if (num >= 0)
            {
                if (least_num == -1)
                {
                    least_num = num + i;
                }
                else
                {
                    least_num = min(least_num, num + i);
                }
            }
        }
    }
    return least_num;
}