#include "LinkedList.h"

//GIVEN
template <class T>
LinkedList<T>::LinkedList(){
   front = nullptr;
   count=0;
}
//GIVEN
template <class T>
bool LinkedList<T>::empty(){
  return (front == nullptr);
}
//GIVEN
template <class T>
int LinkedList<T>::size(){
  return count;
}
//GIVEN
//add is more efficient since it adds at the front
//this is different from add of the Assignment 4 which adds at the end of List, so really the question is if we are going to add in order, then why make it more inefficient
template <class T>
void LinkedList<T>::add( T  t){
  ListNode<T>* e = new ListNode<T>(t,front);
  front=e;
  count++;
}
/*
template <class T>
std::string LinkedList<T>:: toString(int i){
   return get(i).toString();
}
*/
//GIVEN
template <class T>
void  LinkedList<T>::printList(){
  ListNode<T> * cur =front;
  while (cur!=nullptr){
    std::cout<<cur->toString()<<"\n";
    cur=cur->next;
  }
}
//Requires: Song  for inserting
//Effects: creates a new ListNode with input value and inserts in proper position (increasing order of chart position)in the chain. If LinkedList, adds to the beginning
//Modifies: front, if node is added at the beginning.
//Also changes the next pointer of the previous node to point to the newly inserted list node. the next pointer of the newly inserted pointer points to what was the next of the previous node. This way both previous and current links are adjusted
//TODO
template <class T>
int LinkedList<T>::insert( T value, SortBy<T> f){
  int steps=0;
  //TODO
 return steps;
}
//Requires: Song title  for searching
//Effects: traverses the LinkedList (database) starting from front until the end comparing titles Returns the original  search value if found otherwise returns an empty song with blank title
//Modifies: Nothing

//TODO

template <class T>
T  LinkedList<T>::get(T value){
  ListNode<T> * current = front;//this may need to change
  //TODO
  return current->getData();
}
//TODO
template <class T>
int  LinkedList<T>::remove(T value){
  //TODO
int steps=0;
  
 return steps;
}




//Requires: index position of Song to be found
//Effects: traverses the LinkedList  starting from front and travels to the index position (if valid) and returns the song at that index position. Note index position may NOT be the same as chart position
//Modifies: Nothing
//TODO
template <class T>
T  LinkedList<T>::get(int index){
  
  ListNode<T> * current = front;
  //TODO
   
  return current->getData();
}
