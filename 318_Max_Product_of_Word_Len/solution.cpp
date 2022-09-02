#include "header.h"

bool exclusiveString(vector<vector<bool>>& letter_counts, int i, int j);

int maxProduct(vector<string>& words)
{
    vector<vector<bool>> letter_counts(words.size(), vector<bool>(26, false));

    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words[i].length(); j++)
        {
            letter_counts[i][words[i][j] - 'a'] = true;
        }
    }

    int max_product = 0;
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = i + 1; j < words.size(); j++)
        {
            if (exclusiveString(letter_counts, i, j))
            {
                max_product = max(max_product, (int)words[i].length() * (int)words[j].length());
            }
        }
    }
    return max_product;
}

bool exclusiveString(vector<vector<bool>>& letter_counts, int i, int j)
{
    bool result = true;
    for (int k = 0; k < 26; k++)
    {
        if (letter_counts[i][k] && letter_counts[j][k])
        {
            result = false;
            break;
        }
    }
    return result;
}