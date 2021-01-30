// @author: Leon
// https://leetcode.com/problems/find-the-most-competitive-subsequence/
//
// Time Complexity:     O(`nNums`)
// Space Complexity:    O(`nNums`)
//
// References:
//  https://leetcode.com/problems/find-the-most-competitive-subsequence/discuss/952797/Kotlin-Monotonic-Stack
//  https://leetcode.com/problems/find-the-most-competitive-subsequence/discuss/952786/JavaC%2B%2BPython-One-Pass-Stack-Solution
#include <vector>;

using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        const int nNums = nums.size();
        const int nLimit = nNums - k;
        
        vector<int> stack;
        int count = 0;
        
        for(auto &num : nums){
            while(!stack.empty() && stack.back() > num && count < nLimit){
                stack.pop_back();
                ++count;
            }
            
            stack.push_back(num);
        }
        
        while(stack.size() > k) stack.pop_back();
        
        return stack;
    }
};