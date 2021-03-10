// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
//
// Time Complexity:     O(N)
// Space Complexity:    O(H)
//
// Reference:
//  https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/36977/My-short-post-order-traversal-Java-solution-for-share/150699
//  https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/36977/My-short-post-order-traversal-Java-solution-for-share/146292
//  https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/36977/My-short-post-order-traversal-Java-solution-for-share
#include <cstddef>
#include "tree_node.h"

using namespace std;

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        DFS(root, NULL);
    }

private:
    // (reverse) postorder
    TreeNode *DFS(TreeNode *node, TreeNode *prev)
    {
        if (!node)
            return prev;

        prev = DFS(node->right, prev);
        prev = DFS(node->left, prev);
        node->right = prev;
        node->left = NULL;
        prev = node;
        return prev;
    }
};