#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "Solutions.h"
using namespace Solutions;

TEST_CASE("Binary tree size")
{
    Node* testTree = new Node{ 5, new Node{14, new Node{4}, new Node{7}}, new Node{65, new Node{5}} };

    CHECK(sizeBinaryTree(testTree) == 6);

    Node* onlyRoot = new Node{561};
    CHECK(sizeBinaryTree(onlyRoot) == 1);
}

TEST_CASE("Amount of even numbers in binary tree")
{
    Node* testTree = new Node{ 6, new Node{14, new Node{4}, new Node{7}}, new Node{65, new Node{5}} };

    CHECK(amountEvenNumbersBinaryTree(testTree) == 3);

    Node* testTreeSecond = new Node{ 2, new Node{7, new Node{7}, new Node{7}}, new Node{7, new Node{2}} };
    CHECK(amountEvenNumbersBinaryTree(testTreeSecond) == 2);

    Node* testTreeNoEvens = new Node{ 5, new Node{15, new Node{9}, new Node{7}}, new Node{65, new Node{5}} };
    CHECK(amountEvenNumbersBinaryTree(testTreeNoEvens) == 0);
}

TEST_CASE("Amount of nodes that fulfil predicate (size of tree)")
{
    Node* testTree = new Node{ 5, new Node{14, new Node{4}, new Node{7}}, new Node{65, new Node{5}} };

    CHECK(searchCount(testTree, [](const int&) {return true; }) == 6);

    Node* onlyRoot = new Node{ 561 };
    CHECK(searchCount(onlyRoot, [](const int&) {return true; }) == 1);
}

TEST_CASE("Amount of nodes that fulfil predicate (Even numbers)")
{
    Node* testTree = new Node{ 6, new Node{14, new Node{4}, new Node{7}}, new Node{65, new Node{5}} };

    CHECK(searchCount(testTree, [](const int& val) {return val % 2 == 0; }) == 3);

    Node* testTreeSecond = new Node{ 2, new Node{7, new Node{7}, new Node{7}}, new Node{7, new Node{2}} };
    CHECK(searchCount(testTreeSecond, [](const int& val) {return val % 2 == 0; }) == 2);

    Node* testTreeNoEvens = new Node{ 5, new Node{15, new Node{9}, new Node{7}}, new Node{65, new Node{5}} };
    CHECK(searchCount(testTreeNoEvens, [](const int& val) {return val % 2 == 0; }) == 0);
}

TEST_CASE("Height of binary tree")
{
    Node* testTree = new Node{ 6, new Node{14, new Node{4}, new Node{7}}, new Node{65, new Node{5}} };

    CHECK(heightBinaryTree(testTree) == 3);

    Node* testTreeSecond = 
        new Node{ 2, new Node{7, new Node{7, new Node{1, new Node{4, new Node{3}}}}, 
        new Node{7}}, new Node{7, new Node{2, new Node{5}, new Node{6}}} };
    CHECK(heightBinaryTree(testTreeSecond) == 6);
}

TEST_CASE("Amount of leaves in a binary tree")
{
    Node* testTree = new Node{ 6, new Node{14, new Node{4}, new Node{7}}, new Node{65, new Node{5}} };

    CHECK(amountOfLeavesBinaryTree(testTree) == 3);

    Node* testTreeSecond =
        new Node{ 2, new Node{7, new Node{7, new Node{1, new Node{4, new Node{3}}}},
        new Node{7}}, new Node{7, new Node{2, new Node{5}, new Node{6}}} };
    CHECK(amountOfLeavesBinaryTree(testTreeSecond) == 4);
}

TEST_CASE("Maximum value of leaves in a binary tree")
{
    Node* testTree = new Node{ 4, new Node{14, new Node{8}, new Node{7}}, new Node{65, new Node{5}} };

    int maxValue = 0;
    CHECK(maxLeaf(testTree, maxValue) == 8);

    Node* testTreeSecond =
        new Node{ 2, new Node{7, new Node{7, new Node{1, new Node{4, new Node{789}}}},
        new Node{7}}, new Node{7, new Node{2, new Node{5}, new Node{6}}} };

    CHECK(maxLeaf(testTreeSecond, maxValue) == 789);
}

TEST_CASE("Get node value from string instructions")
{
    Node* testTree = new Node{ 4, new Node{14, new Node{8}, new Node{7}}, new Node{65, new Node{5}} };

    CHECK(getValueFromStringInstructions(testTree, "L") == 14);
    CHECK(getValueFromStringInstructions(testTree, "R") == 65);
    CHECK(getValueFromStringInstructions(testTree, "RL") == 5);
    CHECK(getValueFromStringInstructions(testTree, "LL") == 8);
}

int main()
{
    doctest::Context().run();

    //Node* testTree = new Node{ 10, new Node{5}, new Node{20, new Node{15}, new Node{25}} };
    //prettyPrint(testTree);

    return 0;
}
