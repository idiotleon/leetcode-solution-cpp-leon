// @author: Leon
// https://leetcode.com/problems/keys-and-rooms/
//
// Time Complexity:     O(V + E)
// Space Complexity:    O(V + E)
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        const int kRooms = rooms.size();
        queue<int> queue;

        unordered_set<int> seen;
        seen.insert(0);

        for (int start : rooms[0])
        {
            queue.push(start);
            // please pay attention the intial state here
            seen.insert(start);
        }

        while (!queue.empty())
        {
            const int kSize = queue.size();

            for (int sz = 0; sz < kSize; ++sz)
            {
                int cur = queue.front();
                queue.pop();

                for (int next : rooms[cur])
                {
                    if (seen.count(next))
                        continue;
                    seen.insert(next);
                    queue.push(next);
                }
            }
        }

        return seen.size() == kRooms;
    }
};