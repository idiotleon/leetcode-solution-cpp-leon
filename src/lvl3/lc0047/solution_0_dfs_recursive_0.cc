// https://leetcode.com/problems/permutations-ii/
//
// Time Complexity:     O(`kSize`!)
// Space Complexity:    O(`kSize`)
//
// Reference:
//  https://leetcode.com/problems/permutations-ii/discuss/18596/A-simple-C++-solution-in-only-20-lines/159337
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        dfs(0, nums, ans);

        return ans;
    }

private:
    void dfs(int idx_start, vector<int> nums, vector<vector<int>> &res)
    {
        const int kSize = nums.size();
        if (idx_start == kSize)
        {
            res.push_back(nums);
            return;
        }

        for (int i = idx_start; i < kSize; ++i)
        {
            if (i > idx_start && nums[i] == nums[idx_start])
                continue;

            swap(nums[i], nums[idx_start]);
            dfs(1 + idx_start, nums, res);
        }
    }
};