#include "header.h"

int tryRob(TreeNode* node, int& l, int& r);

int rob2(TreeNode* root)
{
    int l = 0, r = 0;
    return tryRob(root, l, r);
}


int tryRob(TreeNode* node, int& l, int& r)
{
    if (node == nullptr)
    {
        return 0;
    }

    int ll = 0, lr = 0, rl = 0, rr = 0;

    l = tryRob(node->left, ll, lr);
    r = tryRob(node->right, rl, rr);

    return max(node->val + ll + lr + rl + rr, l + r);
}