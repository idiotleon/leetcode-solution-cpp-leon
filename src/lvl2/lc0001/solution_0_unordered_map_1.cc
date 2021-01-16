// https://leetcode.com/problems/two-sum/
//
// Time Compleixty:     O(`size`)
// Spece Complexity:    O(`size`)
//
// References:
//  https://leetcode.com/problems/two-sum/discuss/13/Accepted-C%2B%2B-O(n)-Solution
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        const int size = nums.size();
            
        unordered_map<int, int> num_to_idx;
        vector<int> ans;
        
        for(int i = 0; i < size; ++i){
            int num = nums[i];
            
            if(num_to_idx.find(target - num) != num_to_idx.end()){
                ans.push_back(i);
                ans.push_back(num_to_idx[target - num]);
                
                return ans;
            }
            
            num_to_idx[num] = i;
        }
        
        return ans;
    }
};