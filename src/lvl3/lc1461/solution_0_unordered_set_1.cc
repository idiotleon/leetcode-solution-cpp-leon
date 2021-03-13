// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/discuss/660632/Kt-Js-Py3-Cpp-Sliding-Window-Seen-Strings/563588
#include <unordered_set>
#include <string>

using namespace std;

class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        const int kLen = s.size();
        if (kLen < k)
            return false;

        unordered_set<string> seen;

        int lo = 0, hi = k - 1;

        while (hi++ < kLen)
        {
            string word = s.substr(lo++, k);
            seen.insert(word);
        }

        return seen.size() == (1 << k);
    }
};