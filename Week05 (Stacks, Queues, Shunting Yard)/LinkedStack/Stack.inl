#include "Stack.h"

template<typename T>
inline Stack<T>::Node::Node(const T& data, Node* next)
	: data_(data), next_(next)
{
}

template<typename T>
inline void Stack<T>::copy(const Stack<T>& other)
{
	Node* last = nullptr;
	Node* current = other.top_;

	while (current != nullptr)
	{
		Node* nodeToPush = new Node(current->data_);

		if (last == nullptr)
		{
			top_ = nodeToPush;
		}
		else
		{
			last->next_ = nodeToPush;
		}

		last = nodeToPush;
		current = current->next_;
	}
}

template<typename T>
inline void Stack<T>::del()
{
	while (top_ != nullptr)
	{
		Node* current = top_;
		top_ = top_->next_;
		delete current;
	}
}

template<typename T>
inline Stack<T>::Stack()
{
}

template<typename T>
inline Stack<T>::Stack(const Stack<T>& other)
{
	copy(other);
}

template<typename T>
inline Stack<T>::~Stack()
{
	del();
}

template<typename T>
inline void Stack<T>::push(const T& elem)
{
	Node* nodeToPush = new Node(elem, top_);

	top_ = nodeToPush;
}

template<typename T>
inline void Stack<T>::pop()
{
	Node* nodeToPop = top_;

	top_ = top_->next_;

	delete nodeToPop;
}

template<typename T>
inline const size_t Stack<T>::size() const
{
	Node* current = top_;
	size_t count = 0;
	while (current != nullptr)
	{
		count++;
		current = current->next_;
	}

	return count;
}

template<typename T>
inline bool Stack<T>::empty() const
{
	return size() == 0;
}

template<typename T>
inline const T& Stack<T>::top() const
{
	assert(size() > 0);
	return top_->data_;
}