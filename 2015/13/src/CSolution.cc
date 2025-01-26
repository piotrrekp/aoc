#include "CSolution.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <regex>
#include <utility>
#include <vector>


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
	prepareData();
	result1 = maximiseHappiness();
}

void CSolution::prepareData() {
	for (const auto &line : data) {
		std::regex pattern(R"((\b.*?\b) .* (gain){0,1}(lose){0,1} (\d+) .* (\b.*?\b)\.)");
		std::smatch match;
		std::regex_search(line, match, pattern);
		seatersRelation[std::make_pair(match[1], match[5])] =
			match[2].matched ? std::stoi(match[4]) : -1 * std::stoi(match[4]);
		attendees.push_back(match[1]);
	}
	std::sort(attendees.begin(), attendees.end());
	attendees.erase(std::unique(attendees.begin(), attendees.end()), attendees.end());
	
}

int CSolution::maximiseHappiness() {
	int result = 0;
	for (const auto &name : attendees) {
		Tree tmp(name);
		tmp.buildTree(attendees);
		auto tmpResult = tmp.calculateMaxHappiness(seatersRelation);
		result = std::max(result, tmpResult);
	
	}
	return result;
}

Node::Node(const std::string &_name, Node *_parent) : name(_name), parent(_parent) {}
Node::~Node() {
	for(const auto &child : children) {
		delete child;
	}
}

void Node::addChild(Node *child) {
	children.push_back(child);
}

std::string Node::getName() const {
	return name;
}

std::vector<Node *> Node::getChildren() {
	return children;
}

Node *Node::getParent() {
	return parent;
}

Tree::Tree(const std::string &_name) : root(new Node(_name, nullptr)) {}

Tree::~Tree() {
	delete root;
}

void Tree::buildTree(const std::vector<std::string> &_names) {
	buildTree(root, _names);
}

void Tree::buildTree(Node *node, const std::vector<std::string> &_names) {
	if(_names.empty()) {
		return;
	}
	auto names = _names;
	auto nodeName = std::find(names.begin(), names.end(), node->getName());
	if (nodeName == names.end()) {
		return;
	}	
	names.erase(nodeName);
	for (const auto &name : names) {
		Node *tmp = new Node(name, node);
		node->addChild(tmp);
		buildTree(tmp, names);
	}
}

int Tree::calculateMaxHappiness(const relationsValues &values) {
	auto ans{0};
	for(auto leaf : getLeafs()) {
		auto result{0};
		auto found = values.find(std::make_pair(root->getName(), leaf->getName()));
		if (found != values.end()) {
			result += found->second;
		}
		found = values.find(std::make_pair(leaf->getName(), root->getName()));
		if (found != values.end()) {
			result += found->second;
		}
		auto node = leaf;
		auto parent = leaf->getParent();

		while(parent) {
			auto found = values.find(std::make_pair(node->getName(), parent->getName()));
			if (found != values.end()) {
				result += found->second;
			}
			found = values.find(std::make_pair(parent->getName(), node->getName()));
			if (found != values.end()) {
				result += found->second;
			}
			node = node->getParent();
			parent = parent->getParent();
		}
		ans = std::max(ans, result);
	}
	return ans;
}

std::vector<Node*> Tree::getLeafs() {
	std::vector<Node*> leafs{};
	getLeafs(root,leafs);
	return leafs;
}

void Tree::getLeafs(Node *node, std::vector<Node *> &leaves) {
	if(!node) return;
	if(node->getChildren().empty()) {
		leaves.push_back(node);

	} else {
		for (Node *x : node->getChildren()) {
			getLeafs(x, leaves);
		}
	}
}

