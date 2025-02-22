#ifndef _CSOLUTION_H_
#define _CSOLUTION_H_

#include <iostream>
#include <string>
#include <vector>


class CDisplay {
public:
	CDisplay() : CDisplay(50, 6) {}
	CDisplay(const int _width, const int _height);
	// display getDisplay();
	int getLitPixelCount();
	void rect(const std::size_t a, const std::size_t b);
	void rotateRow(const int row, const int distance);
	void rotateColumn(const int column, const int distance);

	//for test
	bool getPixel(const int a, const int b);
	void print();
private:
	std::vector<std::vector<bool>> pixels;
};

class CSolution {
public:
	void setData(const std::vector<std::string> &_input);
	void solution();
	int getResultPart1();
	int getResultPart2();
private:
	std::vector<std::string> data{};
	int result1{};
	int result2{};

};

#endif // _CSOLUTION_H_
