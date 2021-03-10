// https://leetcode.com/problems/diameter-of-binary-tree/
//
// Time Complexity:     O(N)
// Space Complexity:    O(H)
//
// Reference:
//  https://leetcode.com/problems/diameter-of-binary-tree/discuss/573591/C%2B%2B-5-lines-O(n)-solution
#include <algorithm>
#include "tree_node.h"

using namespace std;

class Solution
{
public:
    int GetMaxDiameterOfBinaryTree(TreeNode *root)
    {
        int deepest = 0;
        DFS(root, deepest);
        return deepest;
    }

private:
    // postorder
    int DFS(TreeNode *node, int &deepest)
    {
        if (!node)
            return 0;

        int left = DFS(node->left, deepest);
        int right = DFS(node->right, deepest);

        deepest = max(deepest, left + right);
        return 1 + max(left, right);
    }
};