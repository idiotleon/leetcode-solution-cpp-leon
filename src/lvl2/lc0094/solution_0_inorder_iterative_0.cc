// @author: Leon
// https://leetcode.com/problems/binary-tree-inorder-traversal/
//
// Time Complexity:     O()
// Space Complexity:    O()
#include <stack>
#include <vector>
#include "tree_node.h"

using namespace std;

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        stack<TreeNode *> stack;
        push_left(root, stack);

        while (!stack.empty())
        {
            auto &top = stack.top();
            stack.pop();
            ans.push_back(top->val);
            push_left(top->right, stack);
        }

        return ans;
    }

private:
    void push_left(TreeNode *node, stack<TreeNode *> &stack)
    {
        while (node)
        {
            stack.push(node);
            node = node->left;
        }
    }
};