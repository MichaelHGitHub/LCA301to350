#include "header.h"
#include <unordered_set>

string reverseVowels(string s)
{
    int left = 0, right = s.size() - 1;
    unordered_set<char> vowels(
        { 'a', 'e', 'i', 'o', 'u',
          'A', 'E', 'I', 'O', 'U' });

    while (left < right)
    {
        while (left < right && vowels.find(s[left]) == vowels.end())
        {
            ++left;
        }

        while (left < right && vowels.find(s[right]) == vowels.end())
        {
            --right;
        }

        if (left < right)
        {
            char c = s[left];
            s[left++] = s[right];
            s[right--] = c;
        }
    }
    return s;
}