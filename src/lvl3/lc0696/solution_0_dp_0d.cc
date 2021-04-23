// https://leetcode.com/problems/count-binary-substrings/
//
// Time Complexity:     O(`kLen`)
// Space Complexity:    O(1)
//
// Reference:
//  https://leetcode.com/problems/count-binary-substrings/discuss/108625/JavaC%2B%2BPython-Easy-and-Concise-with-Explanation
#include <string>

using namespace std;

class Solution
{
public:
    int countBinarySubstrings(string str)
    {
        const int kLen = str.size();

        int cur = 1, prev = 0, count = 0;

        for (int i = 1; i < kLen; ++i)
        {
            if (str[i] == str[i - 1])
                ++cur;
            else
            {
                count += min(cur, prev);
                prev = cur;
                cur = 1;
            }
        }

        return count + min(prev, cur);
    }
};