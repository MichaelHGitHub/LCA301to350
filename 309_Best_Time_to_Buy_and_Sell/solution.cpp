#include "header.h"

int maxProfit(vector<int>& prices)
{
    // States of holding stock, come from rest or previous hold, can sell
    vector<int> hold(prices.size(), 0);
    // States of just sold stock, come from hold, must go to rest
    vector<int> sold(prices.size(), 0);
    // States of free, from sold or previous rest, can buy
    vector<int> rest(prices.size(), 0);

    hold[0] = -prices[0];
    sold[0] = 0;
    rest[0] = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        hold[i] = max(hold[i - 1], rest[i - 1] - prices[i]);
        sold[i] = hold[i - 1] + prices[i];
        rest[i] = max(rest[i - 1], sold[i - 1]);
    }

    return max(rest[rest.size() - 1], sold[sold.size() - 1]);
}