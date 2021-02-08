// https://leetcode.com/problems/shortest-distance-to-a-character/
//
// Time Complexity:     O(`lenS`)
// Space Complexity:    O(`lenS`)
//
// Reference:
//  https://leetcode.com/problems/shortest-distance-to-a-character/discuss/125788/C%2B%2BJavaPython-2-Pass-with-Explanation
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        const int lenS = s.size();
        int pos = -lenS;
        vector<int> res(lenS, lenS);

        for (int i = 0; i < lenS; ++i)
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