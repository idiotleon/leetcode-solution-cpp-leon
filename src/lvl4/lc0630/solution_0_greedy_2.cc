// https://leetcode.com/problems/course-schedule-iii/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/course-schedule-iii/discuss/104840/C%2B%2B-13-lines-With-Explanation
#include <set>
#include <vector>

using namespace std;

class Solution
{
public:
    int scheduleCourse(vector<vector<int>> &courses)
    {
        const int kCourses = courses.size();

        sort(courses.begin(), courses.end(),
             [](vector<int> a, vector<int> b) { return a[1] < b[1]; });

        multiset<int> cls;
        int sum = 0;

        for (auto &course : courses)
        {
            int kDuration = course.front();
            int kLastDay = course.back();
            if (kDuration > kLastDay)
                continue;

            if (sum + kDuration <= kLastDay)
            {
                cls.insert(kDuration);
                sum += kDuration;
            }
            else if (*cls.rbegin() > kDuration)
            {
                sum += kDuration - *cls.rbegin();
                cls.erase(--cls.end());
                cls.insert(kDuration);
            }
            else
            {
            }
        }

        return cls.size();
    }
};