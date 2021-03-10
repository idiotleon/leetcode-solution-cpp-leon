// https://leetcode.com/problems/integer-to-roman/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/integer-to-roman/discuss/6382/My-simple-cpp-solution
#include <string>

using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        string res;
        string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        int idx = 0;
        while (num != 0)
        {
            while (num >= val[idx])
            {
                num -= val[idx];
                res += sym[idx];
            }

            ++idx;
        }

        return res;
    }
};