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

	Node* first_;
	Node* last_;
	size_t size_;

	void copy(const LinkedList& other);
	void del();
public:
	LinkedList();
	LinkedList(const LinkedList& other);
	~LinkedList();

	void insertLast(const T& elem);
	void updateAt(const size_t& index, const T& elem);
	void removeAt(const size_t& index);
	void print();

	T operator[](const size_t& index) const;
};

#include "LinkedList.inl"
#endif