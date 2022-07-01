#ifndef LIB_VERTEX_H
#define LIB_VERTEX_H

#include "list.h"

template<class T> class Edge;

struct Coordenate {
  float x, y;
} typedef Coordenate;

template<class T>
class Vertex {
private:
  T data;
  Coordenate coordenate;
  List<Edge<T>> * edges;
public:
  Vertex();
  ~Vertex();

  T getData();
  void setData(T value);

  Coordenate getCoordenates();
  void setCoordenates(Coordenate value);

  List<Edge<T>> * getEdges();
  void setEdges(List<Edge<T>> * values);

  bool operator==(Vertex<T> other) { return this->getData() == other.getData(); }
  friend std::ostream& operator<<(std::ostream& output, const Vertex<T>& e) { output << e.data; return output; };
};

template<class T>
Vertex<T>::Vertex() {
  this->data = T();
  this->coordenate = Coordenate();
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
Coordenate Vertex<T>::getCoordenates() {
  return this->coordenate;
}

template<class T>
void Vertex<T>::setCoordenates(Coordenate value) {
  this->coordenate.x = value.x;
  this->coordenate.y = value.y;
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
