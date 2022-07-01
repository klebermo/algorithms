#ifndef LIB_GRAPH_H
#define LIB_GRAPH_H

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

  void add_edge(T x, T y);
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
  Vertex vx = get_vertex(x);
  Vertex vy = get_vertex(y);

  int max = vx.getEdges()->size();
  for(int i=1; i<=max; i++)
    if(vx.getEdges()->get(i)->getData().getDestination() == vy)
      return true;

  return false;
}

template<class T>
List<Vertex<T>> Graph<T>::neighbors(T x) {
  List<Vertex<T>> result;

  Vertex vx = get_vertex(x);
  int max = vx.getEdges()->size();
  for(int i=1; i<=max; i++)
    result.insert(vx.getEdges()->get(i)->getData().getDestination());

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
void Graph<T>::add_edge(T x, T y) {
  Vertex vx = get_vertex(x);
  Vertex vy = get_vertex(y);

  Edge<T> e1(1, 1.3f, vy);
  vx.getEdges()->insert(e1);

  Edge<T> e2(2, 1.4f, vx);
  vy.getEdges()->insert(e2);
}

template<class T>
void Graph<T>::remove_edge(T x, T y) {
  Vertex vx = get_vertex(x);
  Vertex vy = get_vertex(y);

  int max = vx.getEdges()->size();
  for(int i=1; i<max; i++)
    if(vx.getEdges()->get(i)->getData().getDestination() == vy)
      vx.getEdges()->remove(i);
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

  for(int i=1; i<vx.getEdges()->size(); i++) {
    Edge<T> e =vx.getEdges()->get(i)->getData();
    if(e.getDestination() == vy) return e;
  }
}

#endif  // LIB_GRAPH_H
