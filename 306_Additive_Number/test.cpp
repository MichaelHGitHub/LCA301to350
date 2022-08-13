#include "header.h"

void PrepareTestData(vector<TD_S_B>& testData)
{
    TD_S_B data = {};

    data.input = "199100199";
    data.output = true;
    testData.push_back(data);

    data.input = "111";
    data.output = false;
    testData.push_back(data);

    data.input = "121474836472147483648";
    data.output = true;
    testData.push_back(data);

    data.input = "1991000199299498797";
    data.output = false;
    testData.push_back(data);


    data.input = "198019823962";
    data.output = true;
    testData.push_back(data);

    data.input = "10";
    data.output = false;
    testData.push_back(data);

    data.input = "101";
    data.output = true;
    testData.push_back(data);

    data.input = "112358";
    data.output = true;
    testData.push_back(data);
}