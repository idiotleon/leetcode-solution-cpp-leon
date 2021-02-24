// https://leetcode.com/problems/trim-a-binary-search-tree/
//
// Time Complexity:     O(N)
// Space Complexity:    O(H)
//
// Reference:
//  https://leetcode.com/problems/trim-a-binary-search-tree/discuss/107046/C%2B%2B-recursion
#include <stdio.h>
#include "tree_node.h"

using namespace std;

class Solution
{
public:
    TreeNode *TrimBST(TreeNode *root, int low, int high)
    {
        if (root == NULL)
            return NULL;
        if (root->val < low)
            return trimBST(root->right, low, high);
        if (root->val > high)
            return trimBST(root->left, low, high);

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};