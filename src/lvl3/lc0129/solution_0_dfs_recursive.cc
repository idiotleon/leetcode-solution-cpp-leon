// @author: Leon
// https://leetcode.com/problems/sum-root-to-leaf-numbers/
//
// Time Complexity:     O(N)
// Space Complexity:    O(H)
#include "tree_node.h"

using namespace std;

class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode *node, int num)
    {
        if (!node)
            return 0;

        const int kVal = node->val;
        num = num * 10 + kVal;
        if (!node->left && !node->right)
            return num;

        int left_num = dfs(node->left, num);
        int right_num = dfs(node->right, num);

        return left_num + right_num;
    }
};