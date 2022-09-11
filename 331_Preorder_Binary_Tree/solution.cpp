#include "header.h"
#include <stack>

bool isValidSerialization(string preorder)
{
    bool result = true;
    stack<string> pending;

    int pos = 0;
    bool wait_for_right = false;

    while (pos < preorder.length())
    {
        int pos_comma = preorder.find(',', pos);

        if (pos_comma == preorder.npos)
        {
            pos_comma = preorder.length();
        }

        string sub = preorder.substr(pos, pos_comma - pos);
        pos = pos_comma + 1;

        if (!wait_for_right)
        {
            if(sub != "#")
            {
                pending.push(sub);
                wait_for_right = false;
            }
            else
            {
                wait_for_right = true;
            }
        }
        else
        {
            if (!pending.empty())
            {
                pending.pop();
                if (sub != "#")
                {
                    pending.push(sub);
                    wait_for_right = false;
                }
            }
            else
            {
                // when wait_for_right is true and no pending node, it is not a tree.
                result = false;
                break;
            }
        }
    }

    return result ? pending.empty() : result;
}