// https://leetcode.com/problems/number-of-different-subsequences-gcds/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/number-of-different-subsequences-gcds/discuss/1141309/Simple-explanation-or-O(n-*-sqrt-n)
#include <vector>

using namespace std;

class Solution
{
public:
    int CountDifferentSubsequenceGCDs(vector<int> &nums)
    {
        const int kSize = nums.size();

        vector<int> factors(kRange, 0);

        for (auto &num : nums)
        {
            for (int factor1 = 1; factor1 * factor1 <= num; ++factor1)
            {
                if (num % factor1 == 0)
                {
                    int factor2 = num / factor1;

                    if (factors[factor1] == 0)
                        factors[factor1] = num;
                    else
                        factors[factor1] = GetGCD(factors[factor1], num);

                    if (factors[factor2] == 0)
                        factors[factor2] = num;
                    else
                        factors[factor2] = GetGCD(factors[factor2], num);
                }
            }
        }

        int count = 0;
        for (int i = 1; i < kRange; ++i)
        {
            if (factors[i] == i)
                ++count;
        }

        return count;
    }

private:
    constexpr static int kRange = (int)2 * 1e5 + 7;

    int GetGCD(int a, int b)
    {
        while (b != 0)
        {
            int temp = a;
            a = b;
            b = temp % b;
        }

        return a;
    }
};