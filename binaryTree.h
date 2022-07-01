#ifndef LIB_BINARY_TREE_H
#define LIB_BINARY_TREE_H

#include "node_tree.h"

template<class T>
class BinaryTree {
protected:
  NodeTree<T> * root;
public:
  BinaryTree();
  ~BinaryTree();

  NodeTree<T> * getRoot();
  void setRoot(NodeTree<T> * node);

  void insert(T value);
  void update(T old_value, T new_value);
  void remove(T value);

  List<NodeTree<T>*> preOrder();
  List<NodeTree<T>*> inOrder();
  List<NodeTree<T>*> postOrder();

  void preOrder(NodeTree<T> * node, List<NodeTree<T>*> * list);
  void inOrder(NodeTree<T> * node, List<NodeTree<T>*> * list);
  void postOrder(NodeTree<T> * node, List<NodeTree<T>*> * list);

  List<NodeTree<T>*> level(int value);
  int levelOf(NodeTree<T> * data);
  int levelOf(NodeTree<T> * node, NodeTree<T> * target, int level);
  int height();
  int height(NodeTree<T> * node, int height);
  List<NodeTree<T>*> leafs();
};

template<class T>
BinaryTree<T>::BinaryTree() {
  this->root = nullptr;
}

template<class T>
BinaryTree<T>::~BinaryTree() {
  //
}

template<class T>
NodeTree<T> * BinaryTree<T>::getRoot() {
  return this->root;
}

template<class T>
void BinaryTree<T>::setRoot(NodeTree<T> * node) {
  this->root = node;
}

template<class T>
void BinaryTree<T>::insert(T value) {
  if(this->root == nullptr) {
    this->root = new NodeTree<T>();
    this->root->setData(value);
    return;
  } else {
    NodeTree<T> * aux = this->root;
    NodeTree<T> * auxParent = nullptr;

    while(aux != nullptr) {
      if(aux->getData() > value) {
        auxParent = aux;
        aux = aux->getLeft();
      } else {
        auxParent = aux;
        aux = aux->getRight();
      }
    }

    if(aux == nullptr) {
      aux = new NodeTree<T>();
      aux->setData(value);
      if(auxParent->getData() > value)
        auxParent->setLeft(aux);
      else
        auxParent->setRight(aux);
    }
  }
}

template<class T>
void BinaryTree<T>::update(T old_value, T new_value) {
  if(this->root == nullptr) {
    return;
  } else {
    NodeTree<T> aux = root;

    while(aux != nullptr) {
      if(aux->getData() == old_value) {
        aux->setData(new_value);
        break;
      }

      if(aux->getData() > old_value)
        aux = aux->getLeft();
      else
        aux = aux->getRight();
    }
  }
}

template<class T>
void BinaryTree<T>::remove(T value) {
  if(this->root == nullptr) {
    return;
  } else {
    NodeTree<T> aux = root;
    NodeTree<T> auxParent = nullptr;

    while(aux != nullptr) {
      if(aux->getData() == value)
        break;

      if(aux->getData() > value) {
        auxParent = aux;
        aux = aux->getLeft();
      } else {
        auxParent = aux;
        aux = aux->getRight();
      }
    }

    if(aux->getLeft() == nullptr && aux->getRight() == nullptr) {
      if(auxParent->getLeft() != nullptr && auxParent->getLeft()->getData() == value->getData())
        auxParent->setLeft(nullptr);
      if(auxParent->getRight() != nullptr && auxParent->getRight()->getData() == value->getData())
        auxParent->setRight(nullptr);
    } else if(aux->getLeft() == nullptr && aux->getRight() != nullptr) {
      if(auxParent->getLeft() != nullptr && auxParent->getLeft()->getData() == value->getData())
        auxParent->setLeft(aux->getRight());
      if(auxParent->getRight() != nullptr && auxParent->getRight()->getData() == value->getData())
        auxParent->setRight(aux->getRight());
    } else if(aux->getLeft() != nullptr && aux->getRight() == nullptr) {
      if(auxParent->getLeft() != nullptr && auxParent->getLeft()->getData() == value->getData())
        auxParent->setLeft(aux->getLeft());
      if(auxParent->getRight() != nullptr && auxParent->getRight()->getData() == value->getData())
        auxParent->setRight(aux->getLeft());
    } else {
      List<T> list = this->inOrder();
      int index = list.find(value);
      NodeTree<T> item = list.get(index-1);
      NodeTree<T> toDelete = list.get(index-1);
      this->remove(toDelete->getData());
      aux->setData(item->getData());
    }
  }
}

