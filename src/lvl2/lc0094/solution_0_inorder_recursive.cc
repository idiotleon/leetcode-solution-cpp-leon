// @author: Leon
// https://leetcode.com/problems/binary-tree-inorder-traversal/
//
// Time Complexity:     O(N)
// Space Complexity:    O(H)
#include <vector>
#include "tree_node.h"

using namespace std;

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        inorder(root, ans);

        return ans;
    }

private:
    void inorder(TreeNode *node, vector<int> &res)
    {
        if (!node)
            return;

        inorder(node->left, res);
        res.push_back(node->val);
        inorder(node->right, res);
    }
};