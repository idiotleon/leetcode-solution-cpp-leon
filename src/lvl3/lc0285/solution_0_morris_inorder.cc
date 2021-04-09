// https://leetcode.com/problems/inorder-successor-in-bst/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/inorder-successor-in-bst/discuss/72671/C++-O(h)-solution-in-one-pass/153988
//  https://leetcode.com/problems/inorder-successor-in-bst/discuss/72671/C%2B%2B-O(h)-solution-in-one-pass
#include "tree_node.h"

using namespace std;

class Solution
{
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        TreeNode *successor = nullptr, *cur = root;

        while (cur)
        {
            if (p->val < cur->val)
            {
                successor = cur;
                cur = cur->left;
            }
            else if (p->val >= cur->val)
                cur = cur->right;
        }

        return successor;
    }
};