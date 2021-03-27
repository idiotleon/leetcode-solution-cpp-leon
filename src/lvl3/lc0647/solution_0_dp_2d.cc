// https://leetcode.com/problems/palindromic-substrings/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/palindromic-substrings/discuss/258917/Java-Simple-Code%3A-DP-short
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int CountSubstrings(string str)
    {
        const int kSize = str.size();
        int count = 0;
        vector<vector<int>> dp(kSize, vector<int>(kSize, 0));

        for (int len = 0; len < kSize; ++len)
        {
            for (int lo = 0; lo < kSize - len; ++lo)
            {
                int hi = lo + len;

                if (str[lo] == str[hi])
                {
                    dp[lo][hi] = (hi - lo + 1 <= 3) ? true : dp[lo + 1][hi - 1];

                    if (dp[lo][hi])
                        ++count;
                }
            }
        }

        return count;
    }
};