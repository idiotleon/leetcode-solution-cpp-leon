// https://leetcode.com/problems/search-a-2d-matrix-ii/
//
// Time Complexity:     O(`kRows` * lg(`kCols`))
// Space Complexity:    O(1)
//
// Reference:
//  https://leetcode.com/problems/search-a-2d-matrix-ii/discuss/66163/C%2B%2B-two-solutions-(O(m%2Bn)-O(mlogn))
#include <vector>

using namespace std;

class Solution
{
public:
    bool SearchMatrix(vector<vector<int>> &matrix, int target)
    {
        const int kRows = matrix.size();
        return SearchMatrix(0, kRows - 1, target, matrix);
    }

private:
    bool SearchMatrix(int top, int bottom, int target, vector<vector<int>> &matrix)
    {
        if (top > bottom)
            return false;

        int mid = top + (bottom - top) / 2;
        if (matrix[mid].front() <= target && target <= matrix[mid].back())
        {
            if (BinarySearch(matrix[mid], target))
                return true;
        }

        if (SearchMatrix(top, mid - 1, target, matrix))
            return true;
        if (SearchMatrix(mid + 1, bottom, target, matrix))
            return true;

        return false;
    }

    bool BinarySearch(vector<int> &nums, int target)
    {
        const int kNums = nums.size();
        int lo = 0, hi = kNums - 1;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] == target)
                return true;

            if (nums[mid] < target)
            {
                lo = 1 + mid;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return false;
    }
};