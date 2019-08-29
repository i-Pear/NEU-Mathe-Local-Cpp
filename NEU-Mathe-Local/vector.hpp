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
		//�ж�����
		if (finish == endOfstorage)
		{
			size_t newCapacity = start == nullptr ? 1 : 2 * Capacity();
			Reserve(newCapacity);
		}
		*finish++ = val;
	}

	Vector(const Vector<T>& v)
	{
		//1.������� 2.���ռ� 3.���� 4.�ͷ�ԭ�пռ�
		start = new T[v.Capacity()];
		for (int i = 0; i < v.Size(); i++)
		{
			start[i] = v[i];
		}
		finish = start + v.Size();
		endOfstorage = start + v.Capacity();
	}

	//��ֵ���������
	Vector<T>& operator=(const Vector<T>& v)
	{
		//����Ƿ��Լ���ֵ
		//����ֵ����:���ã�Ϊ��������ֵ
		//����: *this
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

	//һ���ɶ���д�Ľӿ�
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
			//�����¿ռ�
			T* tmp = new T[n];
			//����ԭ��(ǳ������ʽ���������)
			/*if (start)
			{
				memcpy(tmp, start, sizeof(T)*len);
				delete[] start;
			}*/
			//�����Զ������͵ĸ�ֵ��������أ��������
			if (start)
			{
				for (int i = 0; i < len; i++)
				{
					tmp[i] = start[i];
				}
				delete[] start;
			}
			//����ָ��
			start = tmp;
			finish = start + len;
			endOfstorage = start + n;
		}
	}

	//���뵼�µ�����ʧЧ��������ԭ�пռ䱻�ͷţ�������ָ���λ��ʧЧ
	void Insert(iterator pos, const T & val)
	{
		assert(pos <= finish && pos >= start);
		size_t len = pos - start;
		//���ռ��Ƿ��㹻
		if (finish == endOfstorage)
		{
			size_t newC = start == nullptr ? 1 : 2 * Capacity();
			Reserve(newC);
		}
		//���ݺ󣬵������ĸ���
		pos = start + len;
		iterator end = finish;
		//�Ӻ���ǰŲ��Ԫ�أ��ڳ�pos�Ŀռ䣬����µ�Ԫ��val
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
			//����λ�ø�ֵ
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