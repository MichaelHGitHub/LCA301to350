#include "header.h"

void PrepareTestData(vector<TD_VI_I>& testData)
{
    TD_VI_I data = {};


    data.input = { 6,1,6,4,3,0,2 };
    data.output = 7;
    testData.push_back(data);


    data.input = { 2, 1, 4 };
    data.output = 3;
    testData.push_back(data);

    data.input = { 1,2,3,0,2 };
    data.output = 3;
    testData.push_back(data);

    data.input = { 1 };
    data.output = 0;
    testData.push_back(data);
}