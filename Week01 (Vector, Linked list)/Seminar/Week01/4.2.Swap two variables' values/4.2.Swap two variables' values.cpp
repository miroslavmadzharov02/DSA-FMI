#include <iostream>

template <typename T>
void swap(T& value1, T& value2)
{
	T temp = value1;
	value1 = value2;
	value2 = temp;
}

int main()
{
	int value1 = 2;
	int value2 = 6;

	swap(value1, value2);

	std::cout << value1 << " " << value2 << '\n';

	return 0;
}
