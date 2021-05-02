// https://leetcode.com/problems/string-to-integer-atoi/
//
// Time Complexity:     O(`kLen`)
// Space Complexity:    O(1)
//
// Reference:
//  https://leetcode.com/problems/string-to-integer-atoi/discuss/4642/8ms-C++-solution-easy-to-understand/160602
//  https://leetcode.com/problems/string-to-integer-atoi/discuss/4642/8ms-C++-solution-easy-to-understand/699046
//  https://leetcode.com/problems/string-to-integer-atoi/discuss/4642/8ms-C%2B%2B-solution-easy-to-understand
#include <string>

using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        const int kLen = str.size();
        const char kSpace = ' ';

        long long int result = 0;
        int indicator = 1;

        int idx = str.find_first_not_of(kSpace);
        if (idx < 0)
            return 0;

        if (str[idx] == '-' || str[idx] == '+')
            indicator = (str[idx++] == '-') ? -1 : 1;

        while (str[idx] >= '0' && str[idx] <= '9')
        {
            result = result * 10 + (str[idx++] - '0');

            if (result * indicator >= INT_MAX)
                return INT_MAX;

            if (result * indicator <= INT_MIN)
                return INT_MIN;
        }

        return result * indicator;
    }
};