// https://leetcode.com/problems/longest-harmonious-subsequence/
//
// Time Complexity:     O()
// Space Complexity:    O()
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
        int longest = 0;

        for (auto &num : nums)
        {
            ++num_to_freq[num];

            if (num_to_freq.count(num + 1))
            {
                longest = max(longest, num_to_freq[num] + num_to_freq[num + 1]);
            }

            if (num_to_freq.count(num - 1))
            {
                longest = max(longest, num_to_freq[num] + num_to_freq[num - 1]);
            }
        }

        return longest;
    }
};