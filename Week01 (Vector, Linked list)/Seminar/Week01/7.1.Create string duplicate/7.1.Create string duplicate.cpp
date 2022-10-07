#include <iostream>

char* strduplicate(const char* str)
{
    char* copy = new char[strlen(str) + 1];
    copy[strlen(str)] = '\0';

    size_t i;
    for (i = 0; i < strlen(str) && str[i] != '\0'; i++)
        copy[i] = str[i];

    return copy;
}

int main()
{
    const char* test = "testing";
    char* copy = strduplicate(test);
    std::cout << copy;

    delete[] copy;
    return 0;
}
