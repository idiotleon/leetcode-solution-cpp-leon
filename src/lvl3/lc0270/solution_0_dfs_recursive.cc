// https://leetcode.com/problems/closest-binary-search-tree-value/
//
// Time Complexity:     O(H)
// Space Complexity:    O(H)
//
// Please pay attentions to the types of `kTarget`, `closed_val`, which should be `double`.
//  If one puts them as `int`, answers will NOT be correct due to (integer) truncation.
//
// Reference:
//  https://youtu.be/DpkTu2tU87o?t=383
#include <cstdlib>
#include <float.h>
#include "tree_node.h"

using namespace std;

class Solution
{
public:
    int closestValue(TreeNode *root, double target)
    {
        double closed_val = DBL_MAX;
        int closed_num = 0;
        dfs(root, target, closed_val, closed_num);
        return closed_num;
    }

private:
    void dfs(TreeNode *node, const double kTarget, double &closed_val, int &closed_num)
    {
        if (!node)
            return;

        const int kVal = node->val;
        if (abs(kVal - kTarget) < closed_val)
        {
            closed_val = abs(kVal - kTarget);
            closed_num = kVal;
        }

        if (kVal > kTarget)
            dfs(node->left, kTarget, closed_val, closed_num);
        else
            dfs(node->right, kTarget, closed_val, closed_num);
    }
};