#ifndef LIB_STACK_H
#define LIB_STACK_H

#include "node_list.h"

template<class T>
class Stack {
private:
  NodeList<T> * first;
  NodeList<T> * last;
public:
  Stack();
  ~Stack();

  void push(T value);
  void pop();

  NodeList<T> * top();
  int size();
  bool empty();
};

template<class T>
Stack<T>::Stack() {
  this->first = nullptr;
  this->last = nullptr;
}

template<class T>
Stack<T>::~Stack() {
  //
}

template<class T>
void Stack<T>::push(T value) {
  if(this->first == nullptr) {
    this->first = new NodeList<T>();
    this->first->setData(value);
    this->last = this->first;
  } else {
    NodeList<T> * aux = this->first;
    NodeList<T> * auxPrevious = nullptr;

    while(aux != nullptr) {
      auxPrevious = aux;
      aux = aux->getNext();
    }

    aux = new NodeList<T>();
    aux->setData(value);
    auxPrevious->setNext(aux);
    this->last = aux;
  }
}

template<class T>
void Stack<T>::pop() {
  NodeList<T> * aux = this->first;
  NodeList<T> * auxPrevious = nullptr;

  while(aux != nullptr) {
    auxPrevious = aux;
    aux = aux->getNext();
  }

  auxPrevious->setNext(nullptr);
  delete(aux);
}

template<class T>
NodeList<T> * Stack<T>::top() {
  return this->last;
}

template<class T>
int Stack<T>::size() {
  int count = 1;

  NodeList<T> * temp = this->first;
  while(temp != nullptr) {
    temp = temp->getNext();
  }

  return count;
}

template<class T>
bool Stack<T>::empty() {
  return this->first == nullptr;
}

#endif  // LIB_STACK_H
