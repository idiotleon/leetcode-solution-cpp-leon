// https://leetcode.com/problems/get-maximum-in-generated-array/
// 
// Time Complexity:     O(`n`)
// Space Complexity:    O(`n`)
//
// References:
//  https://leetcode.com/problems/get-maximum-in-generated-array/discuss/927628/Simulate-the-Generated-Array..
#include <vector>

using namespace std;

class Soln0LinearScan{
public:
    int getMaximumGenerated(int n) {
        if(n == 0) return 0;
        
        vector<int> nums (n + 1, 0);
        nums[0] = 0;
        nums[1] = 1;
            
        for(int i = 1; 2 * i <= n; ++i){
            if(2 * i <= n) {
                nums[i * 2] = nums[i];
            }
            
            if(2 * i + 1 <= n){
                nums[i * 2 + 1] = nums[i] + nums[i + 1];
            }
        }
        
        return *max_element(nums.begin(), nums.end());
    }
};