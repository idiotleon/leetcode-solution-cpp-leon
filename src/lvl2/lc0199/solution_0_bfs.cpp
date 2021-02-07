#include <queue>
#include <vector>
#include "tree_node.h"

using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        
        queue<TreeNode*> queue;
        queue.push(root);
        
        while(!queue.empty()){
            const int nNodes = queue.size();
            
            for(int sz = 0; sz < nNodes; ++sz){
                TreeNode* cur = queue.front();
                queue.pop();
                
                if(sz == nNodes - 1) ans.push_back(cur -> val);
                
                if(cur -> left)
                    queue.push(cur -> left);
                
                if(cur -> right)
                    queue.push(cur -> right);
            }
        }
        
        return ans;
    }
};