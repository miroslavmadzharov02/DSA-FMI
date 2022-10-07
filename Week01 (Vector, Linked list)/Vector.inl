#include "Vector.h"

template<typename T>
void Vector<T>::resize()
{
	const size_t newCapacity = capacity_ + capacity_ / 2;
	if (size_ > newCapacity)
		size_ = newCapacity;

	T* temp = new T[newCapacity];
	for (size_t i = 0; i < size_; i++)
		temp[i] = container_[i];

	delete[] container_;
	container_ = temp;
	capacity_ = newCapacity;
}

template<typename T>
void Vector<T>::copy(const Vector<T>& other)
{
	container_ = new T[other.capacity_];
	for (size_t i = 0; i < other.size_; i++)
		container_[i] = other.container_[i];

	capacity_ = other.capacity_;
	size_ = other.size_;
}

template<typename T>
Vector<T>::Vector()
	: size_(0), capacity_(2)
{
	container_ = new T[capacity_];
}

template<typename T>
Vector<T>::Vector(const T* container, size_t size, size_t capacity)
	: size_(size), capacity_(capacity)
{
	container_ = new T[capacity_];
	for (size_t i = 0; i < size_; i++)
		container_[i] = container[i];
}

template<typename T>
Vector<T>::Vector(const Vector& other)
{
	copy(other);
}

template<typename T>
Vector<T>::Vector(size_t capacity)
	: size_(0), capacity_(capacity)
{
	container_ = new T[capacity_];
}

template<typename T>
Vector<T>::~Vector()
{
	delete[] container_;
}

template<typename T>
const size_t Vector<T>::getSize() const
{
	return size_;
}

template<typename T>
const size_t Vector<T>::getCapacity() const
{
	return capacity_;
}

template<typename T>
void Vector<T>::pushBack(const T elem)
{
	if (size_ >= capacity_)
		resize();
	container_[size_++] = elem;
}

template<typename T>
void Vector<T>::popBack()
{
	if (!size_)
		return;

	container_[size_ - 1].~T();
	--size_;
}

template<typename T>
void Vector<T>::popAtIndex(const size_t& index)
{
	if (index >= size_)
		throw std::exception("Index to remove out of bounds.\n");

	if (index == size_ - 1)
	{
		popBack();
		return;
	}

	container_[index].~T();
	for (size_t i = index; i < size_ - 1; i++)
		container_[i] = container_[i + 1];
	--size_;
}

template<typename T>
void Vector<T>::updateAtIndex(const size_t& index, const T& elem)
{
	if (index >= size_)
		throw std::exception("Index to update out of bounds.\n");

	container_[index] = elem;
}

template<typename T>
bool Vector<T>::doesExist(const T& valueToSeek)
{
	for (size_t i = 0; i < size_; i++)
		if (valueToSeek == container_[i])
			return true;
	return false;
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this == &other)
		return *this;

	delete[] container_;
	copy(other);
	return *this;
}

template<typename T>
T& Vector<T>::operator[](const size_t& index) const
{
	if (index < 0 || index >= size_)
		throw std::exception("Index out of range");

	return container_[index];
}