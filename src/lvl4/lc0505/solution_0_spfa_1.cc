// https://leetcode.com/problems/the-maze-ii/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
    {
        const int n_rows = maze.size(), n_cols = maze[0].size();
        if (n_rows == 0 || n_cols == 0)
            return -1;

        vector<vector<int>> distances(n_rows, vector<int>(n_cols, -1));
        distances[start[0]][start[1]] = 0;

        queue<pair<int, int>> queue;
        queue.push({start[0], start[1]});

        while (!queue.empty())
        {
            auto cur = queue.front();
            queue.pop();

            int cur_row = cur.first, cur_col = cur.second;
            // cannot be commented out
            // if(cur_row == destination[0] && cur_col == destination[1]) break;

            for (int d = 0; d < 4; ++d)
            {
                int next_row = cur_row, next_col = cur_col, distance = distances[cur_row][cur_col];

                while (IsValid(next_row + kDirs[d], next_col + kDirs[d + 1], maze))
                {
                    next_row += kDirs[d];
                    next_col += kDirs[d + 1];
                    ++distance;
                }

                if (distances[next_row][next_col] == -1 || distance < distances[next_row][next_col])
                {
                    distances[next_row][next_col] = distance;
                    queue.push({next_row, next_col});
                }
            }
        }

        return distances[destination[0]][destination[1]];
    }

private:
    static const int EMPTY = 0;
    const int kDirs[5] = {0, -1, 0, 1, 0};

    bool IsValid(int row, int col, vector<vector<int>> &maze)
    {
        const int kRows = maze.size(), kCols = maze[0].size();

        return row >= 0 && row < kRows && col >= 0 && col < kCols && maze[row][col] == EMPTY;
    }
};