#include "Queue.h"

template<typename T>
inline Queue<T>::Node::Node(const T& data, Node* next)
	: data_(data), next_(next)
{
}

template<typename T>
inline void Queue<T>::del()
{
	while (front_ != nullptr)
	{
		Node* current = front_;
		front_ = front_->next_;
		delete current;
	}
}

template<typename T>
inline Queue<T>::Queue()
{
}

template<typename T>
inline Queue<T>::Queue(const Queue& other)
{
	front_ = back_ = nullptr;

	Node* current = other.front_;
	while (current != nullptr)
	{
		push(current->data_);
		current = current->next_;
	}
}

template<typename T>
inline Queue<T>::~Queue()
{
	del();
}

template<typename T>
inline const T& Queue<T>::front() const
{
	assert(front_ != nullptr);
	return front_->data_;
}

template<typename T>
inline const T& Queue<T>::back() const
{
	assert(back_ != nullptr);
	return back_->data_;
}

template<typename T>
inline void Queue<T>::push(const T& elem)
{
	Node* nodeToPush = new Node(elem);

	if (empty())
		front_ = nodeToPush;
	else
		back_->next_ = nodeToPush;

	back_ = nodeToPush;
}

template<typename T>
inline void Queue<T>::pop()
{
	assert(front_ != nullptr);

	Node* nodeToPop = front_;
	front_ = front_->next_;

	if (empty())
		back_ = nullptr;

	delete nodeToPop;
}

template<typename T>
inline const size_t Queue<T>::size() const
{
	size_t count = 0;
	Node* current = front_;
	while (current != nullptr)
	{
		count++;
		current = current->next_;
	}

	return count;
}

template<typename T>
inline bool Queue<T>::empty() const
{
	return front_ == nullptr;
}