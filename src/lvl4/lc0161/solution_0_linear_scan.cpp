// https://leetcode.com/problems/one-edit-distance/
//
// Time Complexity:     O(max(`lenS`, `lenT`))
// Space Complexity:    O(1)
//
// References:
//  https://leetcode.com/problems/one-edit-distance/discuss/50108/C%2B%2B-DP
#include <string>

using namespace std;

class Solution
{
public:
    bool isOneEditDistance(string s, string t)
    {
        const int lenS = s.length(), lenT = t.length();
        if (lenS > lenT)
            return isOneEditDistance(t, s);

        for (int i = 0; i < lenS; ++i)
        {
            if (s[i] != t[i])
            {
                if (lenS == lenT)
                {
                    return s.substr(i + 1) == t.substr(i + 1);
                }
                else
                {
                    return s.substr(i) == t.substr(i + 1);
                }
            }
        }

        return 1 + lenS == lenT;
    }
};