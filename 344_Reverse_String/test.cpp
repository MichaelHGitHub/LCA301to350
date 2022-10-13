#include "header.h"

void PrepareTestData(vector<TD_VC_VC>& testData)
{
    TD_VC_VC data = {};

    data.input = { 'h','e','l','l','o' };
    data.output = { 'o','l','l','e','h' };
    testData.push_back(data);

    data.input = { 'H','a','n','n','a','h' };
    data.output = { 'h','a','n','n','a','H' };
    testData.push_back(data);   


}