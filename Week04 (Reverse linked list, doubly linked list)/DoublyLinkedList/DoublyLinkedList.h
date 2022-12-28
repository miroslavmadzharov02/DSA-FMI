#ifndef DOUBLYLINKEDLIST__
#define DOUBLYLINKEDLIST__

#include <vector>
 
template <typename T>
class DoublyLinkedList
{
	struct Node
	{
		T data_;
		Node* prev_;
		Node* next_;

		Node(const T& data);
		Node(const T& data, const Node* prev, const Node* next);
	};

	Node* head_;
	Node* tail_;

	void copy(const DoublyLinkedList& other);
	void del();
public:
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList& other);
	~DoublyLinkedList();

	const size_t getSize() const;

	void pushFront(const T& elem);
	void pushBack(const T& elem);
	void pushBeforeNode(const T& elem, Node* iterator);
	void pushAfterNode(const T& elem, Node* iterator);

	T popFront();
	T popBack();

	std::vector<T> toVector();
};

#include "DoublyLinkedList.inl"
#endif