// https://leetcode.com/problems/maximum-length-of-repeated-subarray/
//
// Time Complexity:     O(`kSize1` * `kSize2`)
// Space Complexity:    O(`kSize1` * `kSize2`)
//
// Reference:
//  https://leetcode.com/problems/maximum-length-of-repeated-subarray/discuss/109068/JavaC++-Clean-Code-8-lines/173006
//  https://leetcode.com/problems/maximum-length-of-repeated-subarray/discuss/109068/JavaC%2B%2B-Clean-Code-8-lines
//  https://blog.csdn.net/txl199106/article/details/45869557
#include <vector>

using namespace std;

class Solution
{
public:
    int FindLength(vector<int> &nums1, vector<int> &nums2)
    {
        const int kSize1 = nums1.size(), kSize2 = nums2.size();
        if (!kSize1 || !kSize2)
            return 0;

        vector<vector<int>> dp(kSize1 + 1, vector<int>(kSize2 + 1, 0));

        int longest = 0;

        for (int idx1 = kSize1 - 1; idx1 >= 0; --idx1)
        {
            for (int idx2 = kSize2 - 1; idx2 >= 0; --idx2)
            {
                longest = max(longest, dp[idx1][idx2] = nums1[idx1] == nums2[idx2] ? 1 + dp[idx1 + 1][idx2 + 1] : 0);
            }
        }

        return longest;
    }
};