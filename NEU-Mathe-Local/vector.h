#pragma once
#include <cassert>

template <class T>
class Vector
{
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	Vector()
		: start(nullptr)
		, finish(nullptr)
		, endOfstorage(nullptr)
	{}

	void clear() {
		if (start) { delete[]  start; }
		start = finish = endOfstorage = nullptr;
	}

	void PushBack(const T& val)
	{
		//判断容量
		if (finish == endOfstorage)
		{
			size_t newCapacity = start == nullptr ? 1 : 2 * Capacity();
			Reserve(newCapacity);
		}
		*finish++ = val;
	}

	Vector(const Vector<T>& v)
	{
		//1.考虑深拷贝 2.开空间 3.拷贝 4.释放原有空间
		start = new T[v.Capacity()];
		for (int i = 0; i < v.Size(); i++)
		{
			start[i] = v[i];
		}
		finish = start + v.Size();
		endOfstorage = start + v.Capacity();
	}

	//赋值运算符重载
	Vector<T>& operator=(const Vector<T>& v)
	{
		//检测是否自己赋值
		//返回值类型:引用，为了连续赋值
		//返回: *this
		if (this != &v)
		{
			T* tmp = new T[v.Capacity()];
			size_t sz = Size();
			for (int i = 0; i < v.Size(); i++)
			{
				tmp[i] = v[i];
			}
			if (start)
			{
				delete[] start;
			}
			start = tmp;
			finish = start + sz;
			endOfstorage = start + v.Capacity();
		}
		return *this;
	}

	void PopBack()
	{
		Erase(end() - 1);
		//Erase(finish - 1);
	}

	//一个可读可写的接口
	T& operator[](size_t pos)
	{
		assert(pos < Size());
		return start[pos];
	}
	const T& operator[](size_t pos) const
	{
		assert(pos < Size());
		return start[pos];
	}
	size_t Capacity() const
	{
		return endOfstorage - start;
	}
	bool Empty() const
	{
		return start == finish;
	}

	size_t Size() const
	{
		return finish - start;
	}

	iterator begin()
	{
		return start;
	}
	const_iterator begin() const
	{
		return start;
	}
	iterator end()
	{
		return finish;
	}
	const_iterator end() const
	{
		return finish;
	}
	void Reserve(size_t n)
	{
		if (n > Capacity())
		{
			int len = Size();
			//开辟新空间
			T* tmp = new T[n];
			//拷贝原有(浅拷贝方式，会出问题)
			/*if (start)
			{
				memcpy(tmp, start, sizeof(T)*len);
				delete[] start;
			}*/
			//调用自定义类型的赋值运算符重载，进行深拷贝
			if (start)
			{
				for (int i = 0; i < len; i++)
				{
					tmp[i] = start[i];
				}
				delete[] start;
			}
			//更新指针
			start = tmp;
			finish = start + len;
			endOfstorage = start + n;
		}
	}

	//插入导致迭代器失效：增容是原有空间被释放，迭代器指向的位置失效
	void Insert(iterator pos, const T & val)
	{
		assert(pos <= finish && pos >= start);
		size_t len = pos - start;
		//检测空间是否足够
		if (finish == endOfstorage)
		{
			size_t newC = start == nullptr ? 1 : 2 * Capacity();
			Reserve(newC);
		}
		//增容后，迭代器的更新
		pos = start + len;
		iterator end = finish;
		//从后向前挪动元素，腾出pos的空间，存放新的元素val
		while (end > pos)
		{
			*end = *(end - 1);
			end--;
		}
		*pos = val;
		finish++;
	}

	iterator Earse(iterator pos)
	{
		assert(pos < finish && pos >= start);
		iterator begin = pos + 1;
		while (begin < finish)
		{
			*(begin - 1) = *begin;
			++begin;
		}

		--finish;

		return pos;
	}

	void Resize(size_t n, const T & val = T())
	{
		if (n <= Size())
		{
			finish = start + n;
		}
		else
		{
			if (n > Capacity())
				Reserve(n);
			//新增位置赋值
			while (finish != start + n)
			{
				*finish = val;
				++finish;
			}
		}
	}
	~Vector()
	{
		if (start)
		{
			delete[]  start;
			start = finish = endOfstorage = nullptr;
		}
	}
	/*size_t capacity()const
	{
		return Capacity();
	}*/
private:
	T* start;
	T* finish;
	T* endOfstorage;
};