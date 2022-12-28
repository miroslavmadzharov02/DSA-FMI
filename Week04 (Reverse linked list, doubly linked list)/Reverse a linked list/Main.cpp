#include "LinkedList.h"
#include <cassert>

void should_test_reversing_linked_list()
{
    LinkedList<int> list{ 1,2,3,4,5 };

    list.reverse();

    size_t expectedVal = 5;
    for (typename LinkedList<int>::iterator it = list.begin(); it != list.end(); ++it, --expectedVal)
        assert(*it == expectedVal);

    list.reverse();

    ++expectedVal;
    for (typename LinkedList<int>::iterator it = list.begin(); it != list.end(); ++it, ++expectedVal)
        assert(*it == expectedVal);
}

int main()
{
    should_test_reversing_linked_list();

    return 0;
}
