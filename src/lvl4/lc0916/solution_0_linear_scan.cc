// https://leetcode.com/problems/word-subsets/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/word-subsets/discuss/175854/JavaC%2B%2BPython-Straight-Forward
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> wordSubsets(vector<string> &A, vector<string> &B)
    {
        vector<int> freqs(26), hash(26);
        for (string b : B)
        {
            hash = Hash(b);
            for (int i = 0; i < 26; ++i)
            {
                freqs[i] = max(freqs[i], hash[i]);
            }
        }

        vector<string> ans;
        for (string a : A)
        {
            hash = Hash(a);

            for (int i = 0; i < 26; ++i)
            {
                if (hash[i] < freqs[i])
                    break;

                if (i == 25)
                    ans.push_back(a);
            }
        }

        return ans;
    }

private:
    vector<int> Hash(string &word)
    {
        vector<int> freqs(26);

        for (char ch : word)
        {
            ++freqs[ch - 'a'];
        }

        return freqs;
    }
};