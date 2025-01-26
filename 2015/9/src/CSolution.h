#ifndef _CSOLUTION_H_
#define _CSOLUTION_H_

#include <list>
#include <map>
#include <memory>
#include <string>
#include <vector>
class CSolution {
public:
	void setData(const std::vector<std::string> &_input);
	void solution();
	int getResultPart1();
	int getResultPart2();
	void printDistances();
private:
	int findLongestDistanceFrom(const std::string &_city);
	int findShortestDistanceFrom(const std::string &_city);
	void analyzeInput(const std::vector<std::string> &_input);
	int result1{};
	int result2{};

	std::map<std::pair<std::string, std::string>, int > distances{};
	std::list<std::string> cities{};
};

class Node {
public:
	Node(const std::string &city, const int distance);
	void addChild(std::shared_ptr<Node> child);
	std::string getName();
	const int getDistance();
	bool hasChild();
	std::list<std::shared_ptr<Node>> getChildren();

private:
	std::list<std::shared_ptr<Node>> children;
	const std::string city{};
	const int distance;
};

class Tree {
public:
	Tree(const std::string &startCity);
	void buildTree(
		const std::list<std::string> &cities, 
		const std::map<std::pair<std::string, std::string>, int> &_distances);
	void print();
	std::string getTree();
	
	int getMinDistance();
	int getMaxDistance();

private:
	void getMin(const std::shared_ptr<Node> &node);
	void getMax(const std::shared_ptr<Node> &node);

	void buildTree(
		const std::shared_ptr<Node> &node,
		const std::list<std::string> &cities,
		const std::map<std::pair<std::string, std::string>, int> &_distances);
	void getTree(const std::shared_ptr<Node> &node, std::string *path);
	std::shared_ptr<Node> root{nullptr};
	int minDistance{999999999};
	int maxDistance{0};
	std::string tree;
};

#endif // _CSOLUTION_H_
