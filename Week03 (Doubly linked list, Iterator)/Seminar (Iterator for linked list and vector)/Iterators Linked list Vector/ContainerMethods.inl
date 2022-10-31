#include "ContainerMethods.h"
#include <unordered_map>
#include <vector>

template<typename func, typename container>
void ContainerMethods::map(func f, container& vec)
{
	for (typename container::iterator it = vec.begin(); it != vec.end(); ++it)
		f(*it);
}

template<typename container>
bool ContainerMethods::duplicates(container& vec)
{
	std::unordered_map<container::value_type, container::value_type> map;
	for (typename container::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		if (map.find(*it) != map.end())
			return true;
		map[*it] = 1;
	}

	return false;
}

template<typename container>
bool ContainerMethods::isSortedAscending(container& vec)
{
	typename container::iterator it = vec.begin();
	typename container::value_type previous = *it;
	++it;

	for (; it != vec.end(); ++it)
	{
		if (previous > *it)
			return false;
		previous = *it;
	}

	return true;
}

template<typename container>
bool ContainerMethods::isSortedDescending(container& vec)
{
	typename container::iterator it = vec.begin();
	typename container::value_type previous = *it;
	++it;

	for (; it != vec.end(); ++it)
	{
		if (previous < *it)
			return false;
		previous = *it;
	}

	return true;
}

template<typename container>
bool ContainerMethods::palindrome(container& vec)
{
	std::vector<container::value_type> reversedVec;
	for (typename container::iterator it = vec.begin(); it != vec.end(); ++it)
		reversedVec.push_back(*it);

	std::reverse(reversedVec.begin(), reversedVec.end());

	size_t i = 0;
	for (typename container::iterator it = vec.begin(); it != vec.end(); ++it, ++i)
		if (*it != reversedVec[i])
			return false;

	return true;
}
