// https://leetcode.com/problems/brick-wall/
//
// Time Complexity:     O(`kRows` * `kCols`)
// Space Complexity:    O(`kRows` * `kCols`)
//
// Reference:
//  https://leetcode.com/problems/brick-wall/discuss/888577/IntuitionC%2B%2BWith-PicturesHashMapDetailed-ExplanationCommentsSolutionCode
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int leastBricks(vector<vector<int>> &wall)
    {
        const int kRows = wall.size();
        unordered_map<int, int> col_to_edges;

        int max_freq = 0;

        for (auto &row : wall)
        {
            const int kCols = row.size();
            int edge_freq = 0;

            for (int col = 0; col < kCols - 1; ++col)
            {
                edge_freq += row[col];

                ++col_to_edges[edge_freq];

                max_freq = max(max_freq, col_to_edges[edge_freq]);
            }
        }

        return kRows - max_freq;
    }
};