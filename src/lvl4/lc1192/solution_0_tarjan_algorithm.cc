// https://leetcode.com/problems/critical-connections-in-a-network/
//
// Time Complexity:     O(V + E)
// Space Complexity:    O(V + E)
//
// Reference:
//  https://leetcode.com/problems/critical-connections-in-a-network/discuss/784221/Tarjan's-Algorithms-will-be-a-child's-play-if-you-read-this-or-C%2B%2B-implementation.
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> graph = build_graph(n, connections);
        vector<vector<int>> ans;
        vector<int> parents(n, -1), disc(n, -1), low(n, -1);

        int time = 0;

        for (int i = 0; i < n; ++i)
        {
            if (disc[i] == -1)
                dfs(i, time, disc, parents, low, graph, ans);
        }

        return ans;
    }

private:
    void dfs(int cur,
             int &time,
             vector<int> &disc,
             vector<int> &parents,
             vector<int> &low,
             vector<vector<int>> &graph,
             vector<vector<int>> &res)
    {
        disc[cur] = low[cur] = time++;

        for (int next : graph[cur])
        {
            if (disc[next] == -1)
            {
                parents[next] = cur;
                dfs(next, time, disc, parents, low, graph, res);

                if (low[next] > disc[cur])
                    res.push_back({cur, next});

                low[cur] = min(low[cur], low[next]);
            }
            else if (next != parents[cur])
            {
                low[cur] = min(low[cur], low[next]);
            }
        }
    }

    vector<vector<int>> build_graph(const int kVertices, vector<vector<int>> &connections)
    {
        vector<vector<int>> graph(kVertices);

        for (auto &conn : connections)
        {
            int u = conn[0], v = conn[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        return graph;
    }
};