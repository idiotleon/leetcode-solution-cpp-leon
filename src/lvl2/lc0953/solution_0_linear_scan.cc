// @author: Leon
// https://leetcode.com/problems/verifying-an-alien-dictionary/
//
// Time Complexity:     O(`kLen` + `kWords` * len)
// Space Complexity:    O(26) ~ O(1)
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool IsAlienSorted(vector<string> &words, string order)
    {
        const int kLen = order.size(), kWords = words.size();
        vector<int> dict(26, 0);

        for (int i = 0; i < kLen; ++i)
        {
            dict[order[i] - 'a'] = i;
        }

        for (int i = 1; i < kWords; ++i)
        {
            if (IsOrderBroken(words[i - 1], words[i], dict))
                return false;
        }

        return true;
    }

private:
    bool IsOrderBroken(const string &kPrevWord, const string &kCurWord, const vector<int> &kDict)
    {
        const int kLenPrev = kPrevWord.size(), kLenCur = kCurWord.size();
        const int kLen = min(kLenPrev, kLenCur);

        for (int i = 0; i < kLen; ++i)
        {
            const char kCh1 = kPrevWord[i], kCh2 = kCurWord[i];
            if (kCh1 == kCh2)
                continue;
            if (kDict[kCh1 - 'a'] > kDict[kCh2 - 'a'])
                return true;
            else
                return false;
        }

        return kLenPrev > kLenCur;
    }
};