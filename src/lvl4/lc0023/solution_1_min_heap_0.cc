// https://leetcode.com/problems/merge-k-sorted-lists/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// References:
//  https://leetcode.com/problems/merge-k-sorted-lists/discuss/10527/Difference-between-Priority-Queue-and-Heap-and-C%2B%2B-implementation
#include <vector>
#include <queue>
#include "util/data_structure/list_node.h"

using namespace std;

class Solution
{
public:
    ListNode *MergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, Compare> min_heap;

        for (auto list : lists)
        {
            if (list)
            {
                min_heap.push(list);
            }
        }

        if (min_heap.empty())
            return NULL;

        ListNode *top = min_heap.top();
        min_heap.pop();

        if (top->next)
        {
            min_heap.push(top->next);
        }

        ListNode *tail = top;
        while (!min_heap.empty())
        {
            tail->next = min_heap.top();
            min_heap.pop();
            tail = tail->next;
            if (tail->next)
                min_heap.push(tail->next);
        }

        return top;
    }

private:
    struct Compare
    {
        bool operator()(const ListNode *lo, const ListNode *hi)
        {
            return lo->val > hi->val;
        }
    };
};