#include "header.h"

int maxProduct2(vector<string>& words)
{
    vector<int> letter_counts(words.size(), 0);

    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words[i].length(); j++)
        {
            letter_counts[i] |= (1 << (words[i][j] - 'a'));
        }
    }

    int max_product = 0;
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = i + 1; j < words.size(); j++)
        {
            if (!(letter_counts[i] & letter_counts[j]))
            {
                max_product = max(max_product, (int)words[i].length() * (int)words[j].length());
            }
        }
    }
    return max_product;
}
