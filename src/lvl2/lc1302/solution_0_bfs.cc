// @author: Leon
// https://leetcode.com/problems/deepest-leaves-sum/
//
// Time Complexity:     O(N)
// Space Complexity:    O(W)
#include <queue>
#include "tree_node.h"

using namespace std;

class Solution
{
public:
    int deepestLeavesSum(TreeNode *root)
    {
        queue<TreeNode *> queue;
        queue.push(root);

        int deepest = 0, sum = 0, level = 0;

        while (!queue.empty())
        {
            const int kSize = queue.size();
            sum = 0;

            for (int sz = 0; sz < kSize; ++sz)
            {
                auto cur = queue.front();
                queue.pop();

                sum += cur->val;

                if (cur->left)
                    queue.push(cur->left);

                if (cur->right)
                    queue.push(cur->right);
            }
        }

        return sum;
    }
};