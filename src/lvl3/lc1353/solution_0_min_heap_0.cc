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

        int idx = 0, max_num = 0, cur_day = 0;

        while (!min_heap.empty() || idx < kSize)
        {
            if (min_heap.empty())
            {
                cur_day = events[idx][0];
            }

            while (idx < kSize && events[idx][0] <= cur_day)
            {
                min_heap.push(events[idx][1]);
                ++idx;
            }

            min_heap.pop();
            ++max_num;
            ++cur_day;

            while (!min_heap.empty() && min_heap.top() < cur_day)
            {
                min_heap.pop();
            }
        }

        return max_num;
    }
};