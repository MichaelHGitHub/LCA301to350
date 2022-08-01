#pragma once

#include "../common/common.h"

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix):
    sums(matrix.size(), vector<int>(matrix[0].size(), 0))
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (i == 0 && j == 0)
                {
                    sums[i][j] = matrix[i][j];
                }
                else if (i == 0)
                {
                    sums[i][j] = sums[i][j - 1] + matrix[i][j];
                }
                else if(j == 0)
                {
                    sums[i][j] = sums[i - 1][j] + matrix[i][j];
                }
                else
                {
                    sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i-1][j-1] + matrix[i][j];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        if (row1 > 0 && col1 > 0)
        {
            return (sums[row2][col2] - sums[row1 - 1][col2] - sums[row2][col1 - 1] + sums[row1 - 1][col1 - 1]);
        }
        else if (row1 > 0)
        {
            return (sums[row2][col2] - sums[row1 - 1][col2]);
        }
        else if (col1 > 0)
        {
            return (sums[row2][col2] - sums[row2][col1 - 1]);
        }
        else
        {
            return sums[row2][col2];
        }
    }

private:
    vector<vector<int>> sums;
};