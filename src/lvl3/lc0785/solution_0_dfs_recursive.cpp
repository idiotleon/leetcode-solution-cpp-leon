// https://leetcode.com/problems/is-graph-bipartite/
//
// Time Complexity:     O(`kVertices`)
// Space Complexity:    O(`kVertices`)
//
// Reference:
//  https://leetcode.com/problems/is-graph-bipartite/discuss/409594/Clean-C%2B%2B-BFS-with-explanation-and-comments
#include <vector>

using namespace std;

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        const int kVertices = graph.size();
        vector<int> colors(kVertices, 0);
        for (int i = 0; i < kVertices; ++i)
        {
            if (colors[i])
                continue;

            if (!dfs(i, kColor, colors, graph))
                return false;
        }

        return true;
    }

private:
    const int kColor = 7;

    bool dfs(int cur, int expColor, vector<int> &colors, vector<vector<int>> &graph)
    {
        if (colors[cur])
        {
            return colors[cur] == expColor;
        }

        colors[cur] = expColor;

        for (int next : graph[cur])
        {
            if (!dfs(next, -expColor, colors, graph))
                return false;
        }

        return true;
    }
};