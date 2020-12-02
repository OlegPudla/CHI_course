#pragma once




template <class T, int N>
class list
{
private:
	T * _data;
	int _size;
	int _index;

public:
	list();
	~list();
	size_t size();
	const T& operator [](int) const;
	void operator += (const T&);

};


template<typename T, int N>
list<T, N>::list() 
{
	_index = 0;
	if (N > 0)
	{
		_data = new T[N];
		_size = N;
	}
	else
	{
		_data = nullptr;
		_size = 0;
	}
}

template<typename T, int N>
size_t list<T, N>::size()
{
	return _index;
}

template <typename T, int N>
void list<T, N>::operator+=(const T& _element)
{
	if (_data)
	{
		if (_index < _size)
		{
			_data[_index] = _element;
			++ _index;
		}
	}

	return;
}

template <typename T, int N>
const T& list<T, N>::operator[] (int _index) const
{
	if (_data)
	{
	
			return _data[_index];
		
	}
}

template <typename T, int N>
list<T, N>::~list()
{
	if (_data)
	{
		delete[] _data;
	}
}

