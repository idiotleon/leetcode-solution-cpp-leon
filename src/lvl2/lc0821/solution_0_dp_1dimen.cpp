// https://leetcode.com/problems/shortest-distance-to-a-character/
//
// Time Complexity:     O()
// Space Complexity:    O()
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
        vector<int> res(lenS);

        for (int i = 0; i < lenS; ++i)
            res[i] = s[i] == c ? 0 : lenS;

        for (int i = 1; i < lenS; ++i)
            res[i] = min(res[i], res[i - 1] + 1);

        for (int i = lenS - 2; i >= 0; --i)
            res[i] = min(res[i], res[i + 1] + 1);

        return res;
    }
};