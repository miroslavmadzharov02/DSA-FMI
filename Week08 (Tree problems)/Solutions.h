#ifndef SOLUTIONS__
#define SOLUTIONS

#include "Node.h"

namespace Solutions
{
	size_t sizeBinaryTree(Node* root);
	size_t amountEvenNumbersBinaryTree(Node* root);
	size_t searchCount(Node* root, bool(*criteria)(const int&));
	size_t heightBinaryTree(Node* root);
	size_t amountOfLeavesBinaryTree(Node* root);
	int maxLeaf(Node* root, int& maxValue);
	int getValueFromStringInstructions(Node* root, const char* string);
	void prettyPrint(Node* root, const int& indent = 0);
};

#endif 