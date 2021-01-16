// https://leetcode.com/problems/two-sum/
//
// Time Complexity:     O(`size`)
// Space Complexity:    O(`size`)
//
// References:
//  https://leetcode.com/problems/two-sum/discuss/13/Accepted-C++-O(n)-Solution/263
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int size = nums.size();
        unordered_map<int, int> num_to_idx;
        
        for(int i = 0; i < size; ++i){
            int num = nums[i];
            auto it = num_to_idx.find(target - num);
            
            if(it != num_to_idx.end()){
                return vector<int>{i, it -> second};
            }
            
            num_to_idx[num] = i;
        }
        
        return vector<int>{-1, -1};
    }
};