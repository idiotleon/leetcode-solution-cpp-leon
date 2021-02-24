// https://leetcode.com/problems/determine-if-two-strings-are-close/
//
// Time Complexity:     O(N * lg(26))
// Space Complexity:    O(26) ~ O(1)
//
// References:
//  https://leetcode.com/problems/determine-if-two-strings-are-close/discuss/935920/C++-Short-and-Simple-oror-O(-N-)-solution/827020
//  https://leetcode.com/problems/determine-if-two-strings-are-close/discuss/935920/C%2B%2B-Short-and-Simple-oror-O(-N-)-solution
#include <vector>;
#include <string>;

using namespace std;

class Solution
{
public:
    bool CloseStrings(string word1, string word2)
    {
        vector<int> freqs1(26), freqs2(26);

        for (auto ch : word1)
            ++freqs1[ch - 'a'];

        for (auto ch : word2)
            ++freqs2[ch - 'a'];

        for (int i = 0; i < 26; ++i)
        {
            if ((freqs1[i] && !freqs2[i]) || (!freqs1[i] && freqs2[i]))
            {
                return false;
            }
        }

        sort(freqs1.begin(), freqs1.end());
        sort(freqs2.begin(), freqs2.end());
        return freqs1 == freqs2;
    }
};