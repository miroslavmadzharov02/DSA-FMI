#include "LinkedList.h"
#include "Vector.h"
#include "ContainerMethods.h"
#include <cassert>
using namespace ContainerMethods;

void print(const int& val)
{
	std::cout << val << '\n';
}

void should_test_map_linked_list()
{
	LinkedList<int> list;
	for (size_t i = 1; i <= 5; i++)
		list.pushBack(i);

	map(print, list);
}

void should_test_duplicates_linked_list()
{
	LinkedList<int> list;
	for (size_t i = 1; i <= 5; i++)
		list.pushBack(i);

	assert(duplicates(list) == false);

	list.pushBack(3);

	assert(duplicates(list));
}

void should_test_is_sorted_linked_list()
{
	LinkedList<int> listAsc;
	for (size_t i = 1; i <= 5; i++)
		listAsc.pushBack(i);

	assert(isSortedAscending(listAsc));
	assert(isSortedDescending(listAsc) == false);
	
	LinkedList<int> listDesc;
	for (size_t i = 10; i >= 5; i--)
		listDesc.pushBack(i);

	assert(isSortedAscending(listDesc) == false);
	assert(isSortedDescending(listDesc));
}

void should_test_palindrome_linked_list()
{
	LinkedList<int> list;
	for (size_t i = 1; i <= 5; i++)
		list.pushBack(i);
	for (size_t i = 5; i >= 1; i--)
		list.pushBack(i);

	assert(palindrome(list));

	list.pushBack(10);
	assert(palindrome(list) == false);
}

void should_test_map_vector()
{
	Vector<int> vec;
	for (size_t i = 1; i <= 5; i++)
		vec.pushBack(i);

	map(print, vec);
}

void should_test_duplicates_vector()
{
	Vector<int> vec;
	for (size_t i = 1; i <= 5; i++)
		vec.pushBack(i);

	assert(duplicates(vec) == false);

	vec.pushBack(3);

	assert(duplicates(vec));
}

void should_test_is_sorted_vector()
{
	Vector<int> vecAsc;
	for (size_t i = 1; i <= 5; i++)
		vecAsc.pushBack(i);

	assert(isSortedAscending(vecAsc));
	assert(isSortedDescending(vecAsc) == false);

	Vector<int> vecDesc;
	for (size_t i = 10; i >= 5; i--)
		vecDesc.pushBack(i);

	assert(isSortedAscending(vecDesc) == false);
	assert(isSortedDescending(vecDesc));
}

void should_test_palindrome_vector()
{
	Vector<int> vec;
	for (size_t i = 1; i <= 5; i++)
		vec.pushBack(i);
	for (size_t i = 5; i >= 1; i--)
		vec.pushBack(i);

	assert(palindrome(vec));

	vec.pushBack(10);
	assert(palindrome(vec) == false);
}

int main()
{
	//should_test_map_linked_list();
	should_test_duplicates_linked_list();
	should_test_is_sorted_linked_list();
	should_test_palindrome_linked_list();

	//should_test_map_vector();
	should_test_duplicates_vector();
	should_test_is_sorted_vector();
	should_test_palindrome_vector();

	return 0;
}
