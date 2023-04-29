#ifndef LIB_GRAPH_H
#define LIB_GRAPH_H

#include "list.h"
#include "edge.h"

template<class T>
class Graph {
private:
  List<Vertex<T>> vertices;
public:
  Graph();
  ~Graph();

  bool adjacent(T x, T y);
  List<Vertex<T>> neighbors(T x);

  void add_vertex(T x);
  void remove_vertex(T x);

  void add_edge(T x, T y, int weight = 1, float angle = 1.0f);
  void remove_edge(T x, T y);

  List<Vertex<T>> search(T origin, T destination);

  Vertex<T> get_vertex(T x);
  Edge<T> get_edge(T x, T y);
};

template<class T>
Graph<T>::Graph() {
  //
}

template<class T>
Graph<T>::~Graph() {
  //
}

template<class T>
bool Graph<T>::adjacent(T x, T y) {
  Vertex<T> vx = get_vertex(x);
  Vertex<T> vy = get_vertex(y);

  int max = vx.getEdges()->size();
  for(int i=1; i<=max; i++) {
    Edge<T> e = vx.getEdges()->get(i)->getData();
    for(auto j : e.getVertices()) {
      Vertex<T> v = j.second;
      if(v == vy) return true;
    }
  }

  return false;
}

template<class T>
List<Vertex<T>> Graph<T>::neighbors(T x) {
  List<Vertex<T>> result;

  Vertex<T> vx = get_vertex(x);
  int max = vx.getEdges()->size();
  for(int i=1; i<=max; i++) {
    Edge<T> e = vx.getEdges()->get(i)->getData();
    for(auto j : e.getVertices()) {
      Vertex<T> v = j.second;
      result.insert(v);
    }
  }

  return result;
}

template<class T>
void Graph<T>::add_vertex(T x) {
  Vertex<T> v(x);
  this->vertices.insert(v);
}

template<class T>
void Graph<T>::remove_vertex(T x) {
  this->vertices.remove(this->vertices.find(x));
}

template<class T>
void Graph<T>::add_edge(T x, T y, int weight, float angle) {
  Vertex<T> vx = get_vertex(x);
  Vertex<T> vy = get_vertex(y);

  Edge<T> e1(weight, angle, vy);
  vx.getEdges()->insert(e1);

  Edge<T> e2(weight, angle, vx);
  vy.getEdges()->insert(e2);
}

template<class T>
void Graph<T>::remove_edge(T x, T y) {
  Vertex<T> vx = get_vertex(x);
  Vertex<T> vy = get_vertex(y);

  int max = vx.getEdges()->size();
  for(int i=1; i<max; i++) {
    Edge<T> e = vx.getEdges()->get(i)->getData();
    for(auto j : e.getVertices()) {
      Vertex<T> v = j->second;
      if(v == vy)
        vx.getEdges()->remove(i);
    }
  }
}

template<class T>
List<Vertex<T>> Graph<T>::search(T origin, T destination) {
  List<Vertex<T>> result;
  return result;
}

template<class T>
Vertex<T> Graph<T>::get_vertex(T x) {
  return this->vertices.get(this->vertices.find(x))->getData();
}

template<class T>
Edge<T> Graph<T>::get_edge(T x, T y) {
  Vertex<T> vx = get_vertex(x);
  Vertex<T> vy = get_vertex(y);

  List<Edge<T>> * edges = vx.getEdges();
  for(int i=1; i<edges->size(); i++) {
    Edge<T> e = edges->get(i)->getData();
    for(auto j : e.getVertices()) {
      Vertex<T> v = j->second;
      if(v == vy) return e;
    }
  }

  return nullptr;
}

#endif  // LIB_GRAPH_H
