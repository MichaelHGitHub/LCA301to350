#include "header.h"

void PrepareTestData(vector<TD_VI_I_I>& testData)
{
    TD_VI_I_I data = {};

    data.input = { 3,5 };
    data.input2 = 4;
    data.output = -1;
    testData.push_back(data);

    data.input = { 1,2,5 };
    data.input2 = 11;
    data.output = 3;
    testData.push_back(data);

    data.input = { 2 };
    data.input2 = 3;
    data.output = -1;
    testData.push_back(data);

    data.input = { 1 };
    data.input2 = 0;
    data.output = 0;
    testData.push_back(data);
 
    data.input = { 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422 };
    data.input2 = 9864;
    data.output = 24;
    testData.push_back(data);
}