// https://leetcode.com/problems/set-mismatch/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/set-mismatch/discuss/105507/Java-O(n)-Time-O(1)-Space/108115
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        const int kSize = nums.size();
        int correctSum = (kSize * (2 + kSize - 1)) / 2;
        int actualSum = 0;
        int badNum = 0;

        for (int &num : nums)
        {
            nums[abs(num) - 1] *= -1;
            if (nums[abs(num) - 1] > 0)
            {
                badNum = abs(num);
            }

            actualSum += abs(num);
        }

        return {badNum, correctSum - (actualSum - badNum)};
    }
};