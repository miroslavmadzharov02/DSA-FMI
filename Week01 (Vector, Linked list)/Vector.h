#ifndef VECTOR
#define VECTOR

template<typename T>
class Vector
{
private:
	T* container_;
	size_t size_;
	size_t capacity_;

	void resize();
	void copy(const Vector<T>& other);
public:
	Vector();
	Vector(const T* container, size_t size, size_t capacity);
	Vector(const Vector<T>& other);
	Vector(size_t capacity);
	~Vector();

	const size_t getSize() const;
	const size_t getCapacity() const;
	void pushBack(const T elem);
	void popBack();
	void popAtIndex(const size_t& index);
	void updateAtIndex(const size_t& index, const T& elem);
	bool doesExist(const T& valueToSeek);

	Vector<T>& operator=(const Vector<T>& other);
	T& operator[](const size_t& index) const;
};

#include "Vector.inl"
#endif 