// https://leetcode.com/problems/beautiful-arrangement/
//
// Time Complexity:     O()
// Space Compleixty:    O()
//
// Reference:
//  https://leetcode.com/problems/beautiful-arrangement/discuss/1000788/C%2B%2B-Backtracking-DFS-%2B-Bitwise-Solutions-Compared-and-Explained-100-Time-~95-Space
class Solution
{
public:
    int countArrangement(int n)
    {
        if (n < 4)
            return n;

        int count = 0, bit_mask = 0;

        backtrack(1, bit_mask, n, count);

        return count;
    }

private:
    void backtrack(int idx, int &bit_mask, const int kN, int &count)
    {
        if (idx > kN)
            ++count;

        for (int i = 1; i <= kN; ++i)
        {
            int cur_bit = 1 << i;

            if (!(bit_mask & cur_bit) && (i % idx == 0 || idx % i == 0))
            {
                bit_mask ^= cur_bit;
                backtrack(idx + 1, bit_mask, kN, count);
                bit_mask ^= cur_bit;
            }
        }
    }
};