#ifndef SOLUTIONS__
#define SOLUTIONS__

#include <vector>
#include <string>
#include "Node.h"

namespace Solutions
{
	std::vector<int> inOrderTraversalIntoVector(Node* root);

	std::vector<int> listLeaves(Node* root);
	std::string findTrace(Node* root, const int& elem);
	int getAt(Node* root, const size_t& indexToSeek);
	Node* getPerfectlyBalancedTreeByHeight(const size_t& height);
};

#endif