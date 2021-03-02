// https://leetcode.com/problems/single-row-keyboard/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/single-row-keyboard/discuss/376078/c%2B%2B-approach
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    int calculateTime(string keyboard, string word)
    {
        const int kLenK = keyboard.size(), kLenW = word.size();

        unordered_map<char, int> index;

        for (int i = 0; i < kLenK; ++i)
        {
            index[keyboard[i]] = i;
        }

        int distance = 0, idx = 0;
        for (int i = 0; i < kLenW; ++i)
        {
            distance += abs(idx - index[word[i]]);
            idx = index[word[i]];
        }

        return distance;
    }
};