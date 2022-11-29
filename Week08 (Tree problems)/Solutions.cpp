#include "Solutions.h"
#include <cstring>
#include <iostream>
#include <iomanip>

size_t Solutions::sizeBinaryTree(Node* root)
{
	if (root == nullptr)
		return 0;

	return 1 + sizeBinaryTree(root->left) + sizeBinaryTree(root->right);
}

size_t Solutions::amountEvenNumbersBinaryTree(Node* root)
{
	if (root == nullptr)
		return 0;

	if (root->data % 2 == 0)
		return 1 + amountEvenNumbersBinaryTree(root->left) + amountEvenNumbersBinaryTree(root->right);
	else
		return amountEvenNumbersBinaryTree(root->left) + amountEvenNumbersBinaryTree(root->right);
}

size_t Solutions::searchCount(Node* root, bool(*criteria)(const int&))
{
	if (root == nullptr)
		return 0;

	if (criteria(root->data))
		return 1 + searchCount(root->left, criteria) + searchCount(root->right, criteria);
	else
		return searchCount(root->left, criteria) + searchCount(root->right, criteria);
}

size_t Solutions::heightBinaryTree(Node* root)
{
	if (root == nullptr)
		return 0;

	size_t leftHeight = heightBinaryTree(root->left);
	size_t rightHeight = heightBinaryTree(root->right);

	return leftHeight >= rightHeight ? leftHeight + 1 : rightHeight + 1;
}

size_t Solutions::amountOfLeavesBinaryTree(Node* root)
{
	if (root == nullptr)
		return 0;

	if (root->left == nullptr && root->right == nullptr)
		return 1;

	return amountOfLeavesBinaryTree(root->left) + amountOfLeavesBinaryTree(root->right);
}

int Solutions::maxLeaf(Node* root, int& maxValue)
{
	if (root == nullptr)
		return 0;

	if (root->left == nullptr && root->right == nullptr)
		if (root->data > maxValue)
			maxValue = root->data;

	maxLeaf(root->left, maxValue);
	maxLeaf(root->right, maxValue);

	return maxValue;
}

int Solutions::getValueFromStringInstructions(Node* root, const char* string)
{
	if (root == nullptr || strlen(string) == 0)
		return 0;

	while (*string != '\0')
	{
		if (*string == 'L' && root != nullptr)
			root = root->left;
		else if (*string == 'R' && root != nullptr)
			root = root->right;
		string++;
	}

	return root == nullptr ? 0 : root->data;
}

void Solutions::prettyPrint(Node* root, const int& indent)
{
	if (root == nullptr)
		return;

	if (root->right != nullptr)
		prettyPrint(root->right, indent + 4);
	if (root->left != nullptr)
		prettyPrint(root->left, indent + 4);
	if (indent != 0)
		std::cout << std::setw(indent) << ' ';
	std::cout << root->data << '\n' << '\n';
}
