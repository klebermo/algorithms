#ifndef LIB_QUEUE_H
#define LIB_QUEUE_H

#include "node_list.h"

template<class T>
class Queue {
private:
  NodeList<T> * first;
public:
  Queue();
  ~Queue();

  void push(T value);
  void pop();

  NodeList<T> * front();
  int size();
  bool empty();
};

template<class T>
Queue<T>::Queue() {
  this->first = nullptr;
}

template<class T>
Queue<T>::~Queue() {
  //
}

template<class T>
void Queue<T>::push(T value) {
  if(this->first == nullptr) {
    this->first = new NodeList<T>();
    this->first->setData(value);
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
  }
}

template<class T>
void Queue<T>::pop() {
  NodeList<T> * aux = this->first;
  this->first = aux->getNext();
  delete aux;
}

template<class T>
NodeList<T> * Queue<T>::front() {
  return this->first;
}

template<class T>
int Queue<T>::size() {
  int count = 1;

  NodeList<T> * temp = this->first;
  while(temp != nullptr) {
    temp = temp->getNext();
  }

  return count;
}

template<class T>
bool Queue<T>::empty() {
  return this->first == nullptr;
}

#endif  // LIB_QUEUE_H
