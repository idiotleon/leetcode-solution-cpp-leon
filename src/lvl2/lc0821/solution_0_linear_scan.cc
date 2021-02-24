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
        int pos = -kLenS;
        vector<int> res(kLenS, kLenS);

        for (int i = 0; i < kLenS; ++i)
        {
            if (s[i] == c)
                pos = i;
            res[i] = i - pos;
        }

        for (int i = pos - 1; i >= 0; --i)
        {
            if (s[i] == c)
                pos = i;
            res[i] = min(res[i], pos - i);
        }

        return res;
    }
};