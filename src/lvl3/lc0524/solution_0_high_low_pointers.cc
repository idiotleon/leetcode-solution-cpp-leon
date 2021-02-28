// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/discuss/99585/10-lines-solutions-for-c++/103698
//  https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/discuss/99585/10-lines-solutions-for-c%2B%2B
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string findLongestWord(string str, vector<string> &words)
    {
        const int kLenS = str.size();
        string ans;

        for (string &word : words)
        {
            int idxS = 0, idxW = 0;

            const int kLenW = word.size();

            while (idxS < kLenS && idxW < kLenW)
            {
                if (str[idxS] == word[idxW])
                {
                    ++idxW;
                }

                ++idxS;
            }

            if (idxW == kLenW)
            {
                const int kLen = ans.size();

                if ((kLen == kLenW && ans > word) || kLen < kLenW)
                {
                    ans = word;
                }
            }
        }

        return ans;
    }
};