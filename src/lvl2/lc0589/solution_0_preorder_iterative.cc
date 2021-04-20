// @author: Leon
// https://leetcode.com/problems/n-ary-tree-preorder-traversal/
//
// Time Complexity:     O(N)
// Space Complexity:    O(H)
#include <stack>
#include <vector>
#include "node.h"

using namespace std;

class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;

        stack<Node *> stk;
        stk.push(root);

        while (!stk.empty())
        {
            auto top = stk.top();
            stk.pop();

            ans.push_back(top->val);

            const int kSize = top->children.size();

            for (int i = kSize - 1; i >= 0; --i)
            {
                stk.push(top->children[i]);
            }
        }

        return ans;
    }
};