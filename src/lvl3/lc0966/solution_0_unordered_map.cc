// https://leetcode.com/problems/vowel-spellchecker/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/vowel-spellchecker/discuss/211189/JavaC%2B%2BPython-Two-HashMap
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
    {
        const int kQueries = queries.size();

        unordered_set<string> words(wordlist.begin(), wordlist.end());
        unordered_map<string, string> cap, vowel;

        for (string word : wordlist)
        {
            string lower = ToLower(word), devowel = ToDev(word);
            cap.insert({lower, word});
            vowel.insert({devowel, word});
        }

        for (int i = 0; i < kQueries; ++i)
        {
            if (words.count(queries[i]))
                continue;
            string lower = ToLower(queries[i]), devowel = ToDev(queries[i]);

            if (cap.count(lower))
            {
                queries[i] = cap[lower];
            }
            else if (vowel.count(devowel))
            {
                queries[i] = vowel[devowel];
            }
            else
            {
                queries[i] = "";
            }
        }

        return queries;
    }

private:
    unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};

    string ToLower(string word)
    {
        for (auto &ch : word)
        {
            ch = tolower(ch);
        }

        return word;
    }

    string ToDev(string word)
    {
        word = ToLower(word);
        for (auto &ch : word)
        {
            if (vowels.count(ch))
                ch = '#';
        }

        return word;
    }
};