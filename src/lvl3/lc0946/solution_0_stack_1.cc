// https://leetcode.com/problems/validate-stack-sequences/
//
// Time Complexity:     O(`kSize`)
// Space Complexity:    O(1)
//
// Reference:
//  https://leetcode.com/problems/validate-stack-sequences/discuss/197685/C%2B%2BJavaPython-Simulation-O(1)-Space
#include <vector>

using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        // not used
        // const int kSize = pushed.size();

        int i = 0, j = 0;
        for (auto &num : pushed)
        {
            pushed[i++] = num;
            while (i > 0 && pushed[i - 1] == popped[j])
            {
                --i;
                ++j;
            }
        }

        return i == 0;
    }
};