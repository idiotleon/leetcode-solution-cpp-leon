// https://leetcode.com/problems/letter-case-permutation/
//
// Time Complexity:     O(2 ^ `kLen`)
// Space Complexity:    O(`kLen`)
//
// Reference:
//  https://leetcode.com/problems/letter-case-permutation/discuss/115515/C++-backtrack-solution-w-trick/117625
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> LetterCasePermutation(string str)
    {
        vector<string> ans;
        Backtrack(0, str, ans);
        return ans;
    }

private:
    void Backtrack(int idx, string &str, vector<string> &res)
    {
        const int kLen = str.size();

        if (idx == kLen)
        {
            res.push_back(str);
            return;
        }

        char ch = str[idx];
        str[idx] = islower(ch) ? toupper(ch) : tolower(ch);
        Backtrack(idx + 1, str, res);
        if (isalpha(ch))
        {
            str[idx] = ch;
            Backtrack(idx + 1, str, res);
        }
    }
};