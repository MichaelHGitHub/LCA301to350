#include "header.h"

void PrepareTestData(vector<TD_I_I>& testData)
{
    TD_I_I data = {};

    data.input = 4;
    data.output = 4;
    testData.push_back(data);

    data.input = 3;
    data.output = 2;
    testData.push_back(data);

    data.input = 2;
    data.output = 1;
    testData.push_back(data);

    data.input = 10;
    data.output = 36;
    testData.push_back(data);
}