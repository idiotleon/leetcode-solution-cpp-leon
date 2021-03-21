// https://leetcode.com/problems/design-hashmap/
//
// Time Complexities:
//      put()           O()
//      get()           O()
//      remove()        O()
//
// Space Complexity:    O(`kSize`)
//
// Reference:
//  https://leetcode.com/problems/design-hashmap/discuss/161483/C++-solution-using-vector-of-lists/472514
//  https://leetcode.com/problems/design-hashmap/discuss/161483/C%2B%2B-solution-using-vector-of-lists
#include <list>
#include <vector>

using namespace std;

class MyHashMap
{
public:
    /** Initialize your data structure here. */
    MyHashMap()
    {
        hash.resize(kRange);
    }

    /** value will always be non-negative. */
    void Put(int key, int value)
    {
        auto &cur_list = hash[key % kRange];

        for (auto &cur_pair : cur_list)
        {
            if (cur_pair.first == key)
            {
                cur_pair.second = value;
                return;
            }
        }

        cur_list.push_back({key, value});
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int Get(int key)
    {
        auto &cur_list = hash[key % kRange];

        for (auto &cur_pair : cur_list)
        {
            if (cur_pair.first == key)
            {
                return cur_pair.second;
            }
        }

        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void Remove(int key)
    {
        auto &cur_list = hash[key % kRange];

        for (auto &cur_pair : cur_list)
        {
            if (cur_pair.first == key)
            {
                cur_list.remove(cur_pair);
                return;
            }
        }
    }

private:
    constexpr static int kRange = 10000;
    vector<list<pair<int, int>>> hash;
};