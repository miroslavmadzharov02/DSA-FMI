#ifndef TREEMETHODS__
#define TREEMETHODS__

#include <iostream>
#include <queue>
#include <vector>
#include "Node.h"

namespace TreeMethods
{
	//DFS 
	void printPreorder(Node* root);
	void printInorder(Node* root);
	void printPostorder(Node* root);
	std::vector<int> inorder(Node* root);

	//BFS
	std::vector<std::vector<int> > levelOrder(Node* root);

	size_t sizeBinaryTree(Node* root);
	size_t heightBinaryTree(Node* root);
	int maxValueBinaryTree(Node* root);
	Node* invertBinaryTree(Node* root);
};

#endif