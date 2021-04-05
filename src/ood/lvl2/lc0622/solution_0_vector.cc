// https://leetcode.com/problems/design-circular-queue/
//
// Time Complexities:
//       O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/design-circular-queue/discuss/149420/Concise-Java-using-array/894776
//  https://leetcode.com/problems/design-circular-queue/discuss/149420/Concise-Java-using-array
#include <vector>

using namespace std;

class MyCircularQueue
{
public:
    MyCircularQueue(int k) : kSize(k)
    {
        v.clear();
        v.resize(k);
        front = 0;
        rear = 0;
        size = 0;
    }

    bool EnQueue(int value)
    {
        if (IsFull())
            return 0;

        v[rear] = value;

        rear = (rear + 1) % kSize;

        ++size;

        return true;
    }

    bool DeQueue()
    {
        if (IsEmpty())
            return 0;

        v[front] = -1;
        front = (front + 1) % kSize;

        --size;

        return true;
    }

    int Front()
    {
        if (IsEmpty())
            return -1;

        return v[front];
    }

    int Rear()
    {
        if (IsEmpty())
            return -1;

        return v[(rear - 1 + kSize) % kSize];
    }

    bool IsEmpty()
    {
        return size == 0;
    }

    bool IsFull()
    {
        return size == kSize;
    }

private:
    vector<int> v;
    int front, rear, size;
    const int kSize;
};