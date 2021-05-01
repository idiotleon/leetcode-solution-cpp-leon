// @author: Leon
// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
//
// Time Complexity:     O(`n`)
// Space Complexity:    O(`n`)
#include <vector>

using namespace std;

class Solution
{
public:
    int CountComponents(int n, vector<vector<int>> &edges)
    {
        vector<int> roots(n + 1, 0);
        vector<int> ranks(n + 1, 0);
        for (int i = 0; i <= n; ++i)
        {
            roots[i] = i;
            ranks[i] = 1;
        }

        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1];
            Union(v, u, roots, ranks, n);
        }

        return n;
    }

private:
    int Find(int x, vector<int> &roots)
    {
        while (roots[x] != x)
        {
            roots[x] = roots[roots[x]];
            x = roots[x];
        }

        return x;
    }

    void Union(int x, int y, vector<int> &roots, vector<int> &ranks, int &n)
    {
        int root_x = Find(x, roots), root_y = Find(y, roots);

        if (root_x == root_y)
            return;

        if (ranks[root_x] > ranks[root_y])
        {
            roots[root_y] = root_x;
            ++ranks[root_x];
        }
        else
        {
            roots[root_x] = root_y;
            ++ranks[root_y];
        }

        --n;
    }
};