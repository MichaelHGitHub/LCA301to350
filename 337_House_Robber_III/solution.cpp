#include "header.h"
#include <queue>

int rob(TreeNode* root)
{
    queue<TreeNode*> pending;
    pending.push(root);

    vector<int> sums;

    while (!pending.empty())
    {
        int size = pending.size();
        int sum_of_level = 0;

        for (int i = 0; i < size; i++)
        {
            TreeNode* node = pending.front();
            pending.pop();

            if (node->left != nullptr)
            {
                pending.push(node->left);
            }

            if (node->right != nullptr)
            {
                pending.push(node->right);
            }

            sum_of_level += node->val;
        }
        sums.push_back(sum_of_level);
    }

    int max_value = 0;
    for (int i = 2; i < sums.size(); i++)
    {
        if (i > 2)
        {
            sums[i] = sums[i] + max(sums[i - 2], sums[i - 3]);
        }
        else if (i > 1)
        {
            sums[i] += sums[i - 2];
        }
    }

    return sums.size() < 2 ? sums[sums.size() - 1] : max(sums[sums.size() - 1], sums[sums.size() - 2]);
}

