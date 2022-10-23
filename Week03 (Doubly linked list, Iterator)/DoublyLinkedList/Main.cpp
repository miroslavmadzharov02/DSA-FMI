#include "DoublyLinkedList.h"
#include <cassert>

void should_insert_to_front_of_doubly_linked_list()
{
    DoublyLinkedList<int> list;
    list.pushFront(2);
    assert(std::vector<int>({ 2 }) == list.toVector());

    list.pushFront(12);
    assert(std::vector<int>({ 2,12 }) != list.toVector());
    assert(std::vector<int>({ 12,2 }) == list.toVector());

    list.pushFront(100);
    assert(std::vector<int>({ 100,12,2 }) == list.toVector());
}

void should_insert_to_back_of_doubly_linked_list()
{
    DoublyLinkedList<int> list;
    list.pushBack(2);
    assert(std::vector<int>({ 2 }) == list.toVector());

    list.pushBack(12);
    assert(std::vector<int>({ 2,12 }) == list.toVector());

    list.pushBack(100);
    assert(std::vector<int>({ 2,12,100 }) == list.toVector());
}

void should_copy_other_doubly_linked_list()
{
    DoublyLinkedList<int> list;
    for (size_t i = 1; i <= 5; i++)
        list.pushBack(i);
    
    DoublyLinkedList<int> listCopy(list);
    assert(std::vector<int>({ 1,2,3,4,5 }) == listCopy.toVector());
}

void should_pop_from_front_of_doubly_linked_list()
{
    DoublyLinkedList<int> list;
    for (size_t i = 1; i <= 5; i++)
        list.pushBack(i);

    list.popFront();
    assert(std::vector<int>({ 2,3,4,5 }) == list.toVector());

    list.popFront();
    list.popFront();
    assert(std::vector<int>({ 4,5 }) == list.toVector());

    list.popFront();
    list.popFront();
    assert(std::vector<int>({}) == list.toVector());
}

void should_pop_from_back_of_doubly_linked_list()
{
    DoublyLinkedList<int> list;
    for (size_t i = 1; i <= 5; i++)
        list.pushBack(i);

    list.popBack();
    assert(std::vector<int>({ 1,2,3,4 }) == list.toVector());

    list.popBack();
    list.popBack();
    assert(std::vector<int>({ 1,2 }) == list.toVector());

    list.popBack();
    list.popBack();
    assert(std::vector<int>({}) == list.toVector());
}

void should_return_correct_doubly_linked_list_size()
{
    DoublyLinkedList<int> list;
    for (size_t i = 1; i <= 5; i++)
        list.pushBack(i);

    assert(list.getSize() == 5);

    list.popBack();
    list.popFront();
    assert(list.getSize() == 3);
}

int main()
{
    should_insert_to_front_of_doubly_linked_list();
    should_insert_to_back_of_doubly_linked_list();
    should_copy_other_doubly_linked_list();
    should_pop_from_front_of_doubly_linked_list();
    should_pop_from_back_of_doubly_linked_list();
    should_return_correct_doubly_linked_list_size();

    return 0;
}
