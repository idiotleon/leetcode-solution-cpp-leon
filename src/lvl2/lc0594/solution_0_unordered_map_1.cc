// https://leetcode.com/problems/longest-harmonious-subsequence/
//
// Time Complexity:     O(`nNums`)
// Space Complexity:    O(`nNums`)
//
// Reference:
//  https://leetcode.com/problems/longest-harmonious-subsequence/discuss/103499/Three-C%2B%2B-Solution-run-time-with-explanation
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int FindLHS(vector<int> &nums)
    {
        unordered_map<int, int> num_to_freq;

        for (auto &num : nums)
        {
            ++num_to_freq[num];
        }

        int longest = 0;
        for (auto &entry : num_to_freq)
        {
            if (num_to_freq.count(entry.first - 1) > 0)
            {
                longest = max(longest, entry.second + num_to_freq[entry.first - 1]);
            }
        }

        return longest;
    }
};