#include <iostream>

bool duplicates(long* pointers[], const size_t& length)
{
	for (size_t i = 0; i < length; i++)
		for (size_t j = i + 1; j < length; j++)
			if (*pointers[i] == *pointers[j])
				return true;
	return false;
}

int main()
{
	long temp1 = 123, temp2 = 324, temp3 = 211, temp4 = 123;
	long* pointers[] = { &temp1, &temp2, &temp3, &temp4 };
	const size_t length = 4;

	std::cout << std::boolalpha << duplicates(pointers, length);

    return 0;
}
