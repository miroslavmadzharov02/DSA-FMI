#include "Solutions.h"
#include <stack>

using namespace Solutions;

std::vector<int> Solutions::listLeaves(Node* root)
{
	if (root == nullptr)
		return std::vector<int>();

	if (root->left == nullptr && root->right == nullptr)
		return std::vector<int>({ root->data });

	std::vector<int> leaves;

	std::vector<int> leftLeaves = listLeaves(root->left);
	std::vector<int> rightLeaves = listLeaves(root->right);

	leaves.insert(leaves.begin(), leftLeaves.begin(), leftLeaves.end());
	leaves.insert(leaves.end(), rightLeaves.begin(), rightLeaves.end());

	return leaves;
}

void dfs(Node* root, const int& elem, std::stack<std::string>& stack, bool& found)
{
	if (root == nullptr)
		return;

	if (root->data == elem)
	{
		found = true;
		return;
	}
	
	if (root->left != nullptr && found == false)
	{
		stack.push("L");
		dfs(root->left, elem, stack, found);
		if (found == false)
			stack.pop();
	}
	if (root->right != nullptr && found == false)
	{
		stack.push("R");
		dfs(root->right, elem, stack, found);
		if (found == false)
			stack.pop();
	}
}

std::string Solutions::findTrace(Node* root, const int& elem)
{
	if (root != nullptr && root->data == elem)
		return "_";

	std::stack<std::string> traceStack;
	bool found = false;
	dfs(root, elem, traceStack, found);

	std::string trace;
	const size_t traceStackSize = traceStack.size();
	for (size_t i = 0; i < traceStackSize; i++)
	{
		trace += traceStack.top();
		traceStack.pop();
	}

	return trace;
}

std::vector<int> Solutions::inOrderTraversalIntoVector(Node* root)
{
	std::vector<int> result;

	if (root == nullptr)
		return result;

	std::vector<int> left = inOrderTraversalIntoVector(root->left);
	std::vector<int> right = inOrderTraversalIntoVector(root->right);

	result.push_back(root->data);
	result.insert(result.end(), left.begin(), left.end());
	result.insert(result.end(), right.begin(), right.end());

	return result;
}

int Solutions::getAt(Node* root, const size_t& indexToSeek)
{
	return inOrderTraversalIntoVector(root)[indexToSeek];
}

Node* populateTree(const int& index, const size_t& height)
{
	Node* root = nullptr;

	if (index >= height - 1)
	{
		root = new Node{ index };
		root->left = populateTree(index + 1, height);
		root->right = populateTree(index + 1, height);
	}

	return root;
}

Node* Solutions::getPerfectlyBalancedTreeByHeight(const size_t& height)
{
	return populateTree(0, height);
}
