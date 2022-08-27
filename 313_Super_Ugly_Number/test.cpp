#include "header.h"

void PrepareTestData(vector<TD_I_VI_I>& testData)
{
    TD_I_VI_I data = {};

    data.input = 12;
    data.input2 = { 2,7,13,19 };
    data.output = 32;
    testData.push_back(data);

    data.input = 1;
    data.input2 = { 2,3,5 };
    data.output = 1;
    testData.push_back(data);

    data.input = 5911;
    data.input2 = { 2, 3, 5, 7 };
    data.output = 2144153025;
    testData.push_back(data);
    
    data.input = 100000;
    data.input2 = { 7, 19, 29, 37, 41, 47, 53, 59, 61, 79, 83, 89, 101, 103, 109, 127, 131, 137, 139, 157, 167, 179, 181, 199, 211, 229, 233, 239, 241, 251 };
    data.output = 1092889481;
    testData.push_back(data);

}