// https://leetcode.com/problems/shortest-distance-to-a-character/
//
// Time Complexity:     O(`kLenS`)
// Space Complexity:    O(`kLenS`)
//
// Reference:
//  https://leetcode.com/problems/shortest-distance-to-a-character/discuss/125788/C%2B%2BJavaPython-2-Pass-with-Explanation
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<int> ShortestToChar(string s, char c)
    {
        const int kLenS = s.size();
        vector<int> res(kLenS);

        for (int i = 0; i < kLenS; ++i)
            res[i] = s[i] == c ? 0 : kLenS;

        for (int i = 1; i < kLenS; ++i)
            res[i] = min(res[i], res[i - 1] + 1);

        for (int i = kLenS - 2; i >= 0; --i)
            res[i] = min(res[i], res[i + 1] + 1);

        return res;
    }
};