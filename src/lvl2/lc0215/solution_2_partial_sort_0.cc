// https://leetcode.com/problems/kth-largest-element-in-an-array/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// References:
//  https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309/C%2B%2B-STL-partition-and-heapsorts
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int FindKthLargest(vector<int> &nums, int k)
    {
        partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
        return nums[k - 1];
    }
};