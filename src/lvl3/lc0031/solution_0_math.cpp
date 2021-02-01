// https://leetcode.com/problems/next-permutation/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// References:
//  https://leetcode.com/problems/next-permutation/discuss/13867/C%2B%2B-from-Wikipedia
#include <vector>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        const int nNums = nums.size();
        int k = 0, l = 0;
        for (k = nNums - 2; k >= 0; --k)
        {
            if (nums[k] < nums[k + 1])
            {
                break;
            }
        }

        if (k < 0)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            for (l = nNums - 1; l > k; --l)
            {
                if (nums[l] > nums[k])
                {
                    break;
                }
            }

            swap(nums[k], nums[l]);
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};