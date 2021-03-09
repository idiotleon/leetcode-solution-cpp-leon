// https://leetcode.com/problems/reconstruct-itinerary/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/reconstruct-itinerary/discuss/78835/28ms-C%2B%2B-beats-100-Short-and-Elegant.
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> FindItinerary(vector<vector<string>> &tickets)
    {
        vector<string> ans;

        for (auto &ticket : tickets)
            graph[ticket[0]].push(ticket[1]);

        Postorder(kStart, ans);

        reverse(ans.begin(), ans.end());

        return ans;
    }

private:
    const string kStart = "JFK";
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;

    void Postorder(const string &cur,
                   vector<string> &res)
    {
        auto &max_heap = graph[cur];
        while (!max_heap.empty())
        {
            string next = max_heap.top();
            max_heap.pop();
            Postorder(next, res);
        }

        res.push_back(cur);
    }
};