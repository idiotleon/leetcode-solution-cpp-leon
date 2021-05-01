// @author: Leon
// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
//
// Time Complexity:     O(V + E)
// Space Complexity:    O(V + E)
#include <queue>
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
            BFS(i, visited, graph);
            ++count;
        }

        return count;
    }

private:
    void BFS(int start, vector<int> &visited, vector<vector<int>> &graph)
    {
        queue<int> queue;
        queue.push(start);

        while (!queue.empty())
        {
            const int kSize = queue.size();

            for (int sz = 0; sz < kSize; ++sz)
            {
                int cur = queue.front();
                queue.pop();

                visited[cur] = 1;

                for (int next : graph[cur])
                {
                    if (visited[next])
                        continue;
                    queue.push(next);
                }
            }
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