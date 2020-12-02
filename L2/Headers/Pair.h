#pragma once

template<class A, class B>

class pair
{
private:
	A _key;
	B _value;
public:
	pair();
	pair(const A&, const B&);
	const A & getkey() const;
	const B & getvalue() const;


};



template <typename A, typename B>
pair<A, B>::pair()
{
	_key = A{};
	_value = B{};
}

template <typename A, typename B>
pair<A, B>::pair(const A& _key, const B& _value) 
{
	this->_key = _key;
	this->_value = _value;
}

template <typename A, typename B>
const A& pair<A, B>::getkey() const
{
	return _key;
}

template <typename A, typename B>
const B& pair<A, B>::getvalue() const
{
	return _value;
}


