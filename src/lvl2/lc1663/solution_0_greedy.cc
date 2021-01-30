// https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// References:
//  https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/discuss/944411/C%2B%2B-Simple-O(N)-with-explanation
#include <string>

using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n, 'a');
        k -= n;
        
        int i = res.size() - 1;
        while(k > 0){
            int temp = min(k, 25);
            res[i] += temp;
            k -= temp;
            --i;
        }
        
        return res;
    }
};