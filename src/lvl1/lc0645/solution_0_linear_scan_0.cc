// https://leetcode.com/problems/set-mismatch/
//
// Time Complexity:     O(`kSize`)
// Space Complexity:    O(1)
//
// Reference:
//  https://leetcode.com/problems/set-mismatch/discuss/105515/C++-6-lines-solution-with-explanation/127088
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        vector<int> result(2, -1);
        for (int i = 0; i < nums.size(); ++i)
        {
            while (nums[i] != i + 1)
            {
                if (nums[i] == nums[nums[i] - 1])
                {
                    result[0] = nums[i];
                    result[1] = i + 1;
                    break;
                }
                else
                    swap(nums[i], nums[nums[i] - 1]);
            }
        }
        return result;
    }
};