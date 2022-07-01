#ifndef LIB_PAIR_H
#define LIB_PAIR_H

#include "list.h"

template<class K, class V>
class Pair {
private:
  K key;
  V value;
  Pair<K,V> * previous;
  Pair<K,V> * next;
public:
  Pair();
  Pair(K key, V value);
  ~Pair();

  K getKey();
  void setKey(K key);

  V getValue();
  void setValue(V value);

  Pair<K,V> * getPrevious();
  void setPrevious(Pair<K,V> * previous);

  Pair<K,V> * getNext();
  void setNext(Pair<K,V> * next);
};

template<class K, class V>
Pair<K,V>::Pair() {
  this->key = K();
  this->value = V();
  this->previous = nullptr;
  this->next = nullptr;
}

template<class K, class V>
Pair<K,V>::Pair(K key, V value) {
  this->key = key;
  this->value = value;
  this->previous = nullptr;
  this->next = nullptr;
}

template<class K, class V>
Pair<K,V>::~Pair() {
  this->previous = nullptr;
  this->next = nullptr;
}

template<class K, class V>
K Pair<K,V>::getKey() {
  return this->key;
}

template<class K, class V>
void Pair<K,V>::setKey(K key) {
  this->key = key;
}

template<class K, class V>
V Pair<K,V>::getValue() {
  return this->value;
}

template<class K, class V>
void Pair<K,V>::setValue(V value) {
  this->value = value;
}

template<class K, class V>
Pair<K,V> * Pair<K,V>::getPrevious() {
  return this->previous;
}

template<class K, class V>
void Pair<K,V>::setPrevious(Pair * previous) {
  this->previous = previous;
}

template<class K, class V>
Pair<K,V> * Pair<K,V>::getNext() {
  return this->next;
}

template<class K, class V>
void Pair<K,V>::setNext(Pair * next) {
  this->next = next;
}

#endif  // LIB_PAIR_H
