#ifndef LIB_EDGE_H
#define LIB_EDGE_H

#include <map>

#include "vertex.h"

struct Direction {
  int weight;
  float angle;

  bool operator==(const Direction & other) const {
    return this->weight == other.weight && this->angle == other.angle;
  }

  bool operator<(const Direction & other) const {
    return this->weight < other.weight && this->angle < other.angle;
  }

  bool operator>(const Direction & other) const {
    return this->weight > other.weight && this->angle > other.angle;
  }

  bool operator<=(const Direction & other) const {
    return this->weight <= other.weight && this->angle <= other.angle;
  }

  bool operator>=(const Direction & other) const {
    return this->weight >= other.weight && this->angle >= other.angle;
  }
};
typedef struct Direction Direction;

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
  Edge(int weight, float angle, Vertex<T> destination);
  ~Edge();

  std::map<Direction, Vertex<T>> getVertices();
  void setVertices(std::map<Direction, Vertex<T>> values);

  bool operator==(const Edge<T> & other) const {
    return this->vertices == other.vertices;
  }

  bool operator<(const Edge<T> & other) const {
    return this->vertices.size < other.vertices.size;
  }

  bool operator>(const Edge<T> & other) const {
    return this->vertices.size > other.vertices.size;
  }

  bool operator<=(const Edge<T> & other) const {
    return this->vertices.size <= other.vertices.size;
  }

  bool operator>=(const Edge<T> & other) const {
    return this->vertices.size >= other.vertices.size;
  }
};

template<class T>
Edge<T>::Edge() {
  //
}

template<class T>
Edge<T>::Edge(int weight, float angle, Vertex<T> destination) {
  Direction direction;
  direction.weight = weight;
  direction.angle = to_rad(angle);

  this->vertices[direction] = destination;
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
