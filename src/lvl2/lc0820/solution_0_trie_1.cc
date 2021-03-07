// https://leetcode.com/problems/short-encoding-of-words/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/short-encoding-of-words/discuss/125784/Trie-Solution
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> next;
};

class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {
        TrieNode *root = new TrieNode;
        vector<pair<TrieNode *, int>> leaves;

        for (auto &word : unordered_set<string>(words.begin(), words.end()))
        {
            const int kLen = word.size();
            TrieNode *cur = root;
            for (int i = kLen - 1; i >= 0; --i)
            {
                if (cur->next.count(word[i]) == 0)
                    cur->next[word[i]] = new TrieNode;

                cur = cur->next[word[i]];
            }

            leaves.push_back(make_pair(cur, 1 + kLen));
        }

        int shortest = 0;
        for (auto leaf : leaves)
        {
            if ((leaf.first->next).size() == 0)
                shortest += leaf.second;
        }

        return shortest;
    }
};
