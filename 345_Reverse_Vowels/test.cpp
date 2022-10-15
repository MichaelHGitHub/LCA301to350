#include "header.h"

void PrepareTestData(vector<TD_S_S>& testData)
{
    TD_S_S data = {};

    data.input = "hello";
    data.output = "holle";
    testData.push_back(data);

    data.input = "leetcode";
    data.output = "leotcede";
    testData.push_back(data);


}