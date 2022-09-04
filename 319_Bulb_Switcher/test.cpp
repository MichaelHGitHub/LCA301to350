#include "header.h"

void PrepareTestData(vector<TD_I_I>& testData)
{
    TD_I_I data = {};

    data.input = 3;
    data.output = 1;
    testData.push_back(data);

    data.input = 0;
    data.output = 0;
    testData.push_back(data);

    data.input = 9999999;
    data.output = 3162;
    testData.push_back(data);
}