#include "header.h"

int main(char* args[], int argc)
{
    vector<TD_VI_VI_VI> test_data;

    PrepareTestData(test_data);

    for (int i = 0; i < test_data.size(); i++)
    {
        PrintInput(test_data[i]);
        vector<int> result = intersect(test_data[i].input, test_data[i].input2);

        CheckResults(test_data[i], result);
    }

    return 0;
}
