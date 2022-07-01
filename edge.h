#ifndef LIB_EDGE_H
#define LIB_EDGE_H

#include "vertex.h"

template<class T>
class Edge {
private:
  int weight;
  float angle;
  Vertex<T> destination;
public:
  Edge();
  ~Edge();

  T getWeight();
  void setWeight(T value);

  float getAngle();
  void setAngle(float value);

  Vertex<T> getDestination();
  void setDestination(Vertex<T> value);

  friend std::ostream& operator<<(std::ostream& output, const Edge<T>& e) { output << e.destination; return output; };
};

template<class T>
Edge<T>::Edge() {
  this->weight = 0;
  this->angle = 0.f;
  this->destination = Vertex<T>();
}

template<class T>
Edge<T>::~Edge() {
  //
}

template<class T>
T Edge<T>::getWeight() {
  return this->weight;
}

template<class T>
void Edge<T>::setWeight(T value) {
  this->weight = value;
}

template<class T>
float Edge<T>::getAngle() {
  return this->angle;
}

template<class T>
void Edge<T>::setAngle(float value) {
  this->angle = value;
}

template<class T>
Vertex<T> Edge<T>::getDestination() {
  return this->destination;
}

template<class T>
void Edge<T>::setDestination(Vertex<T> value) {
  this->destination.setData(value.getData());
  this->destination.setCoordenates(value.getCoordenates());
  this->destination.setEdges(value.getEdges());
}

#endif  // LIB_EDGE_H
