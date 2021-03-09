#include "Utility.h"
#include <iostream>
#include <sstream>
#include <iomanip>

int Utility::IndexCall(int x, int y, int paramMaxX)
{
	//	array[y][x]
	return y * paramMaxX + x;
}

std::string Utility::MsecToTimeString(double msecAll)
{
	static const double calc = 1. / 60.;

	auto secAll = floor(msecAll * 0.001);
	auto minAll = floor(secAll * calc);
	auto hour = floor(minAll * calc);
	auto min = minAll - hour * 60;
	auto sec = secAll - (hour * 60 * 60 + min * 60);
	auto msec = msecAll - (hour * 60 * 60 * 1000 + min * 60 * 1000 + sec * 1000);

	std::ostringstream ostr;
	ostr << std::setfill('0') << std::setw(2) << (int)hour << ":"
		<< std::setfill('0') << std::setw(2) << (int)min << ":"
		<< std::setfill('0') << std::setw(2) << (int)sec << "."
		<< std::setfill('0') << std::setw(3) << (int)msec;

	return ostr.str();
}
