// https://leetcode.com/problems/pacific-atlantic-water-flow/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/pacific-atlantic-water-flow/discuss/114904/C%2B%2B-DFS
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
    {
        vector<vector<int>> res;
        if (matrix.empty())
            return res;

        const int kRows = matrix.size(), kCols = matrix[0].size();
        vector<vector<int>> visited(kRows, vector<int>(kCols, 0));

        for (int row = 0; row < kRows; ++row)
        {
            dfs(row, 0, INT_MIN, 1, visited, matrix, res);
            dfs(row, kCols - 1, INT_MIN, 2, visited, matrix, res);
        }

        for (int col = 0; col < kCols; ++col)
        {
            dfs(0, col, INT_MIN, 1, visited, matrix, res);
            dfs(kRows - 1, col, INT_MIN, 2, visited, matrix, res);
        }

        return res;
    }

private:
    const int DIRS[5] = {0, -1, 0, 1, 0};

    void dfs(int row, int col, int prev, int prev_val, vector<vector<int>> &visited, vector<vector<int>> &matrix, vector<vector<int>> &res)
    {

        const int kRows = matrix.size(), kCols = matrix[0].size();

        if (row < 0 || row >= kRows || col < 0 || col >= kCols || matrix[row][col] < prev || (visited[row][col] & prev_val) == prev_val)
            return;

        visited[row][col] |= prev_val;
        if (visited[row][col] == 3)
        {
            res.push_back({row, col});
        }

        for (int d = 0; d < 4; ++d)
        {
            const int new_row = row + DIRS[d], new_col = col + DIRS[d + 1];
            dfs(new_row, new_col, matrix[row][col], visited[row][col], visited, matrix, res);
        }
    }
};