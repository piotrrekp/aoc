#ifndef _CPOINT_H_
#define _CPOINT_H_

#include <ostream>


class CPoint {
public:
	CPoint();
	CPoint(const int _x, const int _y);
	CPoint(const CPoint &_point) noexcept;
	CPoint& operator=(const CPoint &_point);
	const int getX() const;
	const int getY() const;
	const bool operator==(const CPoint &other) const;
	friend std::ostream& operator<<(std::ostream &os, const CPoint &obj);

private:
	const int x, y;
};

#endif // _CPOINT_H_
