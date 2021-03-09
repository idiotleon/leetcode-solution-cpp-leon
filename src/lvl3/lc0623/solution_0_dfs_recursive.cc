// https://leetcode.com/problems/add-one-row-to-tree/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/add-one-row-to-tree/discuss/104555/C%2B%2B-Java-10-line-Solution-no-helper
#include "tree_node.h"

using namespace std;

class Solution
{
public:
    TreeNode *addOneRow(TreeNode *root, int v, int d)
    {
        if (d == 0 || d == 1)
        {
            TreeNode *new_root = new TreeNode(v);
            (d ? new_root->left : new_root->right) = root;
            return new_root;
        }

        if (root && d >= 2)
        {
            root->left = addOneRow(root->left, v, d > 2 ? d - 1 : 1);
            root->right = addOneRow(root->right, v, d > 2 ? d - 1 : 0);
        }

        return root;
    }
};