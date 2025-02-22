#ifndef _CSOLUTION_H_
#define _CSOLUTION_H_

#include <string>
#include <vector>

enum class EDirection{N, E, S, W};
enum class ERotation{L, R};
class CPoint {
public:
	CPoint() : CPoint(0, 0) {}
	CPoint(const int _x, const int _y) : x(_x), y(_y) {}
	void move(const ERotation turn, const int value);
	int getDistance() {
		return std::abs(x) + std::abs(y);
	}
	int getDistanceToFirstPointVisitedTwice() {
		return distance;
	}
private:
	int x, y;
	int distance{0};
	EDirection currentDirection{EDirection::N};
	std::vector<std::pair<int,int>> visited{};
	bool intersectWasFound{false};
};

class CSolution {
public:
	void setData(const std::string &_input);
	void solution();
	int getResultPart1();
	int getResultPart2();
private:

	std::string data{};
	int result1{};
	int result2{};
};

#endif // _CSOLUTION_H_
