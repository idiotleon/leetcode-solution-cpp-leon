// https://leetcode.com/problems/strobogrammatic-number/
//
// Time Complexity:     O(`kLen`)
// Space Complexity:    O(1)
//
// Reference:
//  https://leetcode.com/problems/strobogrammatic-number/discuss/67207/C++-unordered_map/544717
//  https://leetcode.com/problems/strobogrammatic-number/discuss/67207/C%2B%2B-unordered_map
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isStrobogrammatic(string num)
    {
        const int kLen = num.size();

        vector<int> map = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};

        int lo = 0, hi = kLen - 1;

        // "=" must be included, e.g. num = "2"
        while (lo <= hi)
        {
            if (map[num[lo] - '0'] != num[hi] - '0')
                return false;

            ++lo;
            --hi;
        }

        return true;
    }
};