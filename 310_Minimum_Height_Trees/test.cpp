#include "header.h"

void PrepareTestData(vector<TD_I_VVI_VI>& testData)
{
    TD_I_VVI_VI data = {};

    data.input = 6;
    data.input2 = { {0, 1} ,{0, 2},{0, 3},{3, 4},{4, 5} };
    data.output = { 3 };
    testData.push_back(data);

    data.input = 4;
    data.input2 = {{1, 0}, {1, 2}, {1, 3}};
    data.output = {1};
    testData.push_back(data);

    data.input = 6;
    data.input2 = {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
    data.output = {3, 4};
    testData.push_back(data);

}