// https://leetcode.com/problems/palindromic-substrings/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/palindromic-substrings/discuss/105689/Java-solution-8-lines-extendPalindrome/144768
//  https://leetcode.com/problems/palindromic-substrings/discuss/105689/Java-solution-8-lines-extendPalindrome
#include <string>

using namespace std;

class Solution
{
public:
    int CountSubstrings(string str)
    {
        const int kLenS = str.size();

        int count = 0;

        for (int i = 0; i < kLenS; ++i)
        {
            count += Expand(i, i, str);
            count += Expand(i, 1 + i, str);
        }

        return count;
    }

private:
    int Expand(int lo, int hi, string str)
    {
        const int kLenS = str.size();
        int count = 0;

        while (lo >= 0 && hi < kLenS && (str[lo] == str[hi]))
        {
            --lo;
            ++hi;
            ++count;
        }

        return count;
    }
};