// https://leetcode.com/problems/reconstruct-itinerary/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/reconstruct-itinerary/discuss/78832/Short-C%2B%2B-DFS-iterative-44ms-solution-with-explanation.-No-recursive-calls-no-backtracking.
#include <unordered_map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        unordered_map<string, multiset<string>> graph;
        vector<string> ans;
        if (tickets.empty())
            return ans;

        for (auto &ticket : tickets)
            graph[ticket[0]].insert(ticket[1]);

        stack<string> stack;
        stack.push(kStart);

        while (!stack.empty())
        {
            string top = stack.top();

            if (graph[top].empty())
            {
                ans.push_back(top);
                stack.pop();
            }
            else
            {
                stack.push(*(graph[top].begin()));
                graph[top].erase(graph[top].begin());
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

private:
    const string kStart = "JFK";
};