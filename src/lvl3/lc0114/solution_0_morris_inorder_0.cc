// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
//
// Time Complexity:     O(N)
// Space Complexity:    O(1)
//
// Reference:
//  https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/37000/8ms-Non-recursive-No-stack-C++-solution/35120
//  https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/37010/Share-my-simple-NON-recursive-solution-O(1)-space-complexity!/35136
#include <cstddef>
#include "tree_node.h"

using namespace std;

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        TreeNode *cur = root;

        while (cur)
        {
            if (cur->left)
            {
                TreeNode *predecessor = cur->left;
                while (predecessor->right)
                    predecessor = predecessor->right;

                predecessor->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }

            cur = cur->right;
        }
    }
};