template<class T>
List<NodeTree<T>*> BinaryTree<T>::preOrder() {
  List<NodeTree<T>*> list;

  if(this->root != nullptr) {
    list.insert(this->root);
    preOrder(this->root->getLeft(), &list);
    preOrder(this->root->getRight(), &list);
  }

  return list;
}

template<class T>
List<NodeTree<T>*> BinaryTree<T>::inOrder() {
  List<NodeTree<T>*> list;

  if(this->root != nullptr) {
    inOrder(this->root->getLeft(), &list);
    list.insert(this->root);
    inOrder(this->root->getRight(), &list);
  }

  return list;
}

template<class T>
List<NodeTree<T>*> BinaryTree<T>::postOrder() {
  List<NodeTree<T>*> list;

  if(this->root != nullptr) {
    postOrder(this->root->getLeft(), &list);
    postOrder(this->root->getRight(), &list);
    list.insert(this->root);
  }

  return list;
}

template<class T>
void BinaryTree<T>::preOrder(NodeTree<T> * node, List<NodeTree<T>*> * list) {
  if(node != nullptr) {
    list->insert(node);
    preOrder(node->getLeft(), list);
    preOrder(node->getRight(), list);
  }
}

template<class T>
void BinaryTree<T>::inOrder(NodeTree<T> * node, List<NodeTree<T>*> * list) {
  if(node != nullptr) {
    inOrder(node->getLeft(), list);
    list->insert(node);
    inOrder(node->getRight(), list);
  }
}

template<class T>
void BinaryTree<T>::postOrder(NodeTree<T> * node, List<NodeTree<T>*> * list) {
  if(node != nullptr) {
    postOrder(node->getLeft(), list);
    postOrder(node->getRight(), list);
    list->insert(node);
  }
}

template<class T>
List<NodeTree<T>*> BinaryTree<T>::level(int value) {
  List<NodeTree<T>*> result;

  List<NodeTree<T>*> list = this->inOrder();
  for(int i=1; i<=list.size(); i++)
    if(this->levelOf(list.get(i)->getData()) == value) result.insert(list.get(i)->getData());

  return result;
}

template<class T>
int BinaryTree<T>::levelOf(NodeTree<T> * target) {
  return this->levelOf(this->root, target, 1);
}

template<class T>
int BinaryTree<T>::levelOf(NodeTree<T> * node, NodeTree<T> * target, int level) {
  if(node == nullptr)
    return 0;

  if(node->getData() == target->getData())
    return level;

  int down_level = levelOf(node->getLeft(), target, level+1);
  if(down_level != 0)
    return down_level;

  down_level = levelOf(node->getRight(), target, level+1);
  return down_level;
}

template<class T>
int BinaryTree<T>::height() {
  if(this->root == nullptr)
    return 0;

  int left_height = this->height(this->root->getLeft(), 1);
  int right_height = this->height(this->root->getRight(), 1);

  if(left_height > right_height)
    return left_height;
  else
    return right_height;
}

template<class T>
int BinaryTree<T>::height(NodeTree<T> * node, int height) {
  if(node == nullptr)
    return height;

  int left_height = this->height(node->getLeft(), height+1);
  int right_height = this->height(node->getRight(), height+1);

  if(left_height > right_height)
    return left_height;
  else
    return right_height;
}

template<class T>
List<NodeTree<T>*> BinaryTree<T>::leafs() {
  List<NodeTree<T>*> result = this->level(this->height());
  return result;
}

#endif  // LIB_BINARY_TREE_H
