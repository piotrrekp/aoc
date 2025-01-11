#ifndef _CSOLUTION_H_
#define _CSOLUTION_H_

#include <map>
#include <set>
#include <string>
#include <vector>

using relationsValues = std::map<std::pair<std::string, std::string>, int>;

class Node {
public:
	Node(std::string const &_name, Node *parent = nullptr);
	~Node();
	void addChild(Node *node);
	std::string getName() const;
	std::vector<Node *> getChildren();
	Node *getParent();
	
private:
	std::string name;
	std::vector<Node *> children{};
	Node *parent{};
	
};

class Tree {
public:
	explicit Tree(const std::string &_name);
	~Tree();
	void buildTree(const std::vector<std::string> &_names);
	int calculateMaxHappiness(const relationsValues &values);



private:
	std::vector<Node*> getLeafs();
	void getLeafs(Node *node, std::vector<Node *> &leaves);
	void buildTree(Node *node, const std::vector<std::string> &_names);
	Node *root{nullptr};

};

class CSolution {
public:
	void setData(const std::vector<std::string> &_input);
	void solution();
	int getResultPart1();
	int getResultPart2();
private:
	void prepareData();
	int maximiseHappiness();
	std::vector<std::string> data{};
	int result1{};
	int result2{};

	std::vector<std::string> attendees;
	relationsValues seatersRelation{};

};

#endif // _CSOLUTION_H		
