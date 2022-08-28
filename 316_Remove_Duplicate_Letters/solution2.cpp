#include "header.h"
#include <unordered_set>
#include <unordered_map>
#include <stack>

string removeDuplicateLetters2(string s)
{
    unordered_map<char, int> last_index;
    unordered_set<char> visited;
    stack<char> candidates;

    for (int i = 0; i < s.length(); i++)
    {
        last_index[s[i]] = i;
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (visited.find(s[i]) == visited.end())
        {
            while (!candidates.empty() && s[i] < candidates.top() && last_index[candidates.top()] > i)
            {
                visited.erase(candidates.top());
                candidates.pop();
            }

            candidates.push(s[i]);
            visited.insert(s[i]);
        }
    }

    string result(candidates.size(), ' ');
    size_t pos = candidates.size() - 1;
    while (!candidates.empty())
    {
        result[pos--] = candidates.top();
        candidates.pop();
    }

    return result;
}