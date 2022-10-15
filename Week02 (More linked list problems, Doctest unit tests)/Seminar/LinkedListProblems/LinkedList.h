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

	/*METHODS FOR PROBLEMS 12.1 12.2 12.3 12.4 12.7*/

	size_t count(const T& elem) const;
	LinkedList(const int& range1, const int& range2);
	void pushBack(const T& elem);
	LinkedList& operator+=(const T& elem);
	void append(const LinkedList& other);

	/*METHODS FOR PROBLEMS 12.1 12.2 12.3 12.4 12.7*/

	const size_t getSize() const;

	void updateAt(const size_t& index, const T& elem);
	void popAt(const size_t& index);

	T operator[](const size_t& index) const;
};

#include "LinkedList.inl"
#endif