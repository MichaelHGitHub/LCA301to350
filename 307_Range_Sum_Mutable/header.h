#pragma once

#include "..\common\common.h"

class NumArray {
public:
    NumArray(vector<int>& nums) :
        sums(nums.size(), 0)
    {
        sums[0] = nums[0];

        for (int i = 1; i < sums.size(); i++)
        {
            sums[i] = nums[i] + sums[i - 1];
        }
    }

    void update(int index, int val)
    {
        int diff = index == 0 ? val - sums[index] : val - (sums[index] - sums[index - 1]);

        for (int i = index; i < sums.size(); i++)
        {
            sums[i] += diff;
        }
    }

    int sumRange(int left, int right)
    {
        return left == 0 ? sums[right] : sums[right] - sums[left - 1];
    }

private:
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
