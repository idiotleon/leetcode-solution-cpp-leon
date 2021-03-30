// https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/discuss/214216/JavaC%2B%2BPython-DFS-Solution
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
        return dfs(root, voyage, idx, ans) ? ans : vector<int>{-1};
    }

private:
    bool dfs(TreeNode *node, vector<int> &voyage, int &idx, vector<int> &res)
    {
        if (!node)
            return true;

        if (node->val != voyage[idx++])
            return false;

        if (node->left && node->left->val != voyage[idx])
        {
            res.push_back(node->val);
            return dfs(node->right, voyage, idx, res) && dfs(node->left, voyage, idx, res);
        }

        return dfs(node->left, voyage, idx, res) && dfs(node->right, voyage, idx, res);
    }
};