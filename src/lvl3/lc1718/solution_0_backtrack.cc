// https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/
//
// Time Complexity:     O(`n`!)
// Space Complexity:    O(`n`)
//
// Reference:
//  https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/discuss/1008913/C%2B%2B-Backtracking
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> ConstructDistancedSequence(int n)
    {
        vector<int> ans(2 * n - 1);
        vector<int> used;
        used.assign(n + 1, 0);

        Backtrack(0, used, n, ans);

        return ans;
    }

private:
    bool Backtrack(int idx, vector<int> &used, const int kN, vector<int> &res)
    {
        const int kSize = res.size();
        const int kUsed = used.size();

        if (idx == kSize)
            return true;

        if (res[idx])
            return Backtrack(idx + 1, used, kN, res);

        for (int num = kUsed - 1; num > 0; --num)
        {
            if (used[num])
                continue;

            if (num != 1 && (idx + num >= kSize || res[idx + num]))
                continue;

            used[num] = 1;
            res[idx] = num;

            if (num != 1)
                res[idx + num] = num;

            if (Backtrack(idx + 1, used, kN, res))
                return true;

            res[idx] = 0;

            if (num != 1)
                res[idx + num] = 0;

            used[num] = 0;
        }

        return false;
    }
};