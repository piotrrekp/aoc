#include "CSolution.h"
#include <string>
#include <iostream>

int main(int argc, char **argv) {
	auto input = "hxbxwxba";
	CSolution sol;
	sol.solution(input);
	auto newPassw = sol.getResultPart1();
	sol.solution(++newPassw);
	std::cout << newPassw << std::endl;
	std::cout << sol.getResultPart1() << std::endl;
	return 0;
}
