// https://leetcode.com/problems/average-of-levels-in-binary-tree/
//
// Time Complexity:     O(N)
// Space Complexity:    O(W)
//
// Reference:
//  https://leetcode.com/problems/average-of-levels-in-binary-tree/discuss/105178/C%2B%2B-simple-and-clear-BFS-solution
#include <queue>
#include <vector>
#include "tree_node.h"

using namespace std;

class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> ans;

        queue<TreeNode *> queue;
        queue.push(root);

        while (!queue.empty())
        {
            const int kSize = queue.size();

            double sum = 0;

            for (int sz = 0; sz < kSize; ++sz)
            {
                TreeNode *cur = queue.front();
                queue.pop();

                sum += cur->val;

                if (cur->left)
                    queue.push(cur->left);
                if (cur->right)
                    queue.push(cur->right);
            }

            ans.push_back(sum / kSize);
        }

        return ans;
    }
};