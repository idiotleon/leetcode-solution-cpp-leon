// https://leetcode.com/problems/powerful-integers/
//
// Time Complexity:     O(`bound` ^ 2)
// Space Complexity:    O(`bound`) / O(1)
//
// Reference:
//  https://leetcode.com/problems/powerful-integers/discuss/214212/JavaC%2B%2BPython-Easy-Brute-Force
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        unordered_set<int> set;
        for (int i = 1; i <= bound; i *= x)
        {
            for (int j = 1; i + j <= bound; j *= y)
            {
                set.insert(i + j);
                if (y == 1)
                    break;
            }

            if (x == 1)
                break;
        }

        return vector<int>(set.begin(), set.end());
    }
};