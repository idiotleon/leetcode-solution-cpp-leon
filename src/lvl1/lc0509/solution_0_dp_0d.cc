// @author: Leon
// https://leetcode.com/problems/fibonacci-number/
//
// Time Complexity:     O(`n`)
// Space Complexity:    O(1)
class Solution
{
public:
    int Fib(int n)
    {
        if (n < 1)
            return 0;

        int fn_2 = 0, fn_1 = 1;
        int sum = 1;

        for (int i = 2; i <= n; ++i)
        {
            sum = fn_2 + fn_1;
            fn_2 = fn_1;
            fn_1 = sum;
        }

        return sum;
    }
};