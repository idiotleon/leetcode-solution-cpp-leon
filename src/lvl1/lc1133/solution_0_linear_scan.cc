// @author: Leon
// https://leetcode.com/problems/largest-unique-number/
//
// Time Complexity:     O(`kRange`)
// Space Complexity:    O(`kRange`)
#include <vector>

using namespace std;

class Solution
{
public:
    int largestUniqueNumber(vector<int> &nums)
    {
        vector<int> freqs(kRange, 0);

        for (int num : nums)
        {
            ++freqs[num];
        }

        for (int i = kRange - 1; i >= 0; --i)
        {
            if (freqs[i] == 1)
                return i;
        }

        return -1;
    }

private:
    const int kRange = 1000 + 7;
};