// @author: Leon
// https://leetcode.com/problems/n-ary-tree-preorder-traversal/
//
// Time Complexity:     O(N)
// Space Complexity:    O(H)
#include <vector>
#include "node.h"

using namespace std;

class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> ans;

        preorder(root, ans);

        return ans;
    }

private:
    void preorder(Node *node, vector<int> &res)
    {
        if (!node)
            return;

        res.push_back(node->val);
        for (auto child : node->children)
        {
            preorder(child, res);
        }
    }
};