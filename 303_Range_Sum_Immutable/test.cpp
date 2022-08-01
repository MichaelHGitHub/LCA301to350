#include "header.h"

void PrepareTestData(vector<TD_VI_I>& testData)
{
    TD_VI_I data;

    data.input = { 3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12 };
    data.output = 6;
    testData.push_back(data);

    data.input = { 10,9,2,5,3,7,101,18 };
    data.output = 4;
    testData.push_back(data);

    data.input = { 0,1,0,3,2,3 };
    data.output = 4;
    testData.push_back(data);

    data.input = { 7,7,7,7,7,7,7 };
    data.output = 1;
    testData.push_back(data);
}