#ifndef LIB_MAP_H
#define LIB_MAP_H

#include "pair.h"

template<class K, class V>
class Map {
private:
  Pair<K,V> * first;
public:
  Map();
  ~Map();

  void insert(K key, V value);
  void update(K key, V value);
  void remove(K key);
  int size();
  Pair<K,V> * get(K key);
  List<K> keys();
};

template<class K, class V>
Map<K,V>::Map() {
  this->first = nullptr;
}

template<class K, class V>
Map<K,V>::~Map() {
  //
}

template<class K, class V>
void Map<K,V>::insert(K key, V value) {
  Pair<K,V> * aux = this->first;
  Pair<K,V> * auxPrevious = nullptr;

  if(this->first == nullptr) {
    this->first = new Pair<K,V>(key, value);
  } else {
    while(aux != nullptr) {
      auxPrevious = aux;
      aux = aux->getNext();
    }
    aux = new Pair<K,V>(key, value);
    aux->setPrevious(auxPrevious);
    auxPrevious->setNext(aux);
  }
}

template<class K, class V>
void Map<K,V>::update(K key, V value) {
  Pair<K,V> * aux = this->first;

  while(aux != nullptr) {
    if(aux->getKey() == key) {
      aux->setKey(key);
      aux->setValue(value);
      break;
    }
    aux = aux->getNext();
  }
}

template<class K, class V>
void Map<K,V>::remove(K key) {
  Pair<K,V> * aux = this->first;
  Pair<K,V> * auxPrevious = nullptr;

  while(aux != nullptr) {
    if(aux->getKey() == key) {
      auxPrevious->setNext(aux->getNext());
      break;
    }
    auxPrevious = aux;
    aux = aux->getNext();
  }
}

template<class K, class V>
int Map<K,V>::size() {
  Pair<K,V> * aux = this->first;
  int count = 1;

  while(aux != nullptr) {
    aux = aux->getNext();
    count++;
  }

  return count;
}

template<class K, class V>
Pair<K,V> * Map<K,V>::get(K key) {
  Pair<K,V> * aux = this->first;

  while(aux != nullptr) {
    if(aux->getKey() == key)
      return aux;
    aux = aux->getNext();
  }

  return nullptr;
}

template<class K, class V>
List<K> Map<K,V>::keys() {
  List<K> result;

  Pair<K,V> * aux = this->first;
  while(aux != nullptr) {
    result.insert(aux->getKey());
    aux = aux->getNext();
  }

  return result;
}

#endif  // LIB_MAP_H
