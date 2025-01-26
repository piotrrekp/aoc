#include "CSolution.h"
#include <algorithm>
#include <iostream>
#include <sstream>

CBox::CBox(const std::string &dimension) {
	std::istringstream iss(dimension);
	char sep, sep1;
	if (!(iss >> a >> sep >> b >> sep1>> c && sep == 'x' && sep1 == 'x')) {
		std::cerr << "failed to parse dimension" << std::endl;
	}
}

int CSolution::getNeededSurface(const int a, const int b, const int c) {
	int surfaceArea = 2 * (a*b + b*c + a*c);
	int extraWrapping = std::min(a*b, std::min(b*c, a*c));
	int vResult = surfaceArea + extraWrapping;

	return vResult;
}

int CSolution::getTotalNeededSurface(const std::vector<std::string> &list) {
	int vResult = 0;
	for (const auto &line : list) {
		CBox v(line);
		vResult += getNeededSurface(v.a, v.b, v.c);
	}

	return vResult;
}

int CSolution::getTotalRibbonNeeded(const std::vector<std::string> &list) {
	int vResult = 0;
	for (const auto &line : list) {
		CBox v(line);
		vResult += getNeededRibbon(v.a, v.b, v.c);
	}


	return vResult;
}

int CSolution::getNeededRibbon(const int a, const int b, const int c) {
	int vResult = a * b * c + 2 * (a + b + c);
	int vMax = std::max (a, std::max (b, c));
	vResult -= 2*vMax;
	return vResult;
}
