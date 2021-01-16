#include <vector>
#include "fake-nested-integer.h"

using std::vector;

class Soln0DFSRecurisve{
    public:
    int depthSum(vector<FakeNestedInteger>& nestedList) {
        int sum = 0;
        dfs(1, nestedList, sum);
        return sum;
    }
    
private:
    void dfs(int depth, const vector<FakeNestedInteger>& nestedList, int& sum){        
        for(auto& ni: nestedList){
            if(ni.isInteger()){
                sum += ni.getInteger() * depth;
            }else{
                dfs(1 + depth, ni.getList(), sum);
            }
        }
    }
};