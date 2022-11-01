#ifndef LINKEDLIST__
#define LINKEDLIST__

#include <initializer_list>

template <typename T>
class LinkedList
{
	class ListIterator;

public:
	using value_type = T;
	using iterator = ListIterator;
private:
	struct Node
	{
		T data_;
		Node* next_;

		Node(const T& data, Node* next = nullptr);
	};

	class ListIterator
	{
	private:
		using pointer = Node*;

		pointer current_;
	public:
		ListIterator() = default;
		ListIterator(Node* ptr);

		pointer operator->();
		value_type operator*();

		ListIterator& operator++(); // ++it
		ListIterator& operator++(int); // it++

		bool operator==(const ListIterator& other) const;
		bool operator!=(const ListIterator& other) const;
	};

	Node* head_;
	Node* tail_;

	void copy(const LinkedList& other);
	void del();
public:
	LinkedList();
	explicit LinkedList(std::initializer_list<T> initList);
	LinkedList(const LinkedList& other);
	~LinkedList();

	const size_t getSize() const;

	void pushBack(const T& elem);
	void updateAt(const size_t& index, const T& elem);
	T popFirst();
	T popLast();
	void popAt(const size_t& index);

	void reverse();

	T operator[](const size_t& index) const;

	//_____ITERATOR_____

	ListIterator begin();
	ListIterator end();
};

#include "LinkedList.inl"
#endif