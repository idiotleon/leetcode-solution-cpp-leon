// https://leetcode.com/problems/longest-palindromic-substring/
//
// Time Complexity:		O(`len(s)` ^ 2)
// Space Complexity:	O(`len(s)` ^ 2)
//
// References:
//	https://leetcode.com/problems/longest-palindromic-substring/discuss/2921/Share-my-Java-solution-using-dynamic-programming/3570
//	https://leetcode.com/problems/longest-palindromic-substring/discuss/2921/Share-my-Java-solution-using-dynamic-programming/223961
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string str)
    {
        const int len_str = str.length();
        int idx_start = 0, idx_end = 0;

        vector<vector<bool>> dp(len_str, vector<bool>(len_str, false));

        for (int lo = len_str - 1; lo >= 0; --lo)
        {
            for (int hi = lo; hi < len_str; ++hi)
            {
                dp[lo][hi] = str[lo] == str[hi] && (hi - lo < 2 || dp[lo + 1][hi - 1]);

                if (dp[lo][hi] && hi - lo > idx_end - idx_start)
                {
                    idx_start = lo;
                    idx_end = hi;
                }
            }
        }

        return len_str == 0 ? "" : str.substr(idx_start, idx_end - idx_start + 1);
    }
};