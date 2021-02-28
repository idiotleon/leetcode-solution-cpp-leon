// https://leetcode.com/problems/shortest-path-in-binary-matrix/
//
// Time Complexity:     O()
// Space Complxity:     O()
//
// Reference:
//  https://leetcode.com/problems/shortest-path-in-binary-matrix/discuss/312711/C++-BFS/291171
//  https://leetcode.com/problems/shortest-path-in-binary-matrix/discuss/312711/C%2B%2B-BFS
#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        const int nRows = grid.size(), nCols = grid[0].size();
        int dirs[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        queue<pair<int, int>> queue;
        vector<vector<bool>> visited(nRows, vector<bool>(nCols, false));

        if (grid[0][0] == 1 || grid[nRows - 1][nCols - 1] == 1)
            return -1;

        queue.push(make_pair(0, 0));
        visited[0][0] = true;

        int steps = 1;

        while (!queue.empty())
        {
            const int nMoves = queue.size();

            for (int mv = 0; mv < nMoves; ++mv)
            {
                auto cur = queue.front();
                queue.pop();
                int row = cur.first, col = cur.second;

                if (row == nRows - 1 && col == nCols - 1)
                    return steps;

                for (int d = 0; d < 8; ++d)
                {
                    int next_row = row + dirs[d][0], next_col = col + dirs[d][1];

                    if (next_row < 0 || next_row >= nRows || next_col < 0 || next_col >= nCols || visited[next_row][next_col] || grid[next_row][next_col])
                        continue;

                    queue.push(make_pair(next_row, next_col));
                    visited[next_row][next_col] = true;
                }
            }

            ++steps;
        }

        return -1;
    }
};