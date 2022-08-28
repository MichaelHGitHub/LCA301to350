#include "header.h"

void PrepareTestData(vector<TD_S_S>& testData)
{
    TD_S_S data = {};

    data.input = "bcab";
    data.output = "bca";
    testData.push_back(data);

    data.input = "bcabc";
    data.output = "abc";
    testData.push_back(data);


    data.input = "cbacdcbc";
    data.output = "acdb";
    testData.push_back(data);

    data.input = "thesqtitxyetpxloeevdeqifkz";
    data.output = "hesitxyplovdqfkz";
    testData.push_back(data);

}