// https://leetcode.com/problems/last-stone-weight/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> max_heap(begin(stones), end(stones));

        while (max_heap.size() > 1)
        {
            int top = max_heap.top();
            max_heap.pop();
            int sec_top = max_heap.top();
            max_heap.pop();

            int collision = top - sec_top;

            if (collision > 0)
            {
                max_heap.push(collision);
            }
        }

        return max_heap.empty() ? 0 : max_heap.top();
    }
};