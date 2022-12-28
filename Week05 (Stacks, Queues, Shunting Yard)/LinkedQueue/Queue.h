#ifndef QUEUE__
#define QUEUE__

#include <cassert>

template <typename T>
class Queue
{
private:
	struct Node
	{
		T data_;
		Node* next_;

		Node(const T& data, Node* next = nullptr);
	};

	Node* front_ = nullptr;
	Node* back_ = nullptr;

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