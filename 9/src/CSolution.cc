#include "CSolution.h"
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <list>
#include <memory>
#include <numeric>
#include <set>
#include <utility>


void CSolution::setData(const std::vector<std::string> &_input) {
	analyzeInput(_input);
}

int CSolution::getResultPart1() {
	return result1;
}

int CSolution::getResultPart2() {
	return result2;
}

void CSolution::solution() {
	std::vector<int> shortestDistances{};
	std::vector<int> longestDistance{};
	for (const auto &citi : cities) {
		shortestDistances.push_back(findShortestDistanceFrom(citi));
		longestDistance.push_back(findLongestDistanceFrom(citi));
	}
	result1 = *std::min_element(shortestDistances.begin(), shortestDistances.end());
	result2 = *std::max_element(longestDistance.begin(), longestDistance.end());

}

int CSolution::findShortestDistanceFrom(const std::string &_city) {
	Tree tree(_city);
	tree.buildTree(cities, distances);
	return tree.getMinDistance();
}

int CSolution::findLongestDistanceFrom(const std::string &_city) {
	Tree tree(_city);
	tree.buildTree(cities, distances);
	return tree.getMaxDistance();
}

void CSolution::analyzeInput(const std::vector<std::string> &_input) {
	std::set<std::string> tmp{};
	for (const auto &line : _input) {
		char from[20], to[20];
		int distance;
		sscanf(line.data(), "%s to %s = %d", from, to, &distance);
		distances[{from, to}] = distance;
		distances[{to, from}] = distance;
		tmp.insert(from);
		tmp.insert(to);
	}
	cities = std::list<std::string>(tmp.begin(), tmp.end());

}

void CSolution::printDistances() {
	for (const auto &i : distances) {
		std::cout << "from " << i.first.first << " to " 
			<< i.first.second << " = " << std::to_string(i.second) << std::endl;
	}
}


Node::Node(const std::string &_city, const int _distance) : city(_city), distance(_distance) {} 

void Node::addChild(std::shared_ptr<Node> child) {
	children.emplace_back(std::move(child));
}

std::string Node::getName() {
	return city;
}

const int Node::getDistance() {
	return distance;
}

bool Node::hasChild() {
	return !children.empty();
}

std::list<std::shared_ptr<Node>> Node::getChildren() {
	return children;
}


Tree::Tree(const std::string &startingCity) {
	root = std::shared_ptr<Node>(new Node(startingCity, 0));
}

void Tree::buildTree(const std::list<std::string> &cities, const std::map<std::pair<std::string, std::string>, int> &_distances) {
	buildTree(root, cities, _distances);
}

void Tree::buildTree(
		const std::shared_ptr<Node> &node,
		const std::list<std::string> &cities,
		const std::map<std::pair<std::string, std::string>, int> &_distances) {
	auto newCities = std::move(cities);
	newCities.remove(node->getName());
	for (const auto &city: newCities) {
		auto vIter = _distances.find(std::make_pair(node->getName(), city));
		if (vIter == _distances.end()) {
			continue;
		}
		auto tmp = std::shared_ptr<Node>(new Node(city, node->getDistance() + vIter->second)); 
		node->addChild(std::shared_ptr<Node>(tmp));
		buildTree(tmp, newCities, _distances);
	}
}

void Tree::print() {
	tree = "" ;
	getTree(root, &tree);
	std::cout << tree << std::endl;
}

void Tree::getTree(const std::shared_ptr<Node> &node, std::string *path) {
	*path = *path + node->getName();
	if (!node->hasChild()) {
		tree = *path + "\n";
		return;
	}
	*path += " - ";
	for (const auto &child : node->getChildren()) {
		getTree(child, path);
	}
}

std::string Tree::getTree() {
	tree = "";
	getTree(root, &tree);
	return tree;
}

int Tree::getMinDistance() {
	getMin(root);
	return minDistance;
}

int Tree::getMaxDistance() {
	getMax(root);
	return maxDistance;
}

void Tree::getMin(const std::shared_ptr<Node> &node) {
	if (!node->hasChild()) {
		minDistance = minDistance > node->getDistance() ? node->getDistance() : minDistance;
		return;
	}
	for (const auto &node : node->getChildren()) {
		getMin(node);
	}
}

void Tree::getMax(const std::shared_ptr<Node> &node) {
	if (!node->hasChild()) {
		maxDistance = maxDistance < node->getDistance() ? node->getDistance() : maxDistance;
		return;
	}
	for (const auto &node : node->getChildren()) {
		getMax(node);
	}
}
