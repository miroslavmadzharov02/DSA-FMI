#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "Solutions.h"
using namespace Solutions;

TEST_CASE("Get vector of all the leaves in a tree")
{
	Node* testTree = new Node{ 5, new Node{14, new Node{4}, new Node{7}}, new Node{65, new Node{5}} };
	CHECK(listLeaves(testTree) == std::vector<int>{4, 7, 5});

	Node* testTreeSecond = new Node{ 5, new Node{14, new Node{4}, new Node{7}}, new Node{65, new Node{5}, new Node{99}} };
	CHECK(listLeaves(testTreeSecond) == std::vector<int>{4, 7, 5, 99});

	Node* onlyRoot = new Node{ 561 };
	CHECK(listLeaves(onlyRoot) == std::vector<int>{ 561 });

	Node* nullTree = nullptr;
	CHECK(listLeaves(nullTree) == std::vector<int>());
}

TEST_CASE("Get string of trace for particular element in binary tree.")
{
	Node* testTree = new Node{ 10, new Node{5}, new Node{20, new Node{15}, new Node{25}} };	
	CHECK(findTrace(testTree, 10) == "_");
	CHECK(findTrace(testTree, 5) == "L");
	CHECK(findTrace(testTree, 20) == "R");
	CHECK(findTrace(testTree, 25) == "RR");
}

TEST_CASE("Get value at index of root-left-right traversal.")
{
	Node* testTree = new Node{ 10, new Node{5}, new Node{20, new Node{15}, new Node{25}} };
	CHECK(getAt(testTree, 0) == 10);
	CHECK(getAt(testTree, 1) == 5);
	CHECK(getAt(testTree, 2) == 20);
	CHECK(getAt(testTree, 4) == 25);
}

TEST_CASE("Get perfectly balanced binary tree by height")
{
	Node* testTree = getPerfectlyBalancedTreeByHeight(3);
	std::vector<int> expected{ 0, 1, 2, 2, 1, 2, 2 };
	CHECK(inOrderTraversalIntoVector(testTree) == expected);

	Node* testTreeSecond = getPerfectlyBalancedTreeByHeight(4);
	std::vector<int> expectedSecond{ 0,1,2,3,3,2,3,3,1,2,3,3,2,3,3 };
	CHECK(inOrderTraversalIntoVector(testTreeSecond) == expectedSecond);
}

int main()
{
	doctest::Context().run();

	return 0;
}
