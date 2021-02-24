#include <vector>

using namespace std;

class Iterator
{
	struct Data;
	Data *data;
	Iterator(const vector<int> &nums){};
	Iterator(const Iterator &iter){};

	// Returns the next element in the iteration.
	int next()
	{
		return 1;
	};

	// Returns true if the iteration has more elements.
	bool hasNext() const
	{
		return false;
	};
};