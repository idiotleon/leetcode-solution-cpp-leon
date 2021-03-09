// https://leetcode.com/problems/largest-bst-subtree/
//
// Time Complexity:     O(N)
// Space Complexity:    O(H)
//
// Reference:
//  https://leetcode.com/problems/largest-bst-subtree/discuss/78892/12ms-C++-solution/276242
//  https://leetcode.com/problems/largest-bst-subtree/discuss/78892/12ms-C%2B%2B-solution
#include <algorithm>
#include <limits.h>
#include "tree_node.h"

using namespace std;

class Solution
{
public:
    int largestBSTSubtree(TreeNode *root)
    {
        int largest = 0, min_val = INT_MIN, max_val = INT_MAX;
        IsBST(root, largest, min_val, max_val);
        return largest;
    }

private:
    bool IsBST(TreeNode *node, int &largest, int &min_val, int &max_val)
    {
        if (!node)
            return true;

        int left_min_val = INT_MIN, left_max_val = INT_MAX, left_count = 0;
        bool left = IsBST(node->left, left_count, left_min_val, left_max_val);

        int right_min_val = INT_MIN, right_max_val = INT_MAX, right_count = 0;
        bool right = IsBST(node->right, right_count, right_min_val, right_max_val);

        if (left && right)
        {
            if ((!node->left || node->val > left_max_val) && (!node->right || node->val < right_min_val))
            {
                largest = 1 + left_count + right_count;
                min_val = node->left ? left_min_val : node->val;
                max_val = node->right ? right_max_val : node->val;
                return true;
            }
        }

        largest = max(left_count, right_count);
        return false;
    }
};