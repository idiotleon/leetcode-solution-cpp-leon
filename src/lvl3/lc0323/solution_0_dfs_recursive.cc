// @author: Leon
// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
//
// Time Complexity:     O(V + E)
// Space Complexity:    O(V + E)
#include <vector>

using namespace std;

class Solution
{
public:
    int CountComponents(int n, vector<vector<int>> &edges)
    {
        auto graph = BuildGraph(n, edges);
        vector<int> visited(n, 0);

        int count = 0;

        for (int i = 0; i < n; ++i)
        {
            if (visited[i])
                continue;
            DFS(i, visited, graph);
            ++count;
        }

        return count;
    }

private:
    void DFS(int cur, vector<int> &visited, vector<vector<int>> &graph)
    {
        if (visited[cur])
            return;

        visited[cur] = 1;

        for (int next : graph[cur])
        {
            DFS(next, visited, graph);
        }
    }

    vector<vector<int>> BuildGraph(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> graph(n, vector<int>());

        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        return graph;
    }
};