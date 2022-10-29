#include "header.h"

void PrepareTestData(vector<TD_VI_VI_VI>& testData)
{
    TD_VI_VI_VI data = {};

    data.input = { 1,2,2,1 };
    data.input2 = { 2, 2 };
    data.output = { 2, 2 };
    testData.push_back(data);

    data.input = { 4,9,5 };
    data.input2 = { 9,4,9,8,4 };
    data.output = { 9,4 };
    testData.push_back(data);
}