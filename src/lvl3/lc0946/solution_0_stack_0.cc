// https://leetcode.com/problems/validate-stack-sequences/
//
// Time Complexity:     O(`kSize`)
// Space Complexity:    O(`kSize`)
//
// Reference:
//  https://leetcode.com/problems/validate-stack-sequences/discuss/197685/C%2B%2BJavaPython-Simulation-O(1)-Space
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> stack;

        int idx = 0;

        for (auto &num : pushed)
        {
            stack.push(num);

            while (!stack.empty() && stack.top() == popped[idx])
            {
                stack.pop();
                ++idx;
            }
        }

        return stack.empty();
    }
};