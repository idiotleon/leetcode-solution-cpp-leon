// @author: Leon
// https://leetcode.com/problems/permutations-ii/
//
// Time Complexity:     O(`kSize`!)
// Space Complexity:    O(`kSize`)
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        const int nNums = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> path;
        vector<vector<int>> paths;

        vector<bool> used(nNums, false);

        backtrack(used, path, nums, paths);

        return paths;
    }

private:
    void backtrack(vector<bool> &used,
                   vector<int> &path,
                   vector<int> &nums,
                   vector<vector<int>> &paths)
    {

        const int kSize = nums.size();

        if (path.size() == kSize)
        {
            paths.push_back(path);
            return;
        }

        for (int i = 0; i < kSize; ++i)
        {
            if (used[i])
                continue;
            if (i > 0 && !used[i - 1] && nums[i - 1] == nums[i])
                continue;

            used[i] = true;
            path.push_back(nums[i]);
            backtrack(used, path, nums, paths);
            used[i] = false;
            path.pop_back();
        }
    }
};