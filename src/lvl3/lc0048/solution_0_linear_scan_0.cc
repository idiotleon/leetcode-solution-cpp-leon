// https://leetcode.com/problems/rotate-image/
//
// Time Complexity:     O(`kRows` * `kCols`)
// Space Complexity:    O(1)
//
// Reference:
//  https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        const int kRows = matrix.size();
        reverse(matrix.begin(), matrix.end());

        for (int row = 0; row < kRows; ++row)
        {
            const int kCols = matrix[0].size();
            for (int col = 1 + row; col < kCols; ++col)
            {
                swap(matrix[row][col], matrix[col][row]);
            }
        }
    }
};