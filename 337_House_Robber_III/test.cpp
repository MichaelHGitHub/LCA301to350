#include "header.h"

void PrepareTestData(vector<TD_T_I>& testData)
{
    TD_T_I data = {};

    data.input = GenerateTree({ 2, 1, 3, NULL_NODE_VALUE, 4 });
    data.output = 7;
    testData.push_back(data);

    data.input = GenerateTree({ 3, 2, 3,NULL_NODE_VALUE, 3, NULL_NODE_VALUE, 1 });
    data.output = 7;
    testData.push_back(data);

    data.input = GenerateTree({ 3,4,5,1,3,NULL_NODE_VALUE,1 });
    data.output = 9;
    testData.push_back(data);

    data.input = GenerateTree({ 4, 1, NULL_NODE_VALUE, 2, NULL_NODE_VALUE, 3 });
    data.output = 7;
    testData.push_back(data);
}