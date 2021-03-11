// https://leetcode.com/problems/longest-palindromic-substring/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//
#include <string>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string str)
    {
        const int kLenS = str.size();

        int lo = 0, longest = 0;
        for (int i = 0; i < kLenS; ++i)
        {
            expand(str, i, i, lo, longest);
            expand(str, i, i + 1, lo, longest);
        }

        return str.substr(lo, longest);
    }

private:
    void expand(string str, int i, int j, int &lo, int &longest)
    {
        const int kLenS = str.size();

        while (i >= 0 && j < kLenS && str[i] == str[j])
        {
            --i;
            ++j;
        }

        const int kLen = j - i - 1;
        if (kLen > longest)
        {
            lo = i + 1;
            longest = kLen;
        }
    }
};