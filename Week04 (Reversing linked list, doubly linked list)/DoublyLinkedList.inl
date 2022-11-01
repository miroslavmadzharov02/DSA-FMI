#include "DoublyLinkedList.h"

template<typename T>
inline DoublyLinkedList<T>::Node::Node(const T& data)
	: data_(data), prev_(nullptr), next_(nullptr)
{
}

template<typename T>
inline DoublyLinkedList<T>::Node::Node(const T& data, const Node* prev, const Node* next)
	: data_(data), prev_(prev), next_(next)
{
}

template<typename T>
inline void DoublyLinkedList<T>::copy(const DoublyLinkedList& other)
{
	head_ = tail_ = nullptr;

	Node* current = other.head_;
	while (current != nullptr)
	{
		pushBack(current->data_);
		current = current->next_;
	}
}

template<typename T>
inline void DoublyLinkedList<T>::del()
{
	while (head_ != nullptr)
	{
		Node* current = head_;
		head_ = head_->next_;
		delete current;
	}
}

template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList()
	: head_(nullptr), tail_(nullptr)
{
}

template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& other)
{
	copy(other);
}

template<typename T>
inline DoublyLinkedList<T>::~DoublyLinkedList()
{
	del();
}

template<typename T>
inline const size_t DoublyLinkedList<T>::getSize() const
{
	size_t count = 0;

	Node* current = head_;
	while (current != nullptr)
	{
		current = current->next_;
		count++;
	}

	return count;
}

template<typename T>
inline void DoublyLinkedList<T>::pushFront(const T& elem)
{
	Node* nodeToPush = new Node(elem);

	nodeToPush->prev_ = nullptr;
	nodeToPush->next_ = head_;

	if (head_ != nullptr)
		head_->prev_ = nodeToPush;

	head_ = nodeToPush;
}

template<typename T>
inline void DoublyLinkedList<T>::pushBack(const T& elem)
{
	Node* nodeToPush = new Node(elem);

	nodeToPush->next_ = nullptr;
	if (head_ == nullptr)
	{
		nodeToPush->prev_ = nullptr;
		head_ = tail_ = nodeToPush;
		return;
	}

	tail_->next_ = nodeToPush;
	nodeToPush->prev_ = tail_;
	tail_ = nodeToPush;
}

template<typename T>
inline void DoublyLinkedList<T>::pushBeforeNode(const T& elem, Node* iterator)
{
	if (iterator == nullptr)
		throw std::exception("Cannot push before nullptr node.\n");

	Node* nodeToPush = new Node(elem);

	nodeToPush->prev_ = iterator->next_;
	iterator->prev_ = nodeToPush;
	nodeToPush->next_ = iterator;

	if (nodeToPush->prev_ == nullptr)
	{
		head_ = nodeToPush;
		return;
	}

	nodeToPush->prev_->next_ = nodeToPush;
}

template<typename T>
inline void DoublyLinkedList<T>::pushAfterNode(const T& elem, Node* iterator)
{
	if (iterator == nullptr)
		throw std::exception("Cannot push after nullptr node.\n");

	Node* nodeToPush = new Node(elem);

	nodeToPush->next_ = iterator->next_;
	iterator->next_ = nodeToPush;
	nodeToPush->prev_ = iterator;

	if (nodeToPush->next_ != nullptr)
		nodeToPush->next_->prev_ = nodeToPush;
}

template<typename T>
inline T DoublyLinkedList<T>::popFront()
{
	if (head_ == nullptr)
		throw std::exception("Cannot pop from empty list.\n");

	Node* headToPop = head_;

	head_ = head_->next_;
	if (head_ != nullptr)
		head_->prev_ = nullptr;

	const T dataCopy = headToPop->data_;
	delete headToPop;

	return dataCopy;
}

template<typename T>
inline T DoublyLinkedList<T>::popBack()
{
	if (head_ == nullptr)
		throw std::exception("Cannot pop from empty list.\n");

	if (head_->next_ == nullptr)
	{
		const T dataCopy = head_->data_;
		delete head_;
		head_ = tail_ = nullptr;
		return dataCopy;
	}

	Node* secondToLast = tail_->prev_;
	secondToLast->next_ = nullptr;

	const T dataCopy = tail_->data_;
	delete tail_;
	tail_ = secondToLast;

	return dataCopy;
}

template<typename T>
inline std::vector<T> DoublyLinkedList<T>::toVector()
{
	Node* current = head_;
	std::vector<T> vec;
	
	while (current != nullptr)
	{
		vec.push_back(current->data_);
		current = current->next_;
	}

	return vec;
}

