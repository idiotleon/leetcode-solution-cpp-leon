// https://leetcode.com/problems/kth-largest-element-in-an-array/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// References:
//  https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309/C%2B%2B-STL-partition-and-heapsorts
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> mset;
        
        for(int num : nums){
            mset.insert(num);
            
            if(mset.size() > k){
                mset.erase(mset.begin());
            }
        }
        
        return *mset.begin();
    }
};