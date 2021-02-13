// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/discuss/502809/just-count-number-of-0-and-1-in-binary
class Solution {
public:
    int numberOfSteps (int num) {
        if(!num) return 0;
        
        int res = 0;
        
        while(num){
            res += (num & 1) ? 2 : 1;
            num >>= 1;
        }
        
        return res - 1;
    }
};