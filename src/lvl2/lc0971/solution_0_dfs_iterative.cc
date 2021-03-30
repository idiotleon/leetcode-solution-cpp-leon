// https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/discuss/214384/JavaC++Python-Iterative-Solution-Using-Stack
#include <stack>
#include <vector>
#include "tree_node.h"

using namespace std;

class Solution
{
public:
    vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage)
    {
        vector<int> ans;

        int idx = 0;
        stack<TreeNode *> stack;
        stack.push(root);

        while (!stack.empty())
        {
            TreeNode *node = stack.top();
            stack.pop();

            if (!node)
                continue;

            if (node->val != voyage[idx++])
                return vector<int>{-1};

            if (node->right && node->right->val == voyage[idx])
            {
                if (node->left)
                    ans.push_back(node->val);

                stack.push(node->left);
                stack.push(node->right);
            }
            else
            {
                stack.push(node->right);
                stack.push(node->left);
            }
        }

        return ans;
    }
};