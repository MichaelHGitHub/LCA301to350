#include "header.h"

void PrepareTestData(vector<TD_S_B>& testData)
{
    TD_S_B data = {};

    data.input = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    data.output = true;
    testData.push_back(data);

    data.input = "1,#";
    data.output = false;
    testData.push_back(data);

    data.input = "9,#,#,1";
    data.output = false;
    testData.push_back(data);

}