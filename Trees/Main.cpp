#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "TreeMethods.h"
using namespace TreeMethods;

TEST_CASE("In order binary tree (DFS)")
{
    Node* testTree = new Node{ 6, new Node{14, new Node{4}, new Node{7}}, new Node{65, new Node{5}} };

    CHECK(inorder(testTree) == std::vector<int>{4, 14, 7, 6, 5, 65});
}

TEST_CASE("Level order traversal binary tree (BFS)")
{
    Node* testTree = new Node{ 6, new Node{14, new Node{4}, new Node{7}}, new Node{65, new Node{5}} };

    CHECK(levelOrder(testTree) == std::vector<std::vector<int> >{ {6}, { 14, 65 }, { 4, 7, 5 }});
}

TEST_CASE("Max value in binary tree")
{
    Node* testTree = new Node{ 6, new Node{14, new Node{4}, new Node{7}}, new Node{65, new Node{5}} };

    CHECK(maxValueBinaryTree(testTree) == 65);
}

TEST_CASE("Invert binary tree")
{
    Node* testTree = new Node{ 6, new Node{14, new Node{4}, new Node{7}}, new Node{65, new Node{5}} };

    CHECK(inorder(invertBinaryTree(testTree)) == std::vector<int>{65, 5, 6, 7, 14, 4});
}

int main()
{
    doctest::Context().run();

    return 0;
}
