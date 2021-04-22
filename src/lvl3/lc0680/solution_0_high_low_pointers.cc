// https://leetcode.com/problems/valid-palindrome-ii/
//
// Time Complexity:     O(`kLen`)
// Space Complexity:    O(1)
//
// Reference:
//  https://leetcode.com/problems/valid-palindrome-ii/discuss/107716/Java-O(n)-Time-O(1)-Space
#include <string>

using namespace std;

class Solution
{
public:
    bool ValidPalindrome(string str)
    {
        const int kLen = str.size();

        int lo = 0, hi = kLen - 1;

        while (lo < hi)
        {
            if (str[lo] != str[hi])
                return IsPalindrome(lo + 1, hi, str) || IsPalindrome(lo, hi - 1, str);

            ++lo;
            --hi;
        }

        return true;
    }

private:
    bool IsPalindrome(int lo, int hi, string str)
    {
        while (lo < hi)
        {
            if (str[lo] != str[hi])
                return false;

            ++lo;
            --hi;
        }

        return true;
    }
};