// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/discuss/496490/C%2B%2B-Set
#include <algorithm>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> KWeakestRows(vector<vector<int>> &mat, int k)
    {
        const int kRows = mat.size();
        set<pair<int, int>> m;
        for (auto row = 0; row < kRows; ++row)
        {
            auto cnt = accumulate(begin(mat[row]), end(mat[row]), 0);
            m.insert({cnt, row});
        }

        vector<int> ans;
        for (auto it = begin(m); k > 0; ++it, --k)
        {
            ans.push_back(it->second);
        }

        return ans;
    }
};