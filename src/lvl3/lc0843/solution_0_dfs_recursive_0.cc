// @author: Leon
// https://leetcode.com/problems/keys-and-rooms/
//
// Time Complexity:     O(V + E)
// Space Complexity:    O(V + E)
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        const int kSize = rooms.size();
        unordered_set<int> seen;
        // please pay attention to the initial state
        seen.insert(0);
        dfs(0, seen, rooms);

        return seen.size() == kSize;
    }

private:
    void dfs(int cur, unordered_set<int> &seen, vector<vector<int>> &rooms)
    {

        for (int next : rooms[cur])
        {
            if (seen.count(next))
                continue;
            seen.insert(next);
            dfs(next, seen, rooms);
        }
    }
};