#pragma once

#include "../common/common.h"

class NumArray {
public:
    NumArray(vector<int>& nums) :
        sums(nums.size(), 0)
    {
        sums[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            sums[i] = sums[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right)
    {
        if (left > 0)
        {
            return sums[right] - sums[left - 1];
        }
        else
        {
            return sums[right];
        }
        
    }

private:
    vector<int> sums;
};