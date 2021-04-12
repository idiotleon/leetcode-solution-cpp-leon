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
        Postorder(root, 0, deepest, sum);
        return sum;
    }

private:
    void Postorder(TreeNode *node, int cur_depth, int &deepest, int &sum)
    {
        if (!node)
            return;

        Postorder(node->left, 1 + cur_depth, deepest, sum);
        Postorder(node->right, 1 + cur_depth, deepest, sum);

        if (deepest < cur_depth)
        {
            deepest = cur_depth;
            sum = 0;
        }

        if (deepest == cur_depth)
        {
            sum += node->val;
        }
    }

    bool IsLeaf(TreeNode *node)
    {
        if (!node)
            return false;

        return !node->left && !node->right;
    }
};