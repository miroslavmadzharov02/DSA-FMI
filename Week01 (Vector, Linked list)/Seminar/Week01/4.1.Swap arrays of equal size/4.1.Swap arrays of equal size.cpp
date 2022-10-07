#include <iostream>

template <typename T>
void swapArrays(T* arr1, T* arr2, const size_t& length)
{
    T temp;
    for (size_t i = 0; i < length; i++)
    {
        temp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp;
    }
}

template <typename T>
void printArray(const T* arr, const size_t& length)
{
    for (size_t i = 0; i < length; i++)
        std::cout << arr[i] << ' ';
    std::cout << '\n';
}

int main()
{
    int arr1[] = { 1,2,3,4,5,6 };
    int arr2[] = { -1,-2,-3,-4,-5,-6 };
    const size_t length = sizeof(arr1) / sizeof(arr1[0]);

    swapArrays(arr1, arr2, length);
    printArray(arr1, length);
    printArray(arr2, length);

    return 0;
}
