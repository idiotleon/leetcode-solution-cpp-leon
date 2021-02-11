// https://leetcode.com/problems/copy-list-with-random-pointer/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/copy-list-with-random-pointer/discuss/43497/2-clean-C%2B%2B-algorithms-without-using-extra-arrayhash-table.-Algorithms-are-explained-step-by-step.
#include "node.h"

using namespace std;

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *newHead, *l1, *l2;
        if(head == NULL) return NULL;
        
        for(l1 = head; l1 != NULL; l1 = l1 -> next -> next){
            l2 = new Node(l1 -> val);
            l2 -> next = l1 -> next;
            l1 -> next = l2;
        }
        
        newHead = head -> next;
        for(l1 = head; l1 != NULL; l1 = l1 -> next -> next){
            if(l1 -> random != NULL) 
                l1 -> next -> random = l1 -> random -> next;
        }
        
        for(l1 = head; l1 != NULL; l1 = l1 -> next){
            l2 = l1 -> next;
            l1 -> next = l2 -> next;
            if(l2 -> next != NULL)
                l2 -> next = l2 -> next -> next;
        }
        
        return newHead;
    }
};