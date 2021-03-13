// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/discuss/660546/JavaPython-3-4-and-1-liners-clean-codes-using-set-w-brief-explanation-and-analysis./559976
#include <unordered_set>
#include <string>

using namespace std;

class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        const int kLen = s.size();
        unordered_set<string> seen;

        int len = min(kLen, k);

        for (int i = 0; i <= kLen - len; ++i)
        {
            seen.insert(s.substr(i, len));
        }

        return seen.size() == (1 << k);
    }
};