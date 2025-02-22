#include "CSolution.h"
#include <algorithm>
#include <iterator>
#include <numeric>
#include <regex>

CDisplay::CDisplay(const int width, const int height)
	: pixels(std::vector(height, std::vector(width, false))) {}

void CDisplay::rect(const std::size_t a, const std::size_t b) {
	auto aa = a;
	auto bb = b;
	if (b > pixels.size() || a > pixels.at(0).size()) {
		bb = pixels.size();
		aa = pixels.at(0).size();
	}
	for(std::size_t i = 0; i < aa; ++i) {
		for(std::size_t j = 0; j < bb; ++j) {
			pixels[j][i] = true;
		}
	}
}

void CDisplay::rotateRow(const int row, const int distance) {
	auto dis = distance % pixels.at(row).size();
	std::rotate(
		pixels.at(row).rbegin(),
		pixels.at(row).rbegin() + dis,
		pixels.at(row).rend());
}

void CDisplay::rotateColumn(const int column, const int distance) {
	auto tmp = std::vector<bool>();
	for(std::size_t i = 0; i < pixels.size(); ++i) {
		tmp.push_back(pixels.at(i).at(column));
	}

	std::rotate(tmp.rbegin(), tmp.rbegin() + (distance % pixels.size()), tmp.rend());

	for(std::size_t i = 0; i < pixels.size(); ++i) {
		pixels.at(i).at(column) = tmp.at(i);
	}
}

void CDisplay::print() {
	for(const auto &row : pixels) {
		for (const auto &pix : row) {
			std::cout << (pix ? 'X' : '.') << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int CDisplay::getLitPixelCount() {
	int res = 0;
	for (const auto &line : pixels) {
		res = std::accumulate(
			line.begin(),
			line.end(),
			res,
			[](auto res, const auto &x) {
				return res += x;
			}
		);
	}
	return res;
}

bool CDisplay::getPixel(const int a, const int b) {
	return pixels[a][b];
}

void CSolution::setData(const std::vector<std::string> &_input) {
	data = std::move(_input);
}

int CSolution::getResultPart1() {
	return result1;
}

int CSolution::getResultPart2() {
	return result2;
}

void CSolution::solution() {
	std::regex pattern(R"((rect|rotate){1} (column |row |)(((x|y)=)(((\d*) by (\d*)))|((\d*)x(\d*))))");
	std::smatch match;
	CDisplay dis;

	for (const auto &line : data) {
		std::regex_search(line, match, pattern);
		if (match[1].str() == "rect") {
			dis.rect(std::stoi(match[11].str()), std::stoi(match[12].str()));
		} else {
			auto x = std::stoi(match[8].str());
			auto y = std::stoi(match[9].str());
			if (match[2].str() == "column ") {
				dis.rotateColumn(x, y);
			} else {
				dis.rotateRow(x, y);
			}
		}
	}
	result1 = dis.getLitPixelCount();
	dis.print();
}
