#ifndef LIB_NODE_LIST_H
#define LIB_NODE_LIST_H

template<class T>
class NodeList {
private:
  T data;
  NodeList * next;
public:
  NodeList();
  ~NodeList();

  T getData();
  void setData(T value);

  NodeList * getNext();
  void setNext(NodeList<T> * next);
};

template<class T>
NodeList<T>::NodeList() {
  this->data = T();
  this->next = nullptr;
}

template<class T>
NodeList<T>::~NodeList() {
  this->next = nullptr;
}

template<class T>
T NodeList<T>::getData() {
  return this->data;
}

template<class T>
void NodeList<T>::setData(T value) {
  this->data = value;
}

template<class T>
NodeList<T> * NodeList<T>::getNext() {
  return this->next;
}

template<class T>
void NodeList<T>::setNext(NodeList<T> * next) {
  this->next = next;
}

#endif  // LIB_NODE_LIST_H
