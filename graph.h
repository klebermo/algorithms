#ifndef LIB_GRAPH_H
#define LIB_GRAPH_H

#include "list.h"
#include "edge.h"

#include <unordered_map>
#include <stack>
#include <queue>

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

  List<T> searchDepthFirst(T origin, T destination);
  List<T> searchBreathFirst(T origin, T destination);
  List<T> searchAlphaBetaPruning(T origin, T destination);
  List<T> searchAStar(T origin, T destination);
  List<T> searchBStar(T origin, T destination);
  List<T> searchDStar(T origin, T destination);
  List<T> searchSSSStar(T origin, T destination);
  List<T> searchBestFirst(T origin, T destination);
  List<T> searchBeam(T origin, T destination);
  List<T> searchBidirecional(T origin, T destination);
  List<T> searchFringe(T origin, T destination);
  List<T> searchJumpPoint(T origin, T destination);
  List<T> searchMonteCarloTree(T origin, T destination);

  List<T> searchBellmanFord(T origin, T destination);
  List<T> searchDijkstra(T origin, T destination);
  List<T> searchFloydWarshall(T origin, T destination);
  List<T> searchJohnson(T origin, T destination);
  List<T> searchShortestPathFaster(T origin, T destination);
  List<T> searchYen(T origin, T destination);

  List<T> searchBoruvka(T origin, T destination);
  List<T> searchKruskal(T origin, T destination);
  List<T> searchPrim(T origin, T destination);
  List<T> searchReverseDelete(T origin, T destination);

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

  max = vy.getEdges()->size();
  for(int i=1; i<max; i++) {
    Edge<T> e = vy.getEdges()->get(i)->getData();
    for(auto j : e.getVertices()) {
      Vertex<T> v = j->second;
      if(v == vx)
        vy.getEdges()->remove(i);
    }
  }
}

template<class T>
List<T> Graph<T>::searchDepthFirst(T origin, T destination) {
  List<T> visited;
  std::unordered_map<T, bool> visitedMap;
  std::stack<Vertex<T>> stack;

  // inicializa o mapa de visitados
  for (int i=1; i<=vertices.size(); i++) {
    Vertex<T> vertex = vertices.get(i)->getData();
    visitedMap[vertex.getData()] = false;
  }

  // adiciona o vértice inicial na pilha e o marca como visitado
  stack.push(get_vertex(origin));
  visitedMap[origin] = true;

  // inicia o algoritmo DFS
  while (!stack.empty()) {
    Vertex<T> current = stack.top();
    stack.pop();

    visited.insert(current.getData()); // adiciona o vértice atual à lista de visitados

    // verifica se o destino foi alcançado
    if (current.getData() == destination) {
      break;
    }

    // percorre todos os vizinhos do vértice atual
    List<Vertex<T>> neighbors_list = neighbors(current.getData());
    for (int i=1; i<=neighbors_list.size(); i++) {
      Vertex<T> neighbor = neighbors_list.get(i)->getData();
      T neighborData = neighbor.getData();

      // visita o vizinho, caso ainda não tenha sido visitado
      if (!visitedMap[neighborData]) {
        visitedMap[neighborData] = true; // marca o vizinho como visitado
        stack.push(neighbor); // adiciona o vizinho na pilha
      }
    }
  }

  return visited;
}

template<class T>
List<T> Graph<T>::searchBreathFirst(T origin, T destination) {
  List<T> visited;
  std::unordered_map<T, bool> visitedMap;
  std::queue<Vertex<T>> queue;

  // inicializa o mapa de visitados
  for (int i=1; i<=vertices.size(); i++) {
    Vertex<T> vertex = vertices.get(i)->getData();
    visitedMap[vertex.getData()] = false;
  }

  // adiciona o vértice inicial na fila e o marca como visitado
  queue.push(get_vertex(origin));
  visitedMap[origin] = true;

  // inicia o algoritmo BFS
  while (!queue.empty()) {
    Vertex<T> current = queue.front();
    queue.pop();

    visited.insert(current.getData()); // adiciona o vértice atual à lista de visitados

    // verifica se o destino foi alcançado
    if (current.getData() == destination) {
      break;
    }

    // percorre todos os vizinhos do vértice atual
    List<Vertex<T>> neighbors_list = neighbors(current.getData());
    for (int i=1; i<=neighbors_list.size(); i++) {
      Vertex<T> neighbor = neighbors_list.get(i)->getData();
      T neighborData = neighbor.getData();

      // visita o vizinho, caso ainda não tenha sido visitado
      if (!visitedMap[neighborData]) {
        visitedMap[neighborData] = true; // marca o vizinho como visitado
        queue.push(neighbor); // adiciona o vizinho na fila
      }
    }
  }

  return visited;
}

template<class T>
List<T> Graph<T>::searchAlphaBetaPruning(T origin, T destination) {
  List<T> result;
  return result;
}

template<class T>
List<T> Graph<T>::searchAStar(T origin, T destination) {
  List<T> result;
  return result;
}

template<class T>
List<T> Graph<T>::searchBStar(T origin, T destination) {
  List<T> result;
  return result;
}

template<class T>
List<T> Graph<T>::searchDStar(T origin, T destination) {
  List<T> result;
  return result;
}

template<class T>
List<T> Graph<T>::searchSSSStar(T origin, T destination) {
  List<T> result;
  return result;
}

template<class T>
List<T> Graph<T>::searchBestFirst(T origin, T destination) {
  List<T> result;
  return result;
}

template<class T>
List<T> Graph<T>::searchBeam(T origin, T destination) {
  List<T> result;
  return result;
}

template<class T>
List<T> Graph<T>::searchBidirecional(T origin, T destination) {
  List<T> result;
  return result;
}

template<class T>
List<T> Graph<T>::searchFringe(T origin, T destination) {
  List<T> result;
  return result;
}

template<class T>
List<T> Graph<T>::searchJumpPoint(T origin, T destination) {
  List<T> result;
  return result;
}

template<class T>
List<T> Graph<T>::searchMonteCarloTree(T origin, T destination) {
  List<T> result;
  return result;
}

template<class T>
List<T> Graph<T>::searchBellmanFord(T origin, T destination) {
  List<T> result;
  return result;
}

template<class T>
List<T> Graph<T>::searchDijkstra(T origin, T destination) {
  List<T> result;
  return result;
}

template<class T>
List<T> Graph<T>::searchFloydWarshall(T origin, T destination) {
  List<T> result;
  return result;
}

template<class T>
List<T> Graph<T>::searchJohnson(T origin, T destination) {
  List<T> result;
  return result;
}

template<class T>
List<T> Graph<T>::searchShortestPathFaster(T origin, T destination) {
  List<T> result;
  return result;
}

template<class T>
List<T> Graph<T>::searchYen(T origin, T destination) {
  List<T> result;
  return result;
}

template<class T>
List<T> Graph<T>::searchBoruvka(T origin, T destination) {
  List<T> result;
  return result;
}

template<class T>
List<T> Graph<T>::searchKruskal(T origin, T destination) {
  List<T> result;
  return result;
}

template<class T>
List<T> Graph<T>::searchPrim(T origin, T destination) {
  List<T> result;
  return result;
}

template<class T>
List<T> Graph<T>::searchReverseDelete(T origin, T destination) {
  List<T> result;
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
