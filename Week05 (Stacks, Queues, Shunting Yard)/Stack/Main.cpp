#include <cassert>
#include "Stack.h"

void should_initalize_correctly_stack()
{
    Stack<int> stack;

    assert(stack.size() == 0);
    assert(stack.empty() == true);
}

void should_push_correctly_stack()
{
    Stack<int> stack;

    stack.push(12);
    assert(stack.top() == 12);

    stack.push(54);
    stack.push(99);
    assert(stack.top() == 99);
}

void should_pop_correctly_stack()
{
    Stack<int> stack;

    stack.push(12);
    stack.push(54);
    stack.push(99);
    // 99 54 12
    stack.pop();
    // 54 12
    assert(stack.top() == 54);
    stack.pop();
    // 12
    assert(stack.top() == 12);
    stack.pop();
    assert(stack.size() == 0);
    assert(stack.empty() == true);
}

void should_return_size_correctly_stack()
{
    Stack<int> stack;

    for (size_t i = 0; i < 15; i++)
        stack.push(i);

    assert(stack.size() == 15);

    for (size_t i = 0; i < 10; i++)
        stack.pop();

    assert(stack.size() == 5);

    for (size_t i = 0; i < 5; i++)
        stack.pop();

    assert(stack.empty() == true);
}

void should_copy_correctly_stack()
{
    Stack<int> stack;

    stack.push(12);
    stack.push(54);
    stack.push(99);

    Stack<int> copy(stack);

    assert(copy.top() == 99);
    assert(copy.size() == 3);
}

int main()
{
    should_initalize_correctly_stack();
    should_push_correctly_stack();
    should_pop_correctly_stack();
    should_return_size_correctly_stack();
    should_copy_correctly_stack();

    return 0;
}
