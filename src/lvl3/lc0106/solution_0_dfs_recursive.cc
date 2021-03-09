// @author: Leon
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
//
// Time Complexity:     O(N)
// Space Complexity:    O(H) + O(N) ~ O(N)
#include <unordered_map>
#include <vector>
#include "tree_node.h"

using namespace std;

class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        const int kSize = inorder.size();

        unordered_map<int, int> inorder_val_to_idx;
        for (int i = 0; i < kSize; ++i)
            inorder_val_to_idx[inorder[i]] = i;

        return dfs(kSize - 1, 0, kSize - 1, inorder, postorder, inorder_val_to_idx);
    }

private:
    TreeNode *dfs(
        int idx_postorder,
        int idx_start_inorder,
        int idx_end_inorder,
        vector<int> &inorder,
        vector<int> &postorder,
        unordered_map<int, int> &inorder_val_to_idx)
    {
        if (idx_postorder < 0 || idx_start_inorder > idx_end_inorder)
            return NULL;

        int root_val = postorder[idx_postorder];
        TreeNode *root = new TreeNode(root_val);

        int idx_root = inorder_val_to_idx[root_val];

        root->right = dfs(idx_postorder - 1, idx_root + 1, idx_end_inorder, inorder, postorder, inorder_val_to_idx);
        root->left = dfs(idx_postorder - (idx_end_inorder - idx_root + 1), idx_start_inorder, idx_root - 1, inorder, postorder, inorder_val_to_idx);

        return root;
    }
};