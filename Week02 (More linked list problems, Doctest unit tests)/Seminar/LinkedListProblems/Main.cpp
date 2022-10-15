#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

#include <iostream>
#include "LinkedList.h"

TEST_CASE("Testing count method")
{
    LinkedList<int> list;
	for (size_t i = 0; i < 10; i++)
	{
		list.pushBack(i);
	}
	CHECK(list.count(2) == 1);
	CHECK(list.count(0) == 1);
	CHECK(list.count(42123) == 0);

	list.pushBack(2);
	CHECK(list.count(2) == 2);
}

TEST_CASE("Testing range constructor")
{
	LinkedList<int> list(10, 20);

	for (size_t i = 10, count = 0; i <= 20; i++, count++)
		CHECK(list[count] == i);

	LinkedList<int> listSwapped(10, 5);

	for (size_t i = 5, count = 0; i <= 10; i++, count++)
		CHECK(listSwapped[count] == i);
}

TEST_CASE("Testing +=")
{
	LinkedList<int> list;
	list += 12;
	list += 2;

	CHECK(list[0] == 12);
	CHECK(list[1] == 2);
}

TEST_CASE("Testing append")
{
	LinkedList<int> list;
	list.pushBack(0);
	list.pushBack(1);

	LinkedList<int> listScnd;
	listScnd.pushBack(2);
	listScnd.pushBack(3);

	list.append(listScnd);

	CHECK(list.getSize() == 4);

	for (size_t i = 0, count = 0; i <= 3; i++, count++)
		CHECK(list[count] == i);
}

int main()
{
	doctest::Context().run();

	return 0;
}
