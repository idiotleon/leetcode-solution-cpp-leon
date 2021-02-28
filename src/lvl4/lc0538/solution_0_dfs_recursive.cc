// https://leetcode.com/problems/convert-bst-to-greater-tree/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/convert-bst-to-greater-tree/discuss/100610/c%2B%2B-solution-beats-100
#include "../../util/data_structure/tree_node.h"

using namespace std;

class Solution
{
public:
    TreeNode *convertBST(TreeNode *root)
    {
        dfs(root);
        return root;
    }

    void dfs(TreeNode *node)
    {
        if (!node)
            return;
        if (node->right)
            dfs(node->right);

        node->val = (cur_sum += node->val);
        if (node->left)
            dfs(node->left);
    }

private:
    int cur_sum = 0;
};