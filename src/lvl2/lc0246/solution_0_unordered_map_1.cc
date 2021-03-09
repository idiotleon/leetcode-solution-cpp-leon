// https://leetcode.com/problems/strobogrammatic-number/
//
// Time Compleixty:     O(`kLen`)
// Space Complexity:    O(1)
//
// Reference:
//  https://leetcode.com/problems/strobogrammatic-number/discuss/67207/C++-unordered_map/69172
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isStrobogrammatic(string num)
    {
        const int kLen = num.size();

        unordered_map<char, char> map{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};

        int lo = 0, hi = kLen - 1;

        while (lo <= hi)
        {
            if (map[num[lo++]] != num[hi--])
                return false;
        }

        return true;
    }
};