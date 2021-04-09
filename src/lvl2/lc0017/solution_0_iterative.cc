// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/letter-combinations-of-a-phone-number/discuss/8090/Iterative-c%2B%2B-solution-in-0ms
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};
        vector<string> ans;
        ans.push_back("");

        for (auto digit : digits)
        {
            vector<string> temp;
            for (auto candidate : dial_pad[digit - '0'])
            {
                for (auto str : ans)
                {
                    temp.push_back(str + candidate);
                }
            }

            ans.swap(temp);
        }

        return ans;
    }

private:
    const vector<string> dial_pad = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"};
};