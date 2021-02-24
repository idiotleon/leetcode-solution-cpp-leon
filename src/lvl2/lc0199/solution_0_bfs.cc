// https://leetcode.com/problems/binary-tree-right-side-view/
//
// Time Complexity:     O()
// Space Complexity:    O()
#include <queue>
#include <vector>
#include "tree_node.h"

using namespace std;

class Solution
{
public:
    vector<int> RightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        queue<TreeNode *> queue;
        queue.push(root);

        while (!queue.empty())
        {
            const int kNodes = queue.size();

            for (int sz = 0; sz < kNodes; ++sz)
            {
                TreeNode *cur = queue.front();
                queue.pop();

                if (sz == kNodes - 1)
                    ans.push_back(cur->val);

                if (cur->left)
                    queue.push(cur->left);

                if (cur->right)
                    queue.push(cur->right);
            }
        }

        return ans;
    }
};