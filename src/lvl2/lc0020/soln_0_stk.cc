// @author: Leon
// https://leetcode.com/problems/valid-parentheses/
//
// Time Complexity:     O(`len_s`)
// Space Complexity:    O(`len_s`)
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int, vector<int>> stack;
        
        for(char const& ch: s){
            switch(ch){
                case '[':
                    stack.push(']');
                    break;
                case '(':
                    stack.push(')');
                    break;
                case '{':
                    stack.push('}');
                    break;
                default:
                    if(stack.empty()) 
                        return false;

                    if(stack.top() != ch) 
                        return false;

                    stack.pop();
                    break;
            }
        }
        
        if(!stack.empty()) 
            return false;
            
        return true;
    }
};