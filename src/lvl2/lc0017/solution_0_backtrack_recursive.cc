// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/letter-combinations-of-a-phone-number/discuss/8153/8-line-Backtracking-Function-C++-Solution/215014
//  https://leetcode.com/problems/letter-combinations-of-a-phone-number/discuss/8153/8-line-Backtracking-Function-C%2B%2B-Solution
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if (digits.empty())
            return ans;

        backtrack(0, "", digits, kDialPad, ans);

        return ans;
    }

private:
    const vector<string> kDialPad{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtrack(int idx, string cur_str, const string digits,
                   const vector<string> &kDialPad,
                   vector<string> &res)
    {
        const int kLenD = digits.size(), kLenS = cur_str.size();

        if (kLenD == kLenS)
        {
            res.push_back(cur_str);
            return;
        }

        for (int i = 0; i < kDialPad[digits[idx] - '0'].size(); ++i)
        {
            cur_str.push_back(kDialPad[digits[idx] - '0'][i]);
            backtrack(1 + idx, cur_str, digits, kDialPad, res);
            cur_str.pop_back();
        }
    }
};