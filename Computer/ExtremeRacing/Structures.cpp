#include "Structures.h"

int Car::GetSpeed()
{
	if (IsBadReadPtr(this, sizeof(Car)))
		return 0;

	return round(speed * 3);
}