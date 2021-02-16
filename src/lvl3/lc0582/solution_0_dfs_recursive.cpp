// https://leetcode.com/problems/kill-process/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/kill-process/discuss/103131/C%2B%2B-Clean-Code-2-Solution-DFS-and-BFS
#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill)
    {
        auto graph = build_graph(pid, ppid);

        vector<int> killed;
        dfs(kill, killed, graph);

        return killed;
    }

private:
    void dfs(int cur_id, vector<int> &killed, map<int, set<int>> &graph)
    {
        killed.push_back(cur_id);

        for (int next_id : graph[cur_id])
        {
            dfs(next_id, killed, graph);
        }
    }

    map<int, set<int>> build_graph(vector<int> &pid, vector<int> &ppid)
    {
        const int nIds = pid.size();

        vector<int> killed;
        map<int, set<int>> graph;

        for (int i = 0; i < nIds; ++i)
        {
            graph[ppid[i]].insert(pid[i]);
        }

        return graph;
    }
};