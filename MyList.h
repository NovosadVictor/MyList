#ifndef _MYLIST_H_
#define _MYLIST_H_
#include <exception>
#include "MyNode.h"

template<class T>
class List {
public:
	List() : _first(NULL), _size(0) {}
	List(const List<T> &other);
	~List();
	T &first();
	const T &first() const;
	List<T> operator+(const List<T> &other);
	List<T> &operator+=(const List<T> &other);
	List<T> &operator=(const List<T> &other);
	bool operator==(const List<T> &other);
//	void ListSort();
	bool empty();
	size_t size();
	void push_front(T value);
	void pop_front();
	void pop_back();
	void push_back(T value);
	void insert(size_t i, T value);
	void pop(size_t i);
	void clear();
	template<class U>
	friend std::ostream &operator<<(std::ostream &os, const List<U> &other);
private:
	ListNode<T> *_first;
	size_t _size;
};	

template<class T>
List<T>::List(const List<T> &other) {
	_first = new ListNode<T>;
	_size = 0;
	*this = other;
}
template<class T>
List<T>::~List() {
	(*this).clear();
}
template<class T>
T &List<T>::first() {
	if (_first == NULL)
		throw 1;
	return _first->_value;
}
template<class T>
const T &List<T>::first() const {
	return (const_cast<T &>(*this)).first();
}
template <class T>
size_t List<T>::size() {
	return _size;
}
template <class T>
bool List<T>::empty() {
	return (_size == 0);
}
template<class T>
void List<T>::push_front(T value) {
//	std::cout << "push_front" << std::endl;
	if (_size == 0) {
		ListNode<T> *L = new ListNode<T>;
		L->_value = value;
		_first = L;
//		std::cout << "_first = " << _first << std::endl;
		L = NULL;
		delete L;
	}	
	else {
		ListNode<T> *L = new ListNode<T>;
		L->_value = value;
		L->_next = _first;
		_first = L;
//		std::cout << "_first = " << _first << std::endl;
		L = NULL;
		delete L; 
	}
	++_size;
}
template<class T>
void List<T>::push_back(T value) {
//	std::cout << "push_back" << std::endl;
	if (_size == 0) {
		ListNode<T> *L = new ListNode<T>;
		L->_value = value;
		_first = L;
//		std::cout << "_first = " << _first << std::endl;
		L = NULL;
		delete L;
	}
	else {
		ListNode<T> *L = new ListNode<T>;
		L->_value = value;
		ListNode<T> *cur = _first;
		while (cur->_next != NULL)
			cur = cur->_next;
		cur->_next = L;
		L = NULL;
//		std::cout << "_first = " << _first << std::endl;
		delete L;
	}
	++_size;
}
template<class T>
void List<T>::pop_front() {
//	std::cout << "pop_front" << std::endl;
	if (_size == 0)
		throw 2;
	ListNode<T> *first = _first->_next;
	delete _first;
	_first = first;
//	std::cout << "_first = " << _first << std::endl;
	--_size;
}
template<class T>
void List<T>::pop_back() {
//	std::cout <<"pop_back" << std::endl;
	if (_size == 0)
		throw 3;
	if (_size == 1)
		(*this).pop_front();
	if (_size > 1) {
		ListNode<T> *cur = _first;
//		std::cout << "cur = " << cur << std::endl;
//		std::cout << "size = " << _size << std::endl;
//		std::cout << "cur->_next = " << cur->_next << std::endl;
		while (cur->_next->_next != NULL)
			cur = cur->_next;
		ListNode<T> *n = cur->_next;
//		std::cout << "n = " << n << std::endl;
		cur->_next = NULL;
		delete n;
		--_size;
//		std::cout << "_first = " << _first << std::endl;
	}
}
template<class T>
void List<T>::insert(size_t i, T value) {
//	std::cout << "insert" << std::endl;
	if (i >= _size && i == 0)
		throw 4;
	ListNode<T> *cur = _first;
	for (size_t j = 1; j < i; ++j)
		cur = cur->_next;
	ListNode<T> *L = new ListNode<T>;
	L->_value = value;
	L->_next = cur->_next;
	cur->_next = L;
	L = NULL;
//	std::cout << "_first = " << _first << std::endl;
	delete L;
	++_size;
}
template<class T>
void List<T>::pop(size_t i) {
//	std::cout << "pop" << std::endl;
	if (i >= _size && i == 0)
		throw 5;
	ListNode<T> *cur = _first;
	for (int j = 1; j < i; ++j)
		cur = cur->_next;
	ListNode<T> *p = cur->_next;
	cur->_next = cur->_next->_next;
	delete p;
	--_size;
}
template<class T>
List<T> &List<T>::operator=(const List<T> &other) {
//	std::cout << "=====" << std::endl;
	if (*this == other)
		return *this;
//	std::cout << "_size = " << _size << std::endl;
	(*this).clear();
//	std::cout << "_size after clear = " << _size << std::endl;
//	std::cout << "=== _first = " << _first << std::endl;
	(*this).push_front((other._first)->_value);
	ListNode<T> *_o = other._first;
//	std::cout << "other._size = " << other._size << std::endl;
	for (int s = 1; s < other._size; ++s) {
		_o = _o->_next;
		(*this).insert(s, _o->_value);
	}
//	std::cout << "exit =" << std::endl;
//	(*this).push_back(_o->_next->_value);
	return *this;
}
template<class T>
void List<T>::clear() {
//	std::cout << "clear" << std::endl;
//	std::cout << "_size = " << _size << std::endl;
	while (_size != 0)
		(*this).pop_back();
	delete _first;
	_first = NULL;
	_size = 0;
}
template<class T>
std::ostream& operator<<(std::ostream& os,const List<T> &other){           
  		if (other._size > 0) {
			ListNode<T> *_FIRST = other._first;
        		while (_FIRST != NULL) {
                		os << _FIRST->_value << " ";
               			_FIRST = _FIRST->_next;
       			}
			std::cout << std::endl;
		}
		else
			throw 7;
        	return os;	
}
template<class T>
List<T> List<T>::operator+(const List<T> &other) {
//	std::cout << "+" << std::endl;
	if (_size == 0) {
		List<T> L = other;
		return L;
	}
	if (other._size == 0) {
		List<T> L = *this;
		return L;
	}
	List<T> L = *this;
	L._size = _size + other._size;
//	std::cout << "L size = " << L._size << std::endl;
	ListNode<T> *_o = other._first;
	for (int s = 0; s < other._size - 1; ++s) {
		L.insert(_size + s, _o->_value);
			_o = _o->_next;
	}
	L.push_back(_o->_value);
	L._size = _size + other._size;
//	std::cout << "L size = " << L._size << std::endl;
	return L;
}
template<class T>
List<T> &List<T>::operator+=(const List<T> &other) {
	*this = *this + other;
	return *this;
}
template<class T>
bool List<T>::operator==(const List<T> &other) {
	if (_size != other._size)
		return false;
	ListNode<T> *cur1 = _first;
	ListNode<T> *cur2 = other._first;
	while (cur1->_next != NULL && cur2->_next != NULL) {
		if (cur1->_value != cur2->_value)
			return false;
		cur1 = cur1->_next;
		cur2 = cur2->_next;
	}
	return true;
}
//template<class T>
//void List<T>::ListSort() {
	
#endif
