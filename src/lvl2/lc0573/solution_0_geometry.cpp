// https://leetcode.com/problems/squirrel-simulation/
//
// Time Complexity:     O(`nNuts`)
// Space Complexity:    O(1)
//
// Reference:
//  https://leetcode.com/problems/squirrel-simulation/discuss/102842/C%2B%2B-Clean-Code-with-Explanation
#include <vector>

using namespace std;

class Solution
{
public:
    int minDistance(int height, int width, vector<int> &tree, vector<int> &squirrel, vector<vector<int>> &nuts)
    {
        // not used
        // const int nNuts = nuts.size();

        int sum = 0;
        // the optimized first pick for the squirrel
        int min_dist_start = INT_MAX;

        for (vector<int> nut : nuts)
        {
            int nut_to_tree = get_dist(nut, tree);
            int nut_to_squirrel = get_dist(nut, squirrel);

            sum += nut_to_tree;
            min_dist_start = min(min_dist_start, nut_to_squirrel - nut_to_tree);
        }

        return 2 * sum + min_dist_start;
    }

private:
    int get_dist(vector<int> a, vector<int> b)
    {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
};