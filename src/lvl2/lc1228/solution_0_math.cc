// @author: Leon
// https://leetcode.com/problems/missing-number-in-arithmetic-progression/
//
// Time Complexity:     O(`kNums`)
// Space Complexity:    O(1)
#include <vector>

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        const int kNums = nums.size();

        const int kExpected = (kNums + 1) * (nums[0] + nums.back()) / 2;

        int sum = 0;
        for (int num : nums)
        {
            sum += num;
        }

        return kExpected - sum;
    }
};