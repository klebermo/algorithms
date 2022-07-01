#ifndef LIB_LIST_H
#define LIB_LIST_H

#include "node_list.h"

template<class T>
class List {
private:
  NodeList<T> * first;
public:
  List();
  ~List();

  void insert(T data);
  void update(int index, T data);
  void remove(int index);

  int size();
  NodeList<T> * get(int index);
  void set(int index, NodeList<T> * value);
  int find(T data);
  void sort();
  //void print();
  T * toArray();
};

template<class T>
List<T>::List() {
  this->first = nullptr;
}

template<class T>
List<T>::~List() {
  //
}

template<class T>
void List<T>::insert(T data) {
  if(this->first == nullptr) {
    this->first = new NodeList<T>();
    this->first->setData(data);
  } else {
    NodeList<T> * aux = this->first;
    NodeList<T> * auxPrevious = nullptr;

    while(aux != nullptr) {
      auxPrevious = aux;
      aux = aux->getNext();
    }

    aux = new NodeList<T>();
    aux->setData(data);
    auxPrevious->setNext(aux);
  }
}

template<class T>
void List<T>::update(int index, T data) {
  NodeList<T> * aux = this->first;
  int count = 1;

  while(aux != nullptr) {
    if(count == index) {
      aux->setData(data);
      break;
    }
    aux = aux->getNext();
    count++;
  }
}

template<class T>
void List<T>::remove(int index) {
  if(this->size() == 1) {
    this->first = nullptr;
    return;
  }

  NodeList<T> * aux = this->first;
  NodeList<T> * auxPrevious = nullptr;
  int count = 1;

  while(aux != nullptr) {
    if(count == index) {
      if(auxPrevious == nullptr) {
        this->first = this->first->getNext();
      } else {
        auxPrevious->setNext(aux->getNext());
        aux->setNext(nullptr);
        delete aux;
      }
      break;
    }
    auxPrevious = aux;
    aux = aux->getNext();
    count++;
  }
}

template<class T>
int List<T>::size() {
  NodeList<T> * aux = this->first;
  int count = 0;

  while(aux != nullptr) {
    aux = aux->getNext();
    count++;
  }

  return count;
}

template<class T>
NodeList<T> * List<T>::get(int index) {
  NodeList<T> * aux = this->first;
  int count = 1;

  while(aux != nullptr) {
    if(count == index)
      return aux;
    aux = aux->getNext();
    count++;
  }

  return nullptr;
}

template<class T>
void List<T>::set(int index, NodeList<T> * value) {
  NodeList<T> * aux = this->first;
  int count = 1;

  while(aux != nullptr) {
    if(count == index) {
      aux = value;
      break;
    }
    aux = aux->getNext();
    count++;
  }
}

template<class T>
int List<T>::find(T data) {
  NodeList<T> * aux = this->first;
  int count = 1;

  while(aux != nullptr) {
    if(aux->getData() == data)
      return count;
    aux = aux->getNext();
    count++;
  }

  return 0;
}

template<class T>
void List<T>::sort() {
  int i, j;
  int length = this->size();

  for(i = 1; i <=length; i++) {
    int jMin = i;
    for(j = i+1; j<=length; j++) {
      if(this->get(j)->getData() < this->get(jMin)->getData())
        jMin = j;
    }
    if(jMin != i) {
      T data = this->get(jMin)->getData();
      this->get(jMin)->setData(this->get(i)->getData());
      this->get(i)->setData(data);
    }
  }
}

/*template<class T>
void List<T>::print() {
  cout << "{ ";
  for(int i=1; i<=this->size(); i++)
    cout << this->get(i)->getData() << " ";
  cout << "}";
}*/

template<class T>
T * List<T>::toArray() {
  T * result = new T[this->size()];

  for(int i=1; i<=this->size(); i++)
    result[i] = this->get(i)->getData();

  return result;
}

#endif  // LIB_LIST_H
