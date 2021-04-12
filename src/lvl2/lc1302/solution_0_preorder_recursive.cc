// @author: Leon
// https://leetcode.com/problems/deepest-leaves-sum/
//
// Time Complexity:     O(N)
// Space Complexity:    O(H)
#include "tree_node.h"

using namespace std;

class Solution
{
public:
    int DeepestLeavesSum(TreeNode *root)
    {
        if (!root)
            return 0;

        if (IsLeaf(root))
            return root->val;

        int deepest = 0, sum = 0;
        Preorder(root, 0, deepest, sum);
        return sum;
    }

private:
    void Preorder(TreeNode *node, int cur_depth, int &deepest, int &sum)
    {
        if (!node)
            return;

        if (cur_depth > deepest)
        {
            deepest = cur_depth;
            sum = 0;
        }

        if (IsLeaf(node) && cur_depth == deepest)
        {
            sum += node->val;
        }

        Preorder(node->left, 1 + cur_depth, deepest, sum);
        Preorder(node->right, 1 + cur_depth, deepest, sum);
    }

    bool IsLeaf(TreeNode *node)
    {
        if (!node)
            return false;

        return !node->left && !node->right;
    }
};