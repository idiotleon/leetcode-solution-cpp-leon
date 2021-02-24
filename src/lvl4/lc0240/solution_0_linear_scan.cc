// https://leetcode.com/problems/search-a-2d-matrix-ii/
//
// Time Complexity:     O(`kRows` + `kCols`)
// Space Complexity:    O(1)
//
// Reference:
//  https://leetcode.com/problems/search-a-2d-matrix-ii/discuss/66139/C%2B%2B-search-from-top-right
#include <vector>

using namespace std;

class Solution
{
public:
    bool SearchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty())
            return false;
        const int kRows = matrix.size(), kCols = matrix[0].size();

        int row = 0, col = kCols - 1;

        while (row < kRows && col >= 0)
        {
            if (matrix[row][col] == target)
            {
                return true;
            }

            matrix[row][col] > target ? --col : ++row;
        }

        return false;
    }
};