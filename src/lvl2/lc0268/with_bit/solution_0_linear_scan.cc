// https://leetcode.com/problems/missing-number/
//
// Time Complexity:     O(`kSize`)
// Space Complexity:    O(1)
//
// Reference:
//  https://leetcode.com/problems/missing-number/discuss/69777/C%2B%2B-solution-using-bit-manipulation
#include <vector>

using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        const int kSize = nums.size();
        int ans = kSize;

        int idx = 0;

        for (int &num : nums)
        {
            ans ^= num;
            ans ^= idx;
            ++idx;
        }

        return ans;
    }
};