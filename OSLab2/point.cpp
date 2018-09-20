#include "point.h"
#include <string>

Point::Point(int first, int second)
{
	Point::a = first;
	Point::b = second;
}

std::string Point::giveData()
{
	std::string result = a + "; " + b;
	return result;
}
