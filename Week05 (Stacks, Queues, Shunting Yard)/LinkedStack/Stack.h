#ifndef STACK__
#define STACK__
 
template <typename T>
class Stack
{
private:
	struct Node
	{
		T data_;
		Node* next_;

		Node(const T& data, Node* next = nullptr);
	};

	Node* top_ = nullptr;

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