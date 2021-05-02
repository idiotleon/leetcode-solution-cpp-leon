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

        sort(courses.begin(), courses.end(), comparator());

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
        }

        return cls.size();
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