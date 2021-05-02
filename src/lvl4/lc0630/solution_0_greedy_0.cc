// https://leetcode.com/problems/course-schedule-iii/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
// https://leetcode.com/problems/course-schedule-iii/discuss/104845/Short-Java-code-using-PriorityQueue/164599
#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
    int scheduleCourse(vector<vector<int>> &courses)
    {
        sort(courses.begin(), courses.end(), comparator());

        priority_queue<int> min_heap;

        int sum = 0;
        for (auto &course : courses)
        {
            const int kDuration = course[0];
            const int kLastDay = course[1];

            min_heap.push(kDuration);
            sum += kDuration;

            if (sum > kLastDay)
            {
                sum -= min_heap.top();
                min_heap.pop();
            }
        }
        return min_heap.size();
    }

private:
    struct comparator
    {
        bool operator()(const vector<int> &v1, const vector<int> &v2)
        {
            return v1[1] < v2[1];
        }
    };
};