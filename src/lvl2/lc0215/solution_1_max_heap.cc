// https://leetcode.com/problems/kth-largest-element-in-an-array/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// References:
//  https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309/C%2B%2B-STL-partition-and-heapsort
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int FindKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> max_heap;

        for (int &num : nums)
        {
            max_heap.push(num);

            if (max_heap.size() > k)
            {
                max_heap.pop();
            }
        }

        return max_heap.top();
    }
};