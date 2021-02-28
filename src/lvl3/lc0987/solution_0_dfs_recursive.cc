// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// References:
//  https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/discuss/260502/C%2B%2B-BFSDFS
#include <map>
#include <set>
#include <vector>
#include "tree_node.h"

using namespace std;

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> nodes;

        dfs(root, 0, 0, nodes);
        vector<vector<int>> ans;
        for (auto p : nodes)
        {
            vector<int> col;
            for (auto q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }

private:
    void dfs(TreeNode *root, int x, int y, map<int, map<int, multiset<int>>> &nodes)
    {
        if (root)
        {
            nodes[x][y].insert(root->val);
            dfs(root->left, x - 1, y + 1, nodes);
            dfs(root->right, x + 1, y + 1, nodes);
        }
    }
};