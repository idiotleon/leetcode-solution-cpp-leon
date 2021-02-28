#include <unordered_map>
#include <stack>

using namespace std;

class FreqStack
{
public:
    void push(int x)
    {
        max_freq = max(max_freq, ++num_to_freq[x]);
        freq_level[num_to_freq[x]].push(x);
    }

    int pop()
    {
        int x = freq_level[max_freq].top();
        freq_level[max_freq].pop();

        if (freq_level[num_to_freq[x]--].empty())
            --max_freq;

        return x;
    }

private:
    unordered_map<int, int> num_to_freq;
    unordered_map<int, stack<int>> freq_level;
    int max_freq = 0;
};