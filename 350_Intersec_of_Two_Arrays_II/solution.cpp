#include "header.h"
#include "unordered_map"

vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
    unordered_map<int, int> map1, map2;

    int index = 0;
    while (index < nums1.size() || index < nums2.size())
    {
        if (index < nums1.size())
        {
            map1[nums1[index]] += 1;
        }

        if (index < nums2.size())
        {
            map2[nums2[index]] += 1;
        }

        ++index;
    }

    vector<int> result;

    for (unordered_map<int, int>::iterator it = map1.begin(); it != map1.end(); it++)
    {
        if (map2[it->first] > 0)
        {
            result.insert(result.end(), min(it->second, map2[it->first]), it->first);
        }
    }

    return result;
}