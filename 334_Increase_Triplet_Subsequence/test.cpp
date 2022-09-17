#include "header.h"

void PrepareTestData(vector<TD_VI_B>& testData)
{
    TD_VI_B data = {};

    data.input = { 1,2,3,4,5 };
    data.output = true;
    testData.push_back(data);

    data.input = { 5,4,3,2,1 };
    data.output = false;
    testData.push_back(data);

    data.input = { 2,1,5,0,4,6 };
    data.output = true;
    testData.push_back(data);

    data.input = { 1, 1, -2, 6 };
    data.output = false;
    testData.push_back(data);
 }