// @author: Leon
// https://leetcode.com/problems/path-sum/
//
// Time Complexity:     O(N)
// Space Complexity:    O(H)
#include "tree_node.h"

using namespace std;

class Solution
{
public:
    bool hasPathSum(TreeNode *root, int target_sum)
    {
        return DFS(root, target_sum);
    }

private:
    bool DFS(TreeNode *node, int target_sum)
    {
        if (!node)
            return false;

        const int kVal = node->val;
        target_sum -= kVal;

        if (target_sum == 0)
        {
            if (!node->left && !node->right)
                return true;
        }

        return DFS(node->left, target_sum) || DFS(node->right, target_sum);
    }
};