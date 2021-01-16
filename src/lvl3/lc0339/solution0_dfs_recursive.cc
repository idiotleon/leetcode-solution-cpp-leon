#include <vector>
#include "fake_nested_integer.h"

using std::vector;

class Solution0DFSRecursive{
    public:
    int depthSum(vector<FakeNestedInteger>& nested_list) {
        int sum = 0;
        dfs(1, nested_list, sum);
        return sum;
    }
    
private:
    void dfs(int depth, const vector<FakeNestedInteger>& nested_list, int& sum){        
        for(auto& ni: nested_list){
            if(ni.isInteger()){
                sum += ni.getInteger() * depth;
            }else{
                dfs(1 + depth, ni.getList(), sum);
            }
        }
    }
};