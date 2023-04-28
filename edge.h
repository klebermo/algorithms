#ifndef LIB_EDGE_H
#define LIB_EDGE_H

#include <map>

typedef struct Direction {
  float weight;
  float angle;
};

template<class T> class Vertex;

const float PI = 3.14159265359f;

float to_rad(float value) {
  return (value * PI) / 180.0f;
}

template<class T>
class Edge {
private:
  std::map<Direction, Vertex<T>> vertices;
public:
  Edge();
  ~Edge();

  std::map<Direction, Vertex<T>> getVertices();
  void setVertices(std::map<Direction, Vertex<T>> values);
};

template<class T>
Edge<T>::Edge() {
  //
}

template<class T>
Edge<T>::~Edge() {
  //
}

template<class T>
std::map<Direction, Vertex<T>> Edge<T>::getVertices() {
  return this->vertices;
}

template<class T>
void Edge<T>::setVertices(std::map<Direction, Vertex<T>> values) {
  this->vertices = values;
}

#endif  // LIB_EDGE_H
