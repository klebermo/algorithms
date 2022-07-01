#ifndef LIB_NODE_TREE_H
#define LIB_NODE_TREE_H

template<class T>
class NodeTree {
private:
  T data;
  NodeTree * left;
  NodeTree * right;
public:
  NodeTree();
  ~NodeTree();

  T getData();
  void setData(T value);

  NodeTree * getLeft();
  void setLeft(NodeTree<T> * left);

  NodeTree * getRight();
  void setRight(NodeTree<T> * right);
};

template<class T>
NodeTree<T>::NodeTree() {
  this->data = T();
  this->left = nullptr;
  this->right = nullptr;
}

template<class T>
NodeTree<T>::~NodeTree() {
  this->left = nullptr;
  this->right = nullptr;
}

template<class T>
T NodeTree<T>::getData() {
  return this->data;
}

template<class T>
void NodeTree<T>::setData(T value) {
  this->data = value;
}

template<class T>
NodeTree<T> * NodeTree<T>::getLeft() {
  return this->left;
}

template<class T>
void NodeTree<T>::setLeft(NodeTree<T> * left) {
  this->left = left;
}

template<class T>
NodeTree<T> * NodeTree<T>::getRight() {
  return this->right;
}

template<class T>
void NodeTree<T>::setRight(NodeTree<T> * right) {
  this->right = right;
}

#endif  // LIB_NODE_TREE_H
