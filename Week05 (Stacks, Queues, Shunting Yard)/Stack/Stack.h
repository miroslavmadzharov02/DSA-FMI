#ifndef STACK__
#define STACK__

#include <cassert>

template <typename T>
class Stack
{
private:
	T* data_ = nullptr;
	size_t size_ = 0;
	size_t capacity_ = 2;

	void resize();
	void copy(const Stack<T>& other);
	void del();

public:
	Stack();
	Stack(const Stack<T>& other);
	~Stack();

	void push(const T& elem);
	void pop();
	bool empty() const;
	const size_t size() const;

	const T& top() const;
};

#include "Stack.inl"
#endif 