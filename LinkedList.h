#include "ListNodecpp.h"
#include "SortBycpp.h"
#include <iostream>
template <class T>
class LinkedList{

private: ListNode<T> * front;
int count;

public: LinkedList<T>();
public: bool empty();
public: int size();
public: void add( T  t);
public: T get(T value);
public: T get(int index);
public: int insert( T  t, SortBy<T> f);
//public: void insert( T  t);
public: int remove( T  t);
public: std::string toString();
public: void  printList();

};