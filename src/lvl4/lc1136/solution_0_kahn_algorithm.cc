// https://leetcode.com/problems/parallel-courses/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/parallel-courses/discuss/345015/C++-dfs-15-line-and-bfs-15-line/891356
//  https://leetcode.com/problems/parallel-courses/discuss/345015/C%2B%2B-dfs-15-line-and-bfs-15-line
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    int minimumSemesters(const int kCourses, vector<vector<int>> &relations)
    {
        vector<int> indegrees(1 + kCourses, 0);
        vector<unordered_set<int>> graph(1 + kCourses, unordered_set<int>());
        for (auto &edge : relations)
        {
            int u = edge[0], v = edge[1];
            graph[u].insert(v);
            ++indegrees[v];
        }

        int cntCourse = 0, level = 0;

        queue<int> queue;
        for (int i = 1; i <= kCourses; ++i)
        {
            if (indegrees[i] == 0)
            {
                queue.push(i);
                ++cntCourse;
            }
        }

        while (!queue.empty())
        {
            const int kSize = queue.size();

            for (int sz = 0; sz < kSize; ++sz)
            {
                auto cur = queue.front();
                queue.pop();

                for (auto next : graph[cur])
                {
                    if (--indegrees[next] == 0)
                    {
                        queue.push(next);
                        ++cntCourse;
                    }
                }
            }

            ++level;
        }

        return kCourses == cntCourse ? level : -1;
    }
};