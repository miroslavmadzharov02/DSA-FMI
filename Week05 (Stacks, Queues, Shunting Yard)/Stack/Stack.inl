#include "Stack.h"

template<typename T>
inline void Stack<T>::resize()
{
	T* tempCopy = new T[capacity_ * 2];

	for (int i = 0; i < size_; i++)
		tempCopy[i] = data_[i];

	capacity_ *= 2;

	del();
	data_ = tempCopy;
}

template<typename T>
inline void Stack<T>::copy(const Stack<T>& other)
{
	data_ = new T[other.capacity_];
	for (size_t i = 0; i < other.size_; i++)
		data_[i] = other.data_[i];
	size_ = other.size_;
	capacity_ = other.capacity_;
}

template<typename T>
inline void Stack<T>::del()
{
	delete[] data_;
}

template<typename T>
inline Stack<T>::Stack()
{
	data_ = new T[capacity_];
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
	if (size_ == capacity_)
		resize();

	data_[size_++] = elem;
}

template<typename T>
inline void Stack<T>::pop()
{
	assert(size_ != 0);
	size_--;
}

template<typename T>
inline bool Stack<T>::empty() const
{
	return size_ == 0;
}

template<typename T>
inline const size_t Stack<T>::size() const
{
	return size_;
}

template<typename T>
inline const T& Stack<T>::top() const
{
	assert(size_ != 0);
	return data_[size_ - 1];
}