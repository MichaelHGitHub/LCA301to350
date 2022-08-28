#include "header.h"
#include <unordered_set>

string smallestString(string s, int pos, int length, int expect_len, unordered_set<char>& letterDup, unordered_set<char>& letterTaken);

string removeDuplicateLetters(string s)
{
    unordered_set<char> letter_dup;
    unordered_set<char> letter_taken;
    int length = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (letter_taken.find(s[i]) == letter_taken.end())
        {
            ++length;
            letter_taken.insert(s[i]);
        }
        else
        {
            letter_dup.insert(s[i]);
        }
    }

    letter_taken.clear();

    return smallestString(s, 0, 0, length, letter_dup, letter_taken);
}


string smallestString(string s, int pos, int length, int expect_len, unordered_set<char>& letterDup, unordered_set<char>& letterTaken)
{
    if (pos >= s.length() || length > expect_len)
    {
        return "";
    }

    string result;
    for (int i = pos; i < s.length(); i++)
    {
        if (letterDup.find(s[i]) != letterDup.end())
        {
            if (letterTaken.find(s[i]) == letterTaken.end())
            {
                string temp1 = smallestString(s, i + 1, length, expect_len, letterDup, letterTaken);

                letterTaken.insert(s[i]);
                string temp2 = s[i] + smallestString(s, i + 1, length + 1, expect_len, letterDup, letterTaken);
                letterTaken.erase(s[i]);

                if (temp1.length() == expect_len - length && temp2.length() == expect_len - length)
                {
                    if (result.length() == 0)
                    {
                        result = temp1 > temp2 ? temp2 : temp1;
                    }
                    else
                    {
                        result = temp1 > result ? result : temp1;
                        result = temp2 > result ? result : temp2;
                    }

                }
                else if (temp1.length() == expect_len - length)
                {
                    if (result.length() == 0)
                    {
                        result = temp1;
                    }
                    else
                    {
                        result = temp1 > result ? result : temp1;
                    }
                }
                else if (temp2.length() == expect_len - length)
                {
                    if (result.length() == 0)
                    {
                        result = temp2;
                    }
                    else
                    {
                        result = temp2 > result ? result : temp2;
                    }
                }
            }
            else
            {
                string temp = smallestString(s, i + 1, length, expect_len, letterDup, letterTaken);
                if (temp.length() == expect_len - length)
                {
                    if (result.length() == 0)
                    {
                        result = temp;
                    }
                    else
                    {
                        result = temp > result ? result : temp;
                    }
                }
            }
        }
        else
        {
            string temp = s[i] + smallestString(s, i + 1, length + 1, expect_len, letterDup, letterTaken);
            if (temp.length() == expect_len - length)
            {
                if (result.length() == 0)
                {
                    result = temp;
                }
                else
                {
                    result = temp > result ? result : temp;
                }
            }
        }
    }

    return result;
}