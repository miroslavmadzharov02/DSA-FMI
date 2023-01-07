#include "TreeMethods.h"

void TreeMethods::printPreorder(Node* root)
{
	if (root == nullptr)
		return;

	std::cout << root->data << " ";
	printPreorder(root->left);
	printPreorder(root->right);
}

void TreeMethods::printInorder(Node* root)
{
	if (root == nullptr)
		return;

	printInorder(root->left);
	std::cout << root->data << " ";
	printInorder(root->right);
}

void TreeMethods::printPostorder(Node* root)
{
	if (root == nullptr)
		return;

	printPostorder(root->left);
	printPostorder(root->right);
	std::cout << root->data << " ";
}

void inorderRecursive(Node* root, std::vector<int>& vec)
{
	if (root == nullptr)
		return;

	inorderRecursive(root->left, vec);
	vec.push_back(root->data);
	inorderRecursive(root->right, vec);
}

std::vector<int> TreeMethods::inorder(Node* root)
{
	std::vector<int> result;
	inorderRecursive(root, result);
	return result;
}

std::vector<std::vector<int>> TreeMethods::levelOrder(Node* root)
{
	if (root == nullptr)
		return {};

	std::vector<int> level;
	std::vector<std::vector<int> > result;
	std::queue<Node*> queue;
	size_t count = 1;

	queue.push(root);
	while (!queue.empty())
	{
		if (queue.front()->left != nullptr)
			queue.push(queue.front()->left);
		if (queue.front()->right != nullptr)
			queue.push(queue.front()->right);

		level.push_back(queue.front()->data);
		queue.pop();

		if (--count == 0)
		{
			result.push_back(level);
			level.clear();

			count = queue.size();
		}
	}

	return result;
}

size_t TreeMethods::sizeBinaryTree(Node* root)
{
	if (root == nullptr)
		return 0;

	return 1 + sizeBinaryTree(root->left) + sizeBinaryTree(root->right);
}

size_t TreeMethods::heightBinaryTree(Node* root)
{
	if (root == nullptr)
		return -1;

	size_t leftHeight = heightBinaryTree(root->left);
	size_t rightHeight = heightBinaryTree(root->right);

	return leftHeight >= rightHeight ? leftHeight + 1 : rightHeight + 1;
}

void maxValueRecursion(Node* root, int& max)
{
	if (root == nullptr)
		return;

	if (root->data > max)
		max = root->data;

	maxValueRecursion(root->left, max);
	maxValueRecursion(root->right, max);
}

int TreeMethods::maxValueBinaryTree(Node* root)
{
	int maxValue;
	maxValueRecursion(root, maxValue);
	return maxValue;
}

Node* TreeMethods::invertBinaryTree(Node* root)
{
	if (root == nullptr)
		return root;

	Node* keepLeft = root->left;
	root->left = root->right;
	root->right = keepLeft;

	invertBinaryTree(root->left);
	invertBinaryTree(root->right);

	return root;
}
