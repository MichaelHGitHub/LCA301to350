#include "header.h"
#include <unordered_map>
#include <algorithm>

vector<int> topKFrequent(vector<int>& nums, int k)
{
    unordered_map<int, int> m_freq;
    for (int i = 0; i < nums.size(); i++)
    {
        m_freq[nums[i]]++;
    }

    vector<pair<int, int>> v_freq(m_freq.size());
    int index = 0;
    for (unordered_map<int, int>::iterator it = m_freq.begin(); it != m_freq.end(); it++)
    {
        v_freq[index++] = pair<int, int>(it->first, it->second);
    }

    sort(v_freq.begin(), v_freq.end(), [](pair<int, int> p1, pair<int, int> p2)
        {
            return p2.second < p1.second;
        });

    vector<int> result(k);

    for (int i = 0; i < k; i++)
    {
        result[i] = v_freq[i].first;
    }

    return result;
}