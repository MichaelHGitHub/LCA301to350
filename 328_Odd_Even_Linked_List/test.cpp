#include "header.h"

void PrepareTestData(vector<TD_L_L>& testData)
{
    TD_L_L data = {};

    data.input = GenerateLinkedList({ 1,2,3,4,5 });
    data.output = GenerateLinkedList({ 1,3,5,2,4 });
    testData.push_back(data);

    data.input = GenerateLinkedList({ 2,1,3,5,6,4,7 });
    data.output = GenerateLinkedList({ 2,3,6,7,1,5,4 });
    testData.push_back(data);

}