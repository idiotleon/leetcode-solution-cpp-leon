// @author: Leon
// https://leetcode.com/problems/truncate-sentence/
//
// Time Complexity:     O(`kLen`)
// Space Complexity:    O(1)
#include <string>
#include <vector>

using namespace std;

class Solution0LiearScan0
{
public:
    string truncateSentence(string str, int k)
    {
        const int kLen = str.size();

        int count = 0;

        int idx = 0;

        while (idx < kLen)
        {
            if (str[idx] == ' ') // no need to worry about consecutive spaces
                if (++count == k)
                    break;

            ++idx;
        }

        return str.substr(0, idx);
    }
};