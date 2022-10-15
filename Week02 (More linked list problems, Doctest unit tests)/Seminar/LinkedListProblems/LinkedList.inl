#include "LinkedList.h"
#include <iostream>

template<typename T>
inline LinkedList<T>::Node::Node(const T& data, Node* next)
{
	data_ = data;
	next_ = next;
}

template<typename T>
inline void LinkedList<T>::copy(const LinkedList& other)
{
	size_ = 0;
	head_ = tail_ = nullptr;

	Node* current = other.head_;
	while (current)
	{
		pushBack(current->data_);
		current = current->next_;
	}
}

template<typename T>
inline void LinkedList<T>::del()
{
	while (head_ != nullptr)
	{
		Node* current = head_;
		head_ = head_->next_;
		delete current;
	}
}

template<typename T>
inline LinkedList<T>::LinkedList()
	: head_(nullptr), tail_(nullptr), size_(0)
{
}

template<typename T>
inline LinkedList<T>::LinkedList(const LinkedList& other)
{
	copy(other);
}

template<typename T>
inline LinkedList<T>::~LinkedList()
{
	del();
}

template<typename T>
inline size_t LinkedList<T>::count(const T& elem) const
{
	size_t elemAmountInList = 0;
	Node* current = head_;
	while (current != nullptr)
	{
		if (elem == current->data_)
			elemAmountInList++;
		current = current->next_;
	}

	return elemAmountInList;
}

template<typename T>
inline LinkedList<T>::LinkedList(const int& range1, const int& range2)
{
	const int leftBorder = (range1 < range2) ? range1 : range2;
	const int rightBorder = (range1 > range2) ? range1 : range2;

	for (int i = leftBorder; i <= rightBorder; i++)
		pushBack(i);
}

template<typename T>
inline const size_t LinkedList<T>::getSize() const
{
	return size_;
}

template<typename T>
inline void LinkedList<T>::pushBack(const T& elem)
{
	Node* nodeToAdd = new Node(elem);

	if (size_ == 0)
	{
		head_ = tail_ = nodeToAdd;
		++size_;
		return;
	}

	tail_->next_ = nodeToAdd;
	tail_ = nodeToAdd;
	++size_;
}

template<typename T>
inline LinkedList<T>& LinkedList<T>::operator+=(const T& elem)
{
	pushBack(elem);
	return *this;
}

template<typename T>
inline void LinkedList<T>::append(const LinkedList& other)
{
	if (head_ == nullptr)
	{
		copy(other);
		return;
	}

	if (other.head_ == nullptr)
		return;

	for (size_t i = 0; i < other.size_; i++)
		pushBack(other[i]);
}

template<typename T>
inline void LinkedList<T>::updateAt(const size_t& index, const T& elem)
{
	Node* current = head_;

	for (size_t i = 0; i < index; i++)
		current = current->next_;
	current->data_ = elem;
}

template<typename T>
inline void LinkedList<T>::popAt(const size_t& index)
{
	if (index >= size_)
		throw std::exception("Value to remove is out of bounds.\n");

	--size_;

	if (index == 0)
	{
		Node* tempHead = head_;
		head_ = tempHead->next_;
		delete tempHead;
		return;
	}

	Node* previousToNodeToRemove = head_;

	for (size_t i = 0; i < index - 1; i++)
		previousToNodeToRemove = previousToNodeToRemove->next_;

	Node* nodeToRemove = previousToNodeToRemove->next_;
	previousToNodeToRemove->next_ = nodeToRemove->next_;
	delete nodeToRemove;
}

template<typename T>
inline T LinkedList<T>::operator[](const size_t& index) const
{
	Node* current = head_;
	size_t count = index;

	while (current != nullptr && count-- > 0)
	{
		current = current->next_;
	}

	return (current == nullptr ? T() : current->data_);
}