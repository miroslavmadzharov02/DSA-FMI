#ifndef LINKEDLIST__
#define LINKEDLIST__

template <typename T>
class LinkedList
{
private:
	struct Node
	{
		T data_;
		Node* next_;

		Node(const T& data, Node* next = nullptr);
	};

	Node* head_;
	Node* tail_;
	size_t size_;

	void copy(const LinkedList& other);
	void del();
public:
	LinkedList();
	LinkedList(const LinkedList& other);
	~LinkedList();

	const size_t getSize() const;

	void pushBack(const T& elem);
	void updateAt(const size_t& index, const T& elem);
	void popAt(const size_t& index);

	T operator[](const size_t& index) const;

	/*NEW METHODS*/
	void pushAfterNode(const T& value, Node* iterator);
	T popFirst();
	T popLast();
	T popAfterNode(Node* iterator);
	/*NEW METHODS*/
};

#include "LinkedList.inl"
#endif