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
	first_ = last_ = nullptr;

	Node* current = other.first_;
	while (current)
	{
		insertLast(current->data_);
		current = current->next_;
	}
}

template<typename T>
inline void LinkedList<T>::del()
{
	while (first_ != nullptr)
	{
		Node* current = first_;
		first_ = first_->next_;
		delete current;
	}
}

template<typename T>
inline LinkedList<T>::LinkedList()
	: first_(nullptr), last_(nullptr), size_(0)
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
inline const size_t LinkedList<T>::getSize() const
{
	return size_;
}

template<typename T>
inline void LinkedList<T>::insertLast(const T& elem)
{
	Node* nodeToAdd = new Node(elem);

	if (!size_)
	{
		first_ = last_ = nodeToAdd;
		++size_;
		return;
	}

	last_->next_ = nodeToAdd;
	last_ = nodeToAdd;
	++size_;
}

template<typename T>
inline void LinkedList<T>::updateAt(const size_t& index, const T& elem)
{
	Node* current = first_;

	for (size_t i = 0; i < index; i++)
		current = current->next_;
	current->data_ = elem;
}

template<typename T>
inline void LinkedList<T>::removeAt(const size_t& index)
{
	if (index >= size_)
		throw std::exception("Value to remove is out of bounds.\n");

	--size_;

	if (!index)
	{
		Node* tempFirst = first_;
		first_ = tempFirst->next_;
		delete tempFirst;
		return;
	}

	Node* previousToNodeToRemove = first_;

	for (size_t i = 0; i < index - 1; i++)
		previousToNodeToRemove = previousToNodeToRemove->next_;

	Node* nodeToRemove = previousToNodeToRemove->next_;
	previousToNodeToRemove->next_ = nodeToRemove->next_;
	delete nodeToRemove;
}

template<typename T>
inline void LinkedList<T>::print()
{
	for (Node* current = first_; current != nullptr; current = current->next_)
		std::cout << current->data_ << ' ';
}

template<typename T>
inline T LinkedList<T>::operator[](const size_t& index) const
{
	Node* current = first_;
	size_t count = index;

	while (current != nullptr && count-- > 0)
	{
		current = current->next_;
	}

	return (current == nullptr ? T() : current->data_);
}