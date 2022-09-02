#include "header.h"

void PrepareTestData(vector<TD_VS_I>& testData)
{
    TD_VS_I data = {};

    data.input = { "a","aa","aaa","aaaa" };
    data.output = 0;
    testData.push_back(data);

    data.input = { "abcw","baz","foo","bar","xtfn","abcdef" };
    data.output = 16;
    testData.push_back(data);

    data.input = { "a","ab","abc","d","cd","bcd","abcd" };
    data.output = 4;
    testData.push_back(data);


}