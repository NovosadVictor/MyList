#ifndef _MYNODE_H_
#define _MYNODE_H_
#include <iostream>

template<class T>
class ListNode {
public:
	ListNode() : _next(NULL) {}
	T _value;
	ListNode<T> *_next;
//	~ListNode() { delete _next;}
};
#endif
