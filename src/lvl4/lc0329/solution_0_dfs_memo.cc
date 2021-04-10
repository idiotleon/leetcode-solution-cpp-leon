#include <vector>

using namespace std;

class Solution
{
public:
    int LongestIncreasingPath(vector<vector<int>> &matrix)
    {
        const int kRows = matrix.size(), kCols = matrix[0].size();

        vector<vector<int>> memo(kRows, vector<int>(kCols, 1));

        int longest = 1;
        for (int row = 0; row < kRows; ++row)
        {
            for (int col = 0; col < kCols; ++col)
            {
                longest = max(longest, DFS(row, col, matrix, memo));
            }
        }

        return longest;
    }

private:
    const vector<int> kDirs = {0, -1, 0, 1, 0};

    int DFS(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &memo)
    {
        const int kRows = matrix.size(), kCols = matrix[0].size();

        if (memo[row][col] > 1)
            return memo[row][col];

        int longest = 1;
        for (int d = 0; d < 4; ++d)
        {
            int next_row = row + kDirs[d], next_col = col + kDirs[d + 1];
            if (next_row < 0 || next_row >= kRows || next_col < 0 || next_col >= kCols || matrix[next_row][next_col] <= matrix[row][col])
                continue;
            longest = max(longest, 1 + DFS(next_row, next_col, matrix, memo));
        }

        memo[row][col] = longest;
        return longest;
    }
};