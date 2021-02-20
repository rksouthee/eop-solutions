#include <assert.h>
#include <stdint.h>

bool addition_predicate(int x, int y)
{
	if (x < 0)
		return y >= INT_MIN - x;
	return y <= INT_MAX - x;
}

int main()
{
	assert(addition_predicate(INT_MAX, 0));
	assert(addition_predicate(0, INT_MAX));
	assert(addition_predicate(INT_MIN, 0));
	assert(addition_predicate(0, INT_MIN));
	assert(!addition_predicate(INT_MAX, 1));
	assert(!addition_predicate(1, INT_MAX));
	assert(!addition_predicate(-1, INT_MIN));
	assert(!addition_predicate(INT_MIN, -1));
}
