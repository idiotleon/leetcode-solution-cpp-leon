// @author: Leon
// https://leetcode.com/problems/truncate-sentence/
//
// Time Complexity:     O(`kLen`)
// Space Complexity:    O(1)
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string truncateSentence(string str, int k)
    {
        const int kLen = str.size();

        int count = 0;

        for (int i = 0; i < kLen; ++i)
        {
            if (str[i] == ' ') // no need to worry about consecutive spaces
                if (++count == k)
                    return str.substr(0, i);

            if (i == kLen - 1)
                return str;
        }

        // unreachable
        return "";
    }
};