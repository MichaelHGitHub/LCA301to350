#include "header.h"
#include <unordered_set>

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
    unordered_set<int> set2(nums2.begin(), nums2.end(), nums2.size());
    unordered_set<int> result;

    for (int i = 0; i < nums1.size(); i++)
    {
        if (set2.find(nums1[i]) != set2.end() &&
            result.find(nums1[i]) == result.end())
        {
            result.insert(nums1[i]);
        }
    }

    return vector<int>(result.begin(), result.end());
}