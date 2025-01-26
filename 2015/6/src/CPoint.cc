#include "CPoint.h"

CPoint::CPoint() : CPoint(0, 0) {}

CPoint::CPoint(const int _x, const int _y) : x(_x), y(_y) {}

CPoint::CPoint(const CPoint &_point) noexcept : x(_point.getX()), y(_point.getY()) {}

const int CPoint::getX() const {
	return x;
}

const int CPoint::getY() const {
	return y;
}

const bool CPoint::operator==(const CPoint &other) const {
	return x == other.getX() && y == other.getY();
};

std::ostream &operator<<(std::ostream &os, const CPoint &obj) {
	os << "CPoint(" << obj.getX() << ", " << obj.getY() << ")";
	return os;
};
