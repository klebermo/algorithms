#ifndef LIB_VERTEX_H
#define LIB_VERTEX_H

#include "list.h"

template<class T> class Edge;

template<class T>
class Vertex {
private:
  T data;
  List<Edge<T>> * edges;
public:
  Vertex();
  ~Vertex();

  T getData();
  void setData(T value);

  List<Edge<T>> * getEdges();
  void setEdges(List<Edge<T>> * values);

  bool operator==(const Vertex<T> & other) const {
    return this->data == other.data;
  }
};

template<class T>
Vertex<T>::Vertex() {
  this->data = T();
  this->edges = new List<Edge<T>>();
}

template<class T>
Vertex<T>::~Vertex() {
  //
}

template<class T>
T Vertex<T>::getData() {
  return this->data;
}

template<class T>
void Vertex<T>::setData(T value) {
  this->data = value;
}

template<class T>
List<Edge<T>> * Vertex<T>::getEdges() {
  return this->edges;
}

template<class T>
void Vertex<T>::setEdges(List<Edge<T>> * values) {
  this->edges = values;
}

#endif  // LIB_VERTEX_H
