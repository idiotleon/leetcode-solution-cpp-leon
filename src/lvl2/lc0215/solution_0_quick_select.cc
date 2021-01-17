// https://leetcode.com/problems/kth-largest-element-in-an-array/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// References:
//  https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309/C%2B%2B-STL-partition-and-heapsort
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        const int nNums = nums.size();
        
        int lo = 0, hi = nNums - 1, kLargest = nNums - k;
        
        while(true){
            int pivot = partition(lo, hi, nums);
            
            if(pivot < kLargest){
                lo = 1 + pivot;
            }else if(pivot > kLargest){
                hi = pivot - 1;
            }else{
                return nums[pivot];
            }
        }
        
        return -1;
    }
    
private:
    int partition(int low, int high, vector<int>& nums){
        if(low == high) return low;
        
        int lo = low, hi = high + 1;
        
        int pivot = nums[low];
        
        while(true){
            while(nums[++lo] < pivot){
                if(lo == high) break;
            }
            
            while(pivot < nums[--hi]){
                if(hi == low) break;
            }
            
            if(lo >= hi) break;
            
            swap(nums[lo], nums[hi]);
        }
        
        swap(nums[low], nums[hi]);
        
        return hi;
    }
};