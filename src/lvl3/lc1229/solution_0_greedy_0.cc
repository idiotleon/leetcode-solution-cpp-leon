// https://leetcode.com/problems/meeting-scheduler/
//
// Time Complexity:     O(`kSlots1` * lg(`kSlots1`)) + O(`kSlots2` * lg(`kSlots2`)) ~ O(kSlots * lg(kSlots))
// Space Complexity:    O(1)
//
// Reference:
//  https://leetcode.com/problems/meeting-scheduler/discuss/408491/JavaC%2B%2B-Two-Pointer-Clean-code-O(NlogN)-for-Sorting-Beat-100
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> minAvailableDuration(vector<vector<int>> &slots1, vector<vector<int>> &slots2, int duration)
    {
        const int kSlots1 = slots1.size(), kSlots2 = slots2.size();

        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());

        int idx1 = 0, idx2 = 0;

        while (idx1 < kSlots1 && idx2 < kSlots2)
        {
            const int kStartIntersect = max(slots1[idx1][0], slots2[idx2][0]);
            const int kEndIntersect = min(slots1[idx1][1], slots2[idx2][1]);

            if (kStartIntersect + duration <= kEndIntersect)
                return {kStartIntersect, kStartIntersect + duration};
            else if (slots1[idx1][1] < slots2[idx2][1])
                ++idx1;
            else
                ++idx2;
        }

        return {};
    }
};