#pragma once

#include "..\common\common.h"

class NumArray {
public:
    NumArray(vector<int>& nums) :
        size(nums.size()),
        segments(4 * nums.size(), 0)
    {
        BuildSegTree(0, 0, size - 1, nums);
    }

    void update(int index, int val)
    {
        UpdateSegTree(0, 0, size - 1, index, val);
    }

    int sumRange(int left, int right)
    {
        return GetSum(left, right, 0, 0, size - 1);
    }

private:

    void BuildSegTree(int node, int left, int right, vector<int>& nums)
    {
        if (left == right)
        {
            segments[node] = nums[left];
            return;
        }

        int mid = (left + right) / 2;
        BuildSegTree(2 * node + 1, left, mid, nums);
        BuildSegTree(2 * node + 2, mid + 1, right, nums);
        segments[node] = segments[2 * node + 1] + segments[2 * node + 2];
    }

    void UpdateSegTree(int node, int left, int right, int index, int val)
    {
        if (index < left || index > right)
        {
            return;
        }

        if (left == right)
        {
            if (left == index)
            {
                segments[node] = val;
            }
            return;
        }

        int mid = (left + right) / 2;
        UpdateSegTree(2 * node + 1, left, mid, index, val);
        UpdateSegTree(2 * node + 2, mid + 1, right, index, val);
        segments[node] = segments[2 * node + 1] + segments[2 * node + 2];
    }

    int GetSum(int qlow, int qhigh, int node, int left, int right)
    {
        if (qlow <= left && qhigh >= right)
        {
            return segments[node];
        }

        if (qlow > right || qhigh < left)
        {
            return 0;
        }

        int mid = (left + right) / 2;
        return GetSum(qlow, qhigh, 2 * node + 1, left, mid) + GetSum(qlow, qhigh, 2 * node + 2, mid + 1, right);
    }

    vector<int> segments;
    int size;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */