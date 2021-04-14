// https://leetcode.com/problems/flatten-nested-list-iterator/
//
// Time Complexities:
//  next():     O()
//  hasNext():  O()
//
// Time Complexity: O()
//
// Reference:
//  https://leetcode.com/problems/flatten-nested-list-iterator/discuss/80147/Simple-Java-solution-using-a-stack-with-explanation
#include <stack>
#include <vector>
#include "nested_integer.h"

using namespace std;

class NestedIterator
{
public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        prepare(nestedList);
    }

    int next()
    {
        if (!hasNext())
            return -1;

        auto ni = stack.top();
        stack.pop();

        return ni.getInteger();
    }

    bool hasNext()
    {
        while (!stack.empty() && !stack.top().isInteger())
        {
            auto list = stack.top().getList();
            stack.pop();
            prepare(list);
        }

        return !stack.empty();
    }

private:
    stack<NestedInteger> stack;

    void prepare(vector<NestedInteger> &nestedList)
    {
        const int kSize = nestedList.size();
        for (int i = kSize - 1; i >= 0; --i)
        {
            stack.push(nestedList[i]);
        }
    }
};