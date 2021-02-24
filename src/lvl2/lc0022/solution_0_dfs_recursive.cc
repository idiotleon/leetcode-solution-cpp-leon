// @author: Leon
// https://leetcode.com/problems/generate-parentheses/
//
// Time Complexity:     O()
// Space Complexity:    O()
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> GenerateParenthesis(int n)
    {
        vector<string> ans;

        Dfs("", 0, 0, n, ans);

        return ans;
    }

private:
    void Dfs(string str, int cntOpen, int cntClosed, const int kN, vector<string> &res)
    {
        const int kLen = str.size();

        if (kLen == 2 * kN)
        {
            res.push_back(str);
            return;
        }

        if (cntOpen < kN)
        {
            Dfs(str + "(", 1 + cntOpen, cntClosed, kN, res);
        }

        if (cntClosed < cntOpen)
        {
            Dfs(str + ")", cntOpen, 1 + cntClosed, kN, res);
        }
    }
};
