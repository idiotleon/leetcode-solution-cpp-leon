#include "string"

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        const int lenS = s.length(), lenT = t.length();
        if (lenS != lenT)
            return false;

        int freqs[26] = {0};
        for (int i = 0; i < lenS; ++i)
        {
            ++freqs[s[i] - 'a'];
            --freqs[t[i] - 'a'];
        }

        for (int i = 0; i < 25; ++i)
            if (freqs[i])
                return false;

        return true;
    }
};