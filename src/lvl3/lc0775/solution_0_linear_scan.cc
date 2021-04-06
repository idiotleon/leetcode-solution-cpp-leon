// https://leetcode.com/problems/global-and-local-inversions/
//
// Time Complexity:     O(`kSize`)
// Space Complexity:    O(1)
//
// Reference:
//  https://leetcode.com/problems/global-and-local-inversions/discuss/113644/C%2B%2BJavaPython-Easy-and-Concise-Solution
#include <vector>

using namespace std;

class Solution
{
public:
    bool isIdealPermutation(vector<int> &nums)
    {
        const int kSize = nums.size();

        for (int i = 0; i < kSize; ++i)
            if (abs(nums[i] - i) > 1)
                return false;

        return true;
    }
};