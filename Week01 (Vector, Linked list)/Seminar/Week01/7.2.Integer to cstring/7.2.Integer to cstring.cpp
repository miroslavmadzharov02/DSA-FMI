#include <iostream>

int power(const int& number, const int& pow)
{
	int result = 1;

	for (size_t i = 0; i < pow; i++)
		result *= number;

	return result;
}

size_t digitsAmount(size_t number)
{
	size_t digits = 0;
	while (number) 
	{
		number /= 10;
		digits++;
	}
	return digits;
}

char* intToStr(size_t number)
{
	char* result = new char[digitsAmount(number) + 1];
	result[digitsAmount(number)] = '\0';

	for (size_t i = 0; result[i] != '\0'; i++)
	{
		result[i] = number / (power(10, digitsAmount(number) - 1)) + '0';
		number = number % (power(10, digitsAmount(number) - 1));
	}

	return result;
}

int main()
{
	char* str = intToStr(123456);
	std::cout << str;

	delete[] str;
	return 0;
}
