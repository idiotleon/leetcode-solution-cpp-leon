// @author: Leon
// https://leetcode.com/problems/longest-common-subsequence/
//
// Time Complexity:     O(`kLen1` * `kLen2`)
// Space Complexity:    O(`kLen1` * `kLen2`) + O(max(`kLen1`, `kLen2`))
//
// References:
//  https://leetcode.com/problems/longest-common-subsequence/discuss/398711/ALL-4-ways-Recursion-greater-Top-down-greaterBottom-Up-greater-Efficient-Solution-O(N)-including-VIDEO-TUTORIAL
//  https://leetcode.com/problems/longest-common-subsequence/discuss/348884/C%2B%2B-with-picture-O(nm)
//  https://leetcode.com/problems/longest-common-subsequence/discuss/841563/Java-Recursion-greater-memo-greater-dp
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int LongestCommonSubsequence(string text1, string text2)
    {
        const int kLen1 = text1.size(), kLen2 = text2.size();

        vector<vector<int>> memo(kLen1 + 1, vector<int>(kLen2 + 1, 0));

        return DFS(0, 0, text1, text2, memo);
    }

private:
    int DFS(int idx1, int idx2, string &text1, string &text2, vector<vector<int>> &memo)
    {
        const int kLen1 = text1.size(), kLen2 = text2.size();
        if (idx1 >= kLen1 || idx2 >= kLen2)
            return 0;

        if (memo[idx1][idx2] > 0)
            return memo[idx1][idx2];

        int longest = 0;
        if (text1[idx1] == text2[idx2])
            longest = max(longest, 1 + DFS(1 + idx1, 1 + idx2, text1, text2, memo));
        else
            longest = max(DFS(1 + idx1, idx2, text1, text2, memo),
                          DFS(idx1, 1 + idx2, text1, text2, memo));

        memo[idx1][idx2] = longest;
        return longest;
    }
};