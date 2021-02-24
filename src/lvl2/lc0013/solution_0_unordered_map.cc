// https://leetcode.com/problems/roman-to-integer/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int RomanToInt(string s)
    {
        unordered_map<char, int> sym_to_val = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};

        const int kLen = s.size();
        int sum = sym_to_val[s.back()];

        for (int i = kLen - 2; i >= 0; --i)
        {
            if (sym_to_val[s[i]] < sym_to_val[s[i + 1]])
            {
                sum -= sym_to_val[s[i]];
            }
            else
            {
                sum += sym_to_val[s[i]];
            }
        }

        return sum;
    }
};