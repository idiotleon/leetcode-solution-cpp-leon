#include <bitset>
#include <vector>

using namespace std;

class Solution
{
public:
    int distributeCandies(vector<int> &candyTypes)
    {
        const int kSize = candyTypes.size();

        bitset<kRangeValue> hash;
        int count = 0;

        for (int type : candyTypes)
        {
            if (!hash.test(type + kOffset))
            {
                ++count;
                hash.set(type + kOffset);
            }
        }

        return min(count, kSize / 2);
    }

private:
    constexpr static int kOffset = (int)1e5;
    constexpr static int kRangeValue = 2 * kOffset + 1;
};