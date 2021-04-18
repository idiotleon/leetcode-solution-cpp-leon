// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
//
// Time Complexity:     O(`kRows` * (`kCols` ^ 2))
// Space Complexity:    O(`kRows` * `kCols`)
//
// Reference:
//  https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/discuss/303750/JavaC%2B%2BPython-Find-the-Subarray-with-Target-Sum
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        const int kRows = matrix.size(), kCols = matrix[0].size();

        for (int row = 0; row < kRows; ++row)
        {
            for (int col = 1; col < kCols; ++col)
            {
                matrix[row][col] += matrix[row][col - 1];
            }
        }

        int count = 0;
        unordered_map<int, int> sum_to_freq;
        for (int lo = 0; lo < kCols; ++lo)
        {
            for (int hi = lo; hi < kCols; ++hi)
            {
                sum_to_freq = {{0, 1}};

                int sum = 0;
                for (int row = 0; row < kRows; ++row)
                {
                    sum += matrix[row][hi] - (lo > 0 ? matrix[row][lo - 1] : 0);
                    const int kExpected = sum - target;
                    count += sum_to_freq.find(kExpected) != sum_to_freq.end() ? sum_to_freq[kExpected] : 0;
                    ++sum_to_freq[sum];
                }
            }
        }

        return count;
    }
};