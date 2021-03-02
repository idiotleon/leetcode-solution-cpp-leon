// https://leetcode.com/problems/distribute-candies/
//
// Time Complexity:     O(`kSize`)
// Space Complexity:    O(`kSize`)
//
// Reference:
//  https://leetcode.com/problems/distribute-candies/discuss/102946/C%2B%2B-1-liner
//  https://leetcode.com/problems/distribute-candies/discuss/102924/C%2B%2B-Clean-Code-2-Solutions%3A-Set-and-Sort
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    int distributeCandies(vector<int> &c)
    {
        // not used
        // const int kSize = c.size();

        return min(unordered_set<int>(begin(c), end(c)).size(), c.size() / 2);
    }
};