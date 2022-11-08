#include "Queue.h"
#include <cassert>

template<typename T>
inline void Queue<T>::resize()
{
	T* tempCopy = new T[capacity_ * 2];

	for (int i = front_; i < back_; i++)
		tempCopy[i] = data_[i];

	capacity_ *= 2;

	del();
	data_ = tempCopy;
}

template<typename T>
inline void Queue<T>::del()
{
	delete[] data_;
}

template<typename T>
inline Queue<T>::Queue()
{
	data_ = new T[capacity_];
}

template<typename T>
inline Queue<T>::Queue(const Queue& other)
{
	data_ = new T[other.capacity_];
	for (size_t i = 0; i < other.back_; i++)
		data_[i] = other.data_[i];

	front_ = other.front_;
	back_ = other.back_;
	capacity_ = other.capacity_;
}

template<typename T>
inline Queue<T>::~Queue()
{
	del();
}

template<typename T>
inline const T& Queue<T>::front() const
{
	return data_[front_];
}

template<typename T>
inline const T& Queue<T>::back() const
{
	assert(back_ != 0);
	return data_[back_ - 1];
}

template<typename T>
inline void Queue<T>::push(const T& elem)
{
	if (back_ == capacity_)
		resize();

	data_[back_++] = elem;
}

template<typename T>
inline void Queue<T>::pop()
{
	front_++;
}

template<typename T>
inline const size_t Queue<T>::size() const
{
	return back_ - front_;
}

template<typename T>
inline bool Queue<T>::empty() const
{
	return size() == 0;
}
