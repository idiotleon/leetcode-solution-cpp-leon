// https://leetcode.com/problems/rotate-image/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/rotate-image/discuss/19002/4ms-few-lines-C%2B%2B-code-Rotate-Image-90-degree-for-O(1)-space
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        const int kRows = matrix.size();
        int lo = 0, hi = kRows - 1;
        while (lo < hi)
        {
            for (int i = 0; i < hi - lo; ++i)
            {
                swap(matrix[lo][lo + i], matrix[lo + i][hi]);
                swap(matrix[lo][lo + i], matrix[hi][hi - i]);
                swap(matrix[lo][lo + i], matrix[hi - i][lo]);
            }

            ++lo;
            --hi;
        }
    }
};