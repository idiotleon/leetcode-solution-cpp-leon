// https://leetcode.com/problems/last-stone-weight/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// References:
//  https://leetcode.com/problems/last-stone-weight/discuss/294925/C%2B%2B-Multiset-and-Priority-Queue
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        multiset<int> mset(begin(stones), end(stones));

        while (mset.size() > 1)
        {
            auto top = *prev(mset.end());
            mset.erase(prev(mset.end()));
            auto sec_top = *prev(mset.end());
            mset.erase(prev(mset.end()));

            int collision = top - sec_top;
            if (collision > 0)
            {
                mset.insert(collision);
            }
        }

        return mset.empty() ? 0 : *mset.begin();
    }
};