// https://leetcode.com/problems/peeking-iterator/
//
// Time Complexity:     O()
// Space Complexity:    O()
//
// Reference:
//  https://leetcode.com/problems/peeking-iterator/discuss/72554/Simple-C%2B%2B-solution-(1-line-per-method)-without-extra-member-variables
#include "Iterator.h"

using namespace std;

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return Iterator(*this).next();
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    return Iterator::next();
	}
	
	bool hasNext() const {
	    return Iterator::hasNext();
	}
};