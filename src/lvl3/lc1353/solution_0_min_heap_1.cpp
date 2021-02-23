// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/discuss/510263/JavaC%2B%2BPython-Priority-Queue
#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxEvents(vector<vector<int>> &events)
    {
        const int kSize = events.size();

        priority_queue<int, vector<int>, greater<int>> min_heap;
        sort(events.begin(), events.end());

        int idx = 0, max_num = 0;

        for (int d = 1; d <= kRange; ++d)
        {
            while (!min_heap.empty() && min_heap.top() < d)
            {
                min_heap.pop();
            }

            while (idx < kSize && events[idx][0] == d)
            {
                min_heap.push(events[idx][1]);
                ++idx;
            }

            if (!min_heap.empty())
            {
                min_heap.pop();
                ++max_num;
            }
        }

        return max_num;
    }

private:
    const int kRange = (int)1e5;
};