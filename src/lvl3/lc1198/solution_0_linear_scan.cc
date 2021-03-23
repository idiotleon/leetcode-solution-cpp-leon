// https://leetcode.com/problems/find-smallest-common-element-in-all-rows/
//
// Time Complexity:     O(`kRows` * `kCols`)
// Space Complexity:    O(`kRange`)
//
// Reference:
//  https://leetcode.com/problems/find-smallest-common-element-in-all-rows/discuss/387092/JavaC%2B%2BPython-Brute-Force-Count
#include <vector>

using namespace std;

class Solution
{
public:
    int smallestCommonElement(vector<vector<int>> &matrix)
    {
        const int kRows = matrix.size(), kCols = matrix[0].size();
        vector<int> count(kRange);

        for (int col = 0; col < kCols; ++col)
        {
            for (int row = 0; row < kRows; ++row)
            {
                if (++count[matrix[row][col]] == kRows)
                    return matrix[row][col];
            }
        }

        return -1;
    }

private:
    constexpr static int kRange = (int)1e4 + 7;
};