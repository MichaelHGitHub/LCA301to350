#include "header.h"
#include <unordered_map>

bool isAdditiveNumberCore(string str, int pos, string pre1, string pre2, string pre3);

string add(string str1, string str2);

bool isAdditiveNumber(string num)
{
    return isAdditiveNumberCore(num, 0, "-1", "-1", "-1");
}

bool isAdditiveNumberCore(string str, int pos, string pre1, string pre2, string pre3)
{
    bool isAdditive = false;

    if (pre1 != "-1" && pre2 != "-1" && pre3 != "-1" && pos >= str.length())
    {
        return true;
    }

    if (pre3 != "-1")
    {
        pre1 = pre2;
        pre2 = pre3;
        pre3 = "-1";
    }

    if (pre1 == "-1")
    {
        if (pos < str.length() && str[pos] == '0')
        {
            pre1 = "0";
            isAdditive = isAdditiveNumberCore(str, pos + 1, pre1, pre2, pre3);
        }
        else
        {
            for (int c = 1; c < str.length(); c++)
            {
                pre1 = str.substr(pos, c);
                if (true == (isAdditive = isAdditiveNumberCore(str, pos + c, pre1, pre2, pre3)))
                {
                    break;
                }
            }
        }
    }
    else if (pre2 == "-1")
    {
        if (pos < str.length() && str[pos] == '0')
        {
            pre2 = "0";
            isAdditive = isAdditiveNumberCore(str, pos + 1, pre1, pre2, pre3);
        }
        else
        {
            for (int c = 1; c < str.length() - pos; c++)
            {
                pre2 = str.substr(pos, c);
                if (true == (isAdditive = isAdditiveNumberCore(str, pos + c, pre1, pre2, pre3)))
                {
                    break;
                }
            }
        }
    }
    else
    {
        if (pos < str.length() && str[pos] == '0')
        {
            pre3 = "0";
            if (pre3 == add(pre1, pre2))
            {
                isAdditive = isAdditiveNumberCore(str, pos + 1, pre1, pre2, pre3);
            }
        }
        else
        {
            for (int c = 1; c <= str.length() - pos; c++)
            {
                pre3 = str.substr(pos, c);
                if (pre3 == add(pre1, pre2))
                {
                    if (true == (isAdditive = isAdditiveNumberCore(str, pos + c, pre1, pre2, pre3)))
                    {
                        break;
                    }
                }
            }
        }
    }
    return isAdditive;
}

string add(string str1, string str2)
{
    string result;

    int l1 = str1.length() - 1;
    int l2 = str2.length() - 1;

    int carry = 0;

    while (l1 >= 0 || l2 >= 0)
    {
        int sum = 0;

        if (l1 >= 0)
        {
            sum += (str1[l1] - '0');
        }

        if (l2 >= 0)
        {
            sum += (str2[l2] - '0');
        }

        sum += carry;
        result.push_back((sum % 10) + '0');

        carry = sum / 10;
        --l1;
        --l2;
    }

    if (carry != 0)
    {
        result.push_back(carry + '0');
    }

    std::reverse(result.begin(), result.end());
    return result;
}