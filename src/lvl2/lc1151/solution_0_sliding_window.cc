// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/
//
// Time Complexity:     O(`kSize`)
// Space Complexity:    O(1)
//
// References:
//  https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/discuss/355386/JavaPython-3-Sliding-Window-O(n)-code-w-brief-explanation-and-analysis.
#include <numeric>
#include <vector>

using namespace std;

class Solution
{
public:
    int MinSwaps(vector<int> &data)
    {
        const int kSize = data.size();

        // the size/length of the fixed-size sliding window
        const int kTotalOnes = accumulate(data.begin(), data.end(), 0);
        if (kTotalOnes == 0)
            return 0;

        int cnt_ones = 0;
        int hi = 0;
        // fixed size sliding window: lo = hi - window_size
        // int lo = 0;
        int most = 0;

        while (hi < kSize)
        {
            cnt_ones += data[hi];

            if (hi > kTotalOnes - 1)
                cnt_ones -= data[hi - kTotalOnes];

            most = max(most, cnt_ones);
            ++hi;
        }

        return kTotalOnes - most;
    }
};