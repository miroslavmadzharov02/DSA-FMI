#include <iostream>

size_t strlength(const char* str)
{
	int i = -1;
	do
	{
		i++;
	} while (*str++ != '\0');
	return i;
}

void strcopy_safe(char* dest, const char* src, const size_t& size)
{
	size_t i;
	for (i = 0; i < size - 1 && src[i] != '\0'; ++i)
		dest[i] = src[i];
	dest[i] = '\0';
}

char* append(char*& dest, const char* stringToAppend)
{
	const size_t originalStringLength = strlength(dest);
	const size_t appendedStringLength = strlength(dest) + strlength(stringToAppend);

	char* temp = new char[appendedStringLength + 1];
	temp[appendedStringLength] = '\0';
	for (size_t i = 0; i < originalStringLength; i++)
		temp[i] = dest[i];
	for (size_t i = originalStringLength, j = 0; i < appendedStringLength; i++, j++)
		temp[i] = stringToAppend[j];

	dest = new char[appendedStringLength + 1];
	for (size_t i = 0; i < appendedStringLength; i++)
		dest[i] = temp[i];
	dest[appendedStringLength] = '\0';

	delete[] temp;
	return dest;
}

char* removeDuplicateSymbols(char* str)
{
	int count = 0;
	const size_t length = strlength(str);

	for (size_t i = 0; i < length; i++) 
	{
		size_t j;
		for (j = 0; j < i; j++)
			if (str[i] == str[j])
				break;

		if (j == i)
			str[count++] = str[i];
	}

	char* result = new char[count + 1];
	strcopy_safe(result, str, count + 1);
	return result;
}

int main()
{
    char* str1 = (char*)"testing";
	const char* str2 = " test 1231234";

	char* appendedStr = append(str1, str2);
	std::cout << appendedStr << '\n';

	char* noDuplicatesStr = removeDuplicateSymbols(appendedStr);
	std::cout << noDuplicatesStr << '\n';

	delete[] noDuplicatesStr;
    return 0;
}
