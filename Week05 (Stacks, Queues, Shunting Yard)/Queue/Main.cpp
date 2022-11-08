#include <cassert>
#include "Queue.h"

void should_initalize_correctly_queue()
{
    Queue<int> queue;

    assert(queue.size() == 0);
    assert(queue.empty() == true);
}

void should_push_correctly_queue()
{
    Queue<int> queue;

    queue.push(12);
    assert(queue.front() == 12);
    assert(queue.back() == 12);

    queue.push(54);
    queue.push(99);
    assert(queue.front() == 12);
    assert(queue.back() == 99);
}

void should_pop_correctly_queue()
{
    Queue<int> queue;

    queue.push(12);
    queue.push(54);
    queue.push(99);
    // 99 54 12
    queue.pop();
    // 99 54
    assert(queue.front() == 54);
    assert(queue.back() == 99);
    queue.pop();
    // 99
    assert(queue.front() == 99);
    assert(queue.back() == 99);
    queue.pop();
    assert(queue.size() == 0);
    assert(queue.empty() == true);
}

void should_return_size_correctly_queue()
{
    Queue<int> queue;

    for (size_t i = 0; i < 15; i++)
        queue.push(i);

    assert(queue.size() == 15);

    for (size_t i = 0; i < 10; i++)
        queue.pop();

    assert(queue.size() == 5);

    for (size_t i = 0; i < 5; i++)
        queue.pop();

    assert(queue.empty() == true);
}

void should_copy_correctly_queue()
{
    Queue<int> queue;

    queue.push(12);
    queue.push(54);
    queue.push(99);

    Queue<int> copy(queue);

    assert(copy.front() == 12);
    assert(queue.back() == 99);
    assert(copy.size() == 3);
}

int main()
{
    should_initalize_correctly_queue();
    should_push_correctly_queue();
    should_pop_correctly_queue();
    should_return_size_correctly_queue();
    should_copy_correctly_queue();

    return 0;
}
