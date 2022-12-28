#ifndef QUEUE__
#define QUEUE__

template <typename T>
class Queue
{
private:
	T* data_ = nullptr;
	size_t front_ = 0;
	size_t back_ = 0;
	size_t capacity_ = 2;

	void resize();
	void del();

public:
	Queue();
	Queue(const Queue& other);
	~Queue();

	const T& front() const;
	const T& back() const;

	void push(const T& elem);
	void pop();
	const size_t size() const;
	bool empty() const;
};

#include "Queue.inl"
#endif 