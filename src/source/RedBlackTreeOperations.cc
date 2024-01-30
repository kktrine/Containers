#include "../headers/BasedClassForMapAndSet.h"

using namespace s21;

/////////////////////////////////////
/////CONSTRUCTORS AND DESTRUCTOR/////
/////////////////////////////////////

template <typename Key, typename Value>
RedBlackTree<Key, Value>::RedBlackTree() {
  nil = new Node(Key(), Value());
  nil->color = BLACK;
  root = nil;
}

template <typename Key, typename Value>
RedBlackTree<Key, Value>::RedBlackTree(const RedBlackTree& OtherTree) {
  this->nil = new Node(Key(), Value());
  this->nil->color = BLACK;
  this->root = nil;
  Node* OtherRoot = OtherTree.root;
  this->InsertSecondTree(OtherRoot, OtherTree.nil);
}

template <typename Key, typename Value>
RedBlackTree<Key, Value>::RedBlackTree(RedBlackTree&& OtherTree)
    : root(OtherTree.root), nil(OtherTree.nil) {
  OtherTree.root = nullptr;
  OtherTree.nil = nullptr;
}

template <typename Key, typename Value>
RedBlackTree<Key, Value>::RedBlackTree(
    std::initializer_list<std::pair<const Key, Value>> const& items) {
  nil = new Node(Key(), Value());
  nil->color = BLACK;
  root = nil;
  for (std::pair<const Key, Value> i : items) {
    insert(i.first, i.second);
  }
}

template <typename Key, typename Value>
RedBlackTree<Key, Value>::RedBlackTree(std::initializer_list<Key> const& items,
                                       bool isMultiset) {
  nil = new Node(Key(), Key());
  nil->color = BLACK;
  root = nil;
  for (Key i : items) {
    if (isMultiset) {
      insert_multiset(i);
    } else {
      insert(i, i);
    }
  }
}

template <typename Key, typename Value>
RedBlackTree<Key, Value>::~RedBlackTree() {
  destroy(root);
  if (nil != nullptr) {
    delete nil;
  }
}

template <typename Key, typename Value>
void RedBlackTree<Key, Value>::destroy(Node* root) noexcept {
  if (root != nil && root != nullptr) {
    destroy(root->left);
    destroy(root->right);
    delete root;
  }
}

// assignment_operator_move
template <typename Key, typename Value>
RedBlackTree<Key, Value>& RedBlackTree<Key, Value>::operator=(
    RedBlackTree&& OtherTree) noexcept {
  destroy(this->root);
  delete this->nil;
  this->root = OtherTree.root;
  this->nil = OtherTree.nil;
  OtherTree.root = nullptr;
  OtherTree.nil = nullptr;
  return *this;
}

// assignment_operator_move_copy
template <typename Key, typename Value>
RedBlackTree<Key, Value>& RedBlackTree<Key, Value>::operator=(
    const RedBlackTree& OtherTree) noexcept {
  destroy(this->root);
  this->root = nil;
  Node* OtherRoot = OtherTree.root;
  this->InsertSecondTree(OtherRoot, OtherTree.nil);
  return *this;
}

//////////////////////////
/////ITERATOR METHODS/////
//////////////////////////

template <typename Key, typename Value>
typename RedBlackTree<Key, Value>::Node*
RedBlackTree<Key, Value>::Iterator::FindMaximum() noexcept {
  if (CurrentNode->left == nullptr) {
    return nullptr;
  }
  Node* LocalNode = CurrentNode;
  while (LocalNode->parent != nullptr) {
    LocalNode = LocalNode->parent;
  }
  while (LocalNode->right->right != nullptr) {
    LocalNode = LocalNode->right;
  }
  return LocalNode;
}

template <typename Key, typename Value>
typename RedBlackTree<Key, Value>::Node*
RedBlackTree<Key, Value>::Iterator::FindMinimum() noexcept {
  if (CurrentNode->left == nullptr) {
    return nullptr;
  }
  Node* LocalNode = CurrentNode;
  while (LocalNode->parent != nullptr) {
    LocalNode = LocalNode->parent;
  }
  while (LocalNode->left->left != nullptr) {
    LocalNode = LocalNode->left;
  }
  return LocalNode;
}

template <typename Key, typename Value>
typename RedBlackTree<Key, Value>::Iterator&
RedBlackTree<Key, Value>::Iterator::operator++() noexcept {
  if (CurrentNode->right == nullptr) {
    return *this;
  }
  if (CurrentNode == FindMaximum()) {
    CurrentNode = CurrentNode->right;
    return *this;
  }
  if (CurrentNode->right->right != nullptr) {
    CurrentNode = CurrentNode->right;
    while (CurrentNode->left->left != nullptr) {
      CurrentNode = CurrentNode->left;
    }
  } else {
    Node* preview = CurrentNode;
    CurrentNode = CurrentNode->parent;
    while (CurrentNode->right != nullptr && preview == CurrentNode->right) {
      preview = CurrentNode;
      CurrentNode = CurrentNode->parent;
    }
  }
  return *this;
}

template <typename Key, typename Value>
typename RedBlackTree<Key, Value>::Iterator&
RedBlackTree<Key, Value>::Iterator::operator--() noexcept {
  if (CurrentNode == FindMinimum()) {
    return *this;
  }
  if (CurrentNode->right == nullptr) {
    CurrentNode = CurrentNode->parent;
    return *this;
  }
  if (CurrentNode->left->left != nullptr) {
    CurrentNode = CurrentNode->left;
    while (CurrentNode->right->right != nullptr) {
      CurrentNode = CurrentNode->right;
    }
  } else {
    Node* preview = CurrentNode;
    CurrentNode = CurrentNode->parent;
    while (CurrentNode->left != nullptr && preview == CurrentNode->left) {
      preview = CurrentNode;
      CurrentNode = CurrentNode->parent;
    }
  }
  return *this;
}

template <typename Key, typename Value>
typename RedBlackTree<Key, Value>::Iterator
RedBlackTree<Key, Value>::Iterator::operator++(int) noexcept {
  Iterator NodeBeforeOperation = *this;
  ++(*this);
  return NodeBeforeOperation;
}

template <typename Key, typename Value>
std::pair<Key, Value>*
RedBlackTree<Key, Value>::Iterator::operator->() noexcept {
  AddressPair = &pair;
  AddressPair->first = CurrentNode->key;
  AddressPair->second = CurrentNode->value;
  return AddressPair;
}

////////////////////////////////
/////CONST_ITERATOR METHODS/////
////////////////////////////////

template <typename Key, typename Value>
typename RedBlackTree<Key, Value>::Node*
RedBlackTree<Key, Value>::const_Iterator::FindMinimum() noexcept {
  if (CurrentNode->left == nullptr) {
    return nullptr;
  }
  Node* LocalNode = CurrentNode;
  while (LocalNode->parent != nullptr) {
    LocalNode = LocalNode->parent;
  }
  while (LocalNode->left->left != nullptr) {
    LocalNode = LocalNode->left;
  }
  return LocalNode;
}

template <typename Key, typename Value>
typename RedBlackTree<Key, Value>::Node*
RedBlackTree<Key, Value>::const_Iterator::FindMaximum() noexcept {
  if (CurrentNode->left == nullptr) {
    return nullptr;
  }
  Node* LocalNode = CurrentNode;
  while (LocalNode->parent != nullptr) {
    LocalNode = LocalNode->parent;
  }
  while (LocalNode->right->right != nullptr) {
    LocalNode = LocalNode->right;
  }
  return LocalNode;
}

template <typename Key, typename Value>
const typename RedBlackTree<Key, Value>::const_Iterator&
RedBlackTree<Key, Value>::const_Iterator::operator++() noexcept {
  if (CurrentNode->right == nullptr) {
    return *this;
  }
  if (CurrentNode == FindMaximum()) {
    CurrentNode = CurrentNode->right;
    return *this;
  }
  if (CurrentNode->right->right != nullptr) {
    CurrentNode = CurrentNode->right;
    while (CurrentNode->left->left != nullptr) {
      CurrentNode = CurrentNode->left;
    }
  } else {
    Node* preview = CurrentNode;
    CurrentNode = CurrentNode->parent;
    while (CurrentNode->right != nullptr && preview == CurrentNode->right) {
      preview = CurrentNode;
      CurrentNode = CurrentNode->parent;
    }
  }
  return *this;
}

template <typename Key, typename Value>
const typename RedBlackTree<Key, Value>::const_Iterator&
RedBlackTree<Key, Value>::const_Iterator::operator--() noexcept {
  if (CurrentNode == FindMinimum()) {
    return *this;
  }
  if (CurrentNode->right == nullptr) {
    CurrentNode = CurrentNode->parent;
    return *this;
  }
  if (CurrentNode->left->left != nullptr) {
    CurrentNode = CurrentNode->left;
    while (CurrentNode->right->right != nullptr) {
      CurrentNode = CurrentNode->right;
    }
  } else {
    Node* preview = CurrentNode;
    CurrentNode = CurrentNode->parent;
    while (CurrentNode->left != nullptr && preview == CurrentNode->left) {
      preview = CurrentNode;
      CurrentNode = CurrentNode->parent;
    }
  }
  return *this;
}

template <typename Key, typename Value>
const typename RedBlackTree<Key, Value>::const_Iterator
RedBlackTree<Key, Value>::const_Iterator::operator++(int) noexcept {
  const_Iterator NodeBeforeOperation = *this;
  ++(*this);
  return NodeBeforeOperation;
}

template <typename Key, typename Value>
const std::pair<Key, Value>*
RedBlackTree<Key, Value>::const_Iterator::operator->() noexcept {
  AddressPair = &pair;
  AddressPair->first = CurrentNode->key;
  AddressPair->second = CurrentNode->value;
  return AddressPair;
}

//////////////////////////////
/////FIND PRIVATE METHODS/////
//////////////////////////////

template <typename Key, typename Value>
typename RedBlackTree<Key, Value>::Node*
RedBlackTree<Key, Value>::FindExistOrNo(const Key& key) const noexcept {
  Node* CurrentNode = root;
  while (CurrentNode != nullptr && CurrentNode != nil) {
    if (CurrentNode->key > key) {
      CurrentNode = CurrentNode->left;
    } else if (CurrentNode->key < key) {
      CurrentNode = CurrentNode->right;
    } else {
      return CurrentNode;
    }
  }
  return nullptr;
}

template <typename Key, typename Value>
typename RedBlackTree<Key, Value>::Node*
RedBlackTree<Key, Value>::FindParentIfNoExist(Key& key) const noexcept {
  Node* CurrentNode = root;
  while (CurrentNode != nullptr && CurrentNode != nil) {
    if (CurrentNode->left == nil && CurrentNode->right == nil) {
      return CurrentNode;
    }
    if (key < CurrentNode->key) {
      if (CurrentNode->left == nil) {
        return CurrentNode;
      }
      CurrentNode = CurrentNode->left;
    } else if (key >= CurrentNode->key) {
      if (CurrentNode->right == nil) {
        return CurrentNode;
      }
      CurrentNode = CurrentNode->right;
    }
  }
  return nullptr;
}

template <typename Key, typename Value>
typename RedBlackTree<Key, Value>::Node*
RedBlackTree<Key, Value>::FindFirstElementAkaMinimum() const noexcept {
  Node* CurrentNode = root;
  while (CurrentNode != nil && CurrentNode->left != nil) {
    CurrentNode = CurrentNode->left;
  }
  return CurrentNode;
}

template <typename Key, typename Value>
typename RedBlackTree<Key, Value>::Node*
RedBlackTree<Key, Value>::FindLastElementAkaMaximum() const noexcept {
  Node* CurrentNode = root;
  while (CurrentNode != nil && CurrentNode->right != nil) {
    CurrentNode = CurrentNode->right;
  }
  return CurrentNode;
}

template <typename Key, typename Value>
typename RedBlackTree<Key, Value>::Node*
RedBlackTree<Key, Value>::FindMinBeginCurrentNode(Node* node) const noexcept {
  Node* MinimumNode = node;
  while (MinimumNode != nil && MinimumNode->left != nil) {
    MinimumNode = MinimumNode->left;
  }
  return MinimumNode;
}

//////////////////////////////
/////GET PRIVATE METHODS/////
//////////////////////////////

template <typename Key, typename Value>
typename RedBlackTree<Key, Value>::Node*
RedBlackTree<Key, Value>::GetGrandparent(Node* node) const noexcept {
  if (node != nil && node != nullptr && node->parent != nullptr) {
    return node->parent->parent;
  } else {
    return nullptr;
  }
}

template <typename Key, typename Value>
typename RedBlackTree<Key, Value>::Node* RedBlackTree<Key, Value>::GetUncle(
    Node* node) const noexcept {
  Node* grandparent = GetGrandparent(node);
  if (grandparent == nullptr) {
    return nullptr;
  }
  if (node->parent == grandparent->left) {
    return grandparent->right;
  } else {
    return grandparent->left;
  }
}

////////////////////////
/////INSERT METHODS/////
////////////////////////

template <typename Key, typename Value>
typename RedBlackTree<Key, Value>::Node* RedBlackTree<Key, Value>::Rotate(
    Node* node, RotateDirection direction) noexcept {
  Node* Child = nullptr;
  if (direction == LEFT) {
    Child = node->right;
    node->right = Child->left;
    if (Child->left != nil) {
      Child->left->parent = node;
    }
  } else {
    Child = node->left;
    node->left = Child->right;
    if (Child->right != nil) {
      Child->right->parent = node;
    }
  }
  Child->parent = node->parent;
  if (node->parent == nullptr) {
    root = Child;
  } else if (node == node->parent->left) {
    node->parent->left = Child;
  } else if (node == node->parent->right) {
    node->parent->right = Child;
  }
  if (direction == LEFT) {
    Child->left = node;
  } else {
    Child->right = node;
  }
  node->parent = Child;
  std::swap(node->color, Child->color);
  return node;
}

template <typename Key, typename Value>
void RedBlackTree<Key, Value>::InsertSecondTree(Node* node,
                                                Node* OtherNil) noexcept {
  if (node == OtherNil) {
    return;
  }
  InsertSecondTree(node->left, OtherNil);
  InsertSecondTree(node->right, OtherNil);
  this->insert_or_assign(node->key, node->value);
}

template <typename Key, typename Value>
std::pair<typename RedBlackTree<Key, Value>::Iterator, bool>
RedBlackTree<Key, Value>::insert(
    const std::pair<Key, Value>& PairValue) noexcept {
  Node* ExistNode = FindExistOrNo(PairValue.first);
  if (ExistNode != nullptr) {
    Iterator IteratorNode(ExistNode);
    return {IteratorNode, false};
  }
  return TreeInsert(PairValue.first, PairValue.second);
}

template <typename Key, typename Value>
std::pair<typename RedBlackTree<Key, Value>::Iterator, bool>
RedBlackTree<Key, Value>::insert(const Key& key, const Value& value) noexcept {
  Node* ExistNode = FindExistOrNo(key);
  if (ExistNode != nullptr) {
    Iterator IteratorNode(ExistNode);
    return {IteratorNode, false};
  }
  return TreeInsert(key, value);
}

template <typename Key, typename Value>
std::pair<typename RedBlackTree<Key, Value>::Iterator, bool>
RedBlackTree<Key, Value>::insert_or_assign(const Key& key,
                                           const Value& value) noexcept {
  Node* ExistNode = FindExistOrNo(key);
  if (ExistNode != nullptr) {
    ExistNode->value = value;
    Iterator IteratorNode(ExistNode);
    return {IteratorNode, false};
  }
  return TreeInsert(key, value);
}

template <typename Key, typename Value>
typename RedBlackTree<Key, Value>::Iterator
RedBlackTree<Key, Value>::insert_multiset(const Key& key) noexcept {
  std::pair<Iterator, bool> PairForResult = TreeInsert(key, key);
  return PairForResult.first;
}

template <typename Key, typename Value>
std::pair<typename RedBlackTree<Key, Value>::Iterator, bool>
RedBlackTree<Key, Value>::TreeInsert(Key key, Value value) {
  Node* NewNode = new Node(key, value);
  Node* ParentForNewNode = FindParentIfNoExist(key);
  NewNode->parent = ParentForNewNode;
  NewNode->left = nil;
  NewNode->right = nil;
  // Случай когда дерево пустое и новый элемент становится корнем дерева
  if (ParentForNewNode == nullptr) {
    root = NewNode;
    NewNode->color = BLACK;
    Iterator IteratorRoot(root);
    return {IteratorRoot, true};
  }
  if (ParentForNewNode->key <= NewNode->key) {
    ParentForNewNode->right = NewNode;
  } else {
    ParentForNewNode->left = NewNode;
  }
  Iterator IteratorNewNode(NewNode);
  BalanceTreeAfterInsert(ParentForNewNode, NewNode);
  nil->parent = FindLastElementAkaMaximum();
  return {IteratorNewNode, true};
}

template <typename Key, typename Value>
void RedBlackTree<Key, Value>::BalanceTreeAfterInsert(Node* ParentForNewNode,
                                                      Node* NewNode) noexcept {
  do {
    // Case I1 (Parent is black)
    if (ParentForNewNode->color == BLACK) {
      return;
    }
    // Case_I4 (Parent is red and root)
    if (GetGrandparent(NewNode) == nullptr) {
      InsertCaseGrandParentNoExist();
      return;
    }
    Node* Uncle = GetUncle(NewNode);
    RotateDirection DirectionUncle = LEFT;
    if (ParentForNewNode->parent->left == ParentForNewNode) {
      DirectionUncle = RIGHT;
    }
    if (Uncle->color == BLACK) {
      InsertCaseUncleBlack(NewNode, DirectionUncle);
      return;
    }
    // Case I2 (ParentForNewNode red and Uncle red)
    Uncle->color = BLACK;
    ParentForNewNode->color = BLACK;
    ParentForNewNode->parent->color = RED;
    NewNode = ParentForNewNode->parent;
  } while ((ParentForNewNode = NewNode->parent) != nullptr);
}

template <typename Key, typename Value>
void RedBlackTree<Key, Value>::InsertCaseGrandParentNoExist() noexcept {
  if (root->color == RED) {
    root->color = BLACK;
  }
}

template <typename Key, typename Value>
void RedBlackTree<Key, Value>::InsertCaseUncleBlack(
    Node* NewNode, RotateDirection DirectionUncle) noexcept {
  RotateDirection DirectionNode = LEFT;
  if (NewNode == NewNode->parent->right) {
    DirectionNode = RIGHT;
  }
  RotateDirection RotateDir = (DirectionUncle == RIGHT ? LEFT : RIGHT);
  if (DirectionNode == DirectionUncle) {
    NewNode = Rotate(NewNode->parent, RotateDir);
  }
  Rotate(NewNode->parent->parent, DirectionUncle);
}

/////////////////////////////////
/////RETURN ITERATOR METHODS/////
/////////////////////////////////

template <typename Key, typename Value>
typename RedBlackTree<Key, Value>::Iterator
RedBlackTree<Key, Value>::begin() noexcept {
  Node* node = FindFirstElementAkaMinimum();
  RedBlackTree::Iterator iter(node);
  return iter;
}

template <typename Key, typename Value>
typename RedBlackTree<Key, Value>::Iterator
RedBlackTree<Key, Value>::end() noexcept {
  Iterator iter(nil);
  return iter;
}

///////////////////////////////////////
/////RETURN CONST_ITERATOR METHODS/////
///////////////////////////////////////

template <typename Key, typename Value>
typename RedBlackTree<Key, Value>::const_Iterator
RedBlackTree<Key, Value>::cbegin() noexcept {
  Node* node = FindFirstElementAkaMinimum();
  RedBlackTree::const_Iterator iter(node);
  return iter;
}

template <typename Key, typename Value>
typename RedBlackTree<Key, Value>::const_Iterator
RedBlackTree<Key, Value>::cend() noexcept {
  const_Iterator iter(nil);
  return iter;
}

////////////////////////
/////ELEMENT ACCESS/////
////////////////////////

template <typename Key, typename Value>
Value& RedBlackTree<Key, Value>::operator[](const Key& key) noexcept {
  Node* NodeFind = FindExistOrNo(key);
  if (NodeFind != nullptr) {
    return NodeFind->value;
  }
  this->insert(key);
  Node* Node = FindExistOrNo(key);
  return Node->value;
}

template <typename Key, typename Value>
Value& RedBlackTree<Key, Value>::at(const Key& key) {
  Node* node = FindExistOrNo(key);
  if (node == nullptr) {
    throw std::out_of_range("Out of range, No matches found for key");
  }
  return node->value;
}

//////////////////
/////CAPACITY/////
//////////////////

template <typename Key, typename Value>
bool RedBlackTree<Key, Value>::empty() const noexcept {
  if (root == nil || root == nullptr) {
    return true;
  } else {
    return false;
  }
}

template <typename Key, typename Value>
size_t RedBlackTree<Key, Value>::size() const noexcept {
  Node* node = root;
  size_t SizeTree = 0;
  RecursivSize(node, SizeTree);
  return SizeTree;
}

template <typename Key, typename Value>
void RedBlackTree<Key, Value>::RecursivSize(Node* node,
                                            size_t& size) const noexcept {
  if (node == nil || node == nullptr) {
    return;
  }
  RecursivSize(node->left, size);
  RecursivSize(node->right, size);
  size++;
}

template <typename Key, typename Value>
constexpr size_t RedBlackTree<Key, Value>::max_size() const noexcept {
  size_t MaxSize = pow(2, sizeof(void*) * 8) / (2 * sizeof(Node)) - 1;
  return MaxSize;
}

//////////////////
/////MODIFIERS/////
//////////////////

template <typename Key, typename Value>
void RedBlackTree<Key, Value>::clear() noexcept {
  destroy(root);
  root = nil;
}

template <typename Key, typename Value>
void RedBlackTree<Key, Value>::swap(RedBlackTree<Key, Value>& other) noexcept {
  std::swap(this->root, other.root);
  std::swap(this->nil, other.nil);
}

template <typename Key, typename Value>
void RedBlackTree<Key, Value>::merge(RedBlackTree<Key, Value>& other) noexcept {
  Node* TmpNode = other.root;
  Node* TmpOtherNil = other.nil;
  InsertSecondTree(TmpNode, TmpOtherNil);
}

template <typename Key, typename Value>
void RedBlackTree<Key, Value>::erase(Iterator position) noexcept {
  Iterator NilIterator(nil);
  if (position == NilIterator) {
    return;
  }
  Node* NodeDelete = FindExistOrNo(*position);
  if (NodeDelete == root) {
    EraseIfNodeIsRoot(NodeDelete);
  } else {
    EraseIfNodeNonRoot(NodeDelete);
  }
  nil->parent = FindLastElementAkaMaximum();
}

template <typename Key, typename Value>
void RedBlackTree<Key, Value>::EraseIfNodeIsRoot(Node* node) noexcept {
  if (node->left == nil && node->right == nil) {
    Node* NewRoot = root;
    root = nil;
    delete NewRoot;
    return;
  }
  if ((node->left == nil && node->right != nil) ||
      (node->left != nil && node->right == nil)) {
    Node* NewRoot = root;
    if (node->left == nil) {
      root = node->right;
    } else {
      root = node->left;
    }
    root->parent = nullptr;
    root->color = BLACK;
    delete NewRoot;
    return;
  }
  EraseIfNeedDeleteAnotherNode(node);
}

template <typename Key, typename Value>
void RedBlackTree<Key, Value>::EraseIfNodeNonRoot(Node* node) noexcept {
  if (node->left == nil && node->right == nil && node->color == RED) {
    Node* DeleteNode = node;
    if (node->parent->right == node) {
      node->parent->right = nil;
    } else {
      node->parent->left = nil;
    }
    delete DeleteNode;
    return;
  }
  if ((node->left == nil && node->right != nil) ||
      (node->left != nil && node->right == nil)) {
    Node* DeleteNode = node;
    if (node->parent->right == node) {
      if (node->left == nil) {
        node->right->color = BLACK;
        node->parent->right = node->right;
        node->right->parent = node->parent;
      } else {
        node->left->color = BLACK;
        node->parent->right = node->left;
        node->left->parent = node->parent;
      }
    } else {
      if (node->left == nil) {
        node->right->color = BLACK;
        node->parent->left = node->right;
        node->right->parent = node->parent;
      } else {
        node->left->color = BLACK;
        node->parent->left = node->left;
        node->left->parent = node->parent;
      }
    }
    delete DeleteNode;
    return;
  }
  EraseIfNeedDeleteAnotherNode(node);
}

template <typename Key, typename Value>
void RedBlackTree<Key, Value>::EraseIfNeedDeleteAnotherNode(
    Node* node) noexcept {
  Node* NodeForDelete = nullptr;
  if (node->left == nil && node->left && node->color == BLACK) {
    EraseAndBalanceAfterDelete(node);
  } else if (node->left != nil && node->right != nil) {
    NodeForDelete = FindMinBeginCurrentNode(node->right);
    node->value = NodeForDelete->value;
    node->key = NodeForDelete->key;
    if (NodeForDelete->color == BLACK && NodeForDelete->right == nil) {
      EraseAndBalanceAfterDelete(NodeForDelete);
    } else {
      EraseEasyCase(NodeForDelete);
    }
  }
}

template <typename Key, typename Value>
void RedBlackTree<Key, Value>::EraseEasyCase(Node* DeletedNode) noexcept {
  if (DeletedNode->parent->right == DeletedNode) {
    DeletedNode->parent->right = nil;
  } else {
    DeletedNode->parent->left = DeletedNode->right;
  }
  if (DeletedNode->right == nil) {
  } else if (DeletedNode->right != nil) {
    DeletedNode->right->parent = DeletedNode->parent;
    DeletedNode->color = BLACK;
  }
  delete DeletedNode;
}

template <typename Key, typename Value>
void RedBlackTree<Key, Value>::EraseAndBalanceAfterDelete(Node* node) noexcept {
  Node* Parent = node->parent;
  Node* Sibling = nullptr;
  Node* CloseNephew = nullptr;
  Node* DistantNephew = nullptr;
  Node* NodeForDelete = node;
  RotateDirection DirectionNode = LEFT;
  if (Parent->right == node) {
    DirectionNode = RIGHT;
    Parent->right = nil;
  } else {
    Parent->left = nil;
  }
  bool DirectionFlag = true;
  do {
    if (DirectionFlag == false) {
      DirectionNode = LEFT;
      if (Parent->right == node) {
        DirectionNode = RIGHT;
      }
    } else {
      DirectionFlag = false;
    }
    Sibling = (DirectionNode == LEFT ? Parent->right : Parent->left);
    DistantNephew = (DirectionNode == LEFT ? Sibling->right : Sibling->left);
    CloseNephew = (DirectionNode == RIGHT ? Sibling->right : Sibling->left);
    // Case When Sibling - RED DistNephew, CloseNephew, Parent - BLACK
    if (Sibling->color == RED) {
      BalanceCaseThree(Sibling, Parent, DistantNephew, CloseNephew,
                       DirectionNode);
      delete NodeForDelete;
      return;
      // Case When DistNephew - red && sibling - black
    }
    if (DistantNephew->color == RED) {
      BalanceCaseSix(Parent, DistantNephew, DirectionNode);
      delete NodeForDelete;
      return;
    }
    // Case when Sibling, DistNephew - black CloseNephew - red
    if (CloseNephew->color == RED) {
      BalanceCaseFive(Sibling, Parent, DistantNephew, CloseNephew,
                      DirectionNode);
      delete NodeForDelete;
      return;
    }
    // Case when Parent - red and others are black
    if (Parent->color == RED) {
      BalanceCaseFour(Sibling, Parent);
      delete NodeForDelete;
      return;
    }
    // Case when all are black
    Sibling->color = RED;
    node = Parent;
  } while ((Parent = node->parent) != nullptr);
  delete NodeForDelete;
}

template <typename Key, typename Value>
void RedBlackTree<Key, Value>::BalanceCaseThree(
    Node* Sibling, Node* Parent, Node* DistantNephew, Node* CloseNephew,
    RotateDirection& Direction) noexcept {
  Parent = Rotate(Parent, Direction);
  Sibling = CloseNephew;
  DistantNephew = (Direction == LEFT ? Sibling->right : Sibling->left);
  if (DistantNephew->color == RED) {
    BalanceCaseSix(Parent, DistantNephew, Direction);
    return;
  }
  CloseNephew = (Direction == LEFT ? Sibling->left : Sibling->right);
  if (CloseNephew->color == RED) {
    BalanceCaseFive(Sibling, Parent, DistantNephew, CloseNephew, Direction);
    return;
  }
  BalanceCaseFour(Sibling, Parent);
}

template <typename Key, typename Value>
void RedBlackTree<Key, Value>::BalanceCaseFour(Node* Sibling,
                                               Node* Parent) noexcept {
  Sibling->color = RED;
  Parent->color = BLACK;
}

template <typename Key, typename Value>
void RedBlackTree<Key, Value>::BalanceCaseFive(
    Node* Sibling, Node* Parent, Node* DistantNephew, Node* CloseNephew,
    RotateDirection& Direction) noexcept {
  RotateDirection NewRotate = (Direction == LEFT ? RIGHT : LEFT);
  Sibling = Rotate(Sibling, NewRotate);
  DistantNephew = Sibling;
  Sibling = CloseNephew;
  BalanceCaseSix(Parent, DistantNephew, Direction);
}

template <typename Key, typename Value>
void RedBlackTree<Key, Value>::BalanceCaseSix(
    Node* Parent, Node* DistantNephew, RotateDirection& Direction) noexcept {
  Parent = Rotate(Parent, Direction);
  Parent->color = BLACK;
  DistantNephew->color = BLACK;
}

template <typename Key, typename Value>
typename RedBlackTree<Key, Value>::const_Iterator
RedBlackTree<Key, Value>::ChangeKey(Iterator& position,
                                    const Key& Newkey) noexcept {
  Node* NodeChange = FindExistOrNo(*position);
  if (NodeChange != nullptr) {
    Value TmpValue = NodeChange->value;
    erase(position);
    insert(Newkey, TmpValue);
    NodeChange = FindExistOrNo(Newkey);
  }
  const_Iterator iterator = find(Newkey);
  return iterator;
}

////////////////
/////LOOKUP/////
////////////////

template <typename Key, typename Value>
bool RedBlackTree<Key, Value>::contains(const Key& key) const noexcept {
  Node* FindNode = FindExistOrNo(key);
  if (FindNode == nullptr) {
    return false;
  }
  return true;
}

template <typename Key, typename Value>
typename RedBlackTree<Key, Value>::const_Iterator
RedBlackTree<Key, Value>::find(const Key& key) noexcept {
  Node* FindNode = FindExistOrNo(key);
  if (FindNode == nullptr) {
    const_Iterator iter(nil);
    return iter;
  }
  const_Iterator iter(FindNode);
  return iter;
}

template <typename Key, typename Value>
typename RedBlackTree<Key, Value>::Iterator
RedBlackTree<Key, Value>::lower_bound(const Key& key) const noexcept {
  return take_bound(key, false);
}

template <typename Key, typename Value>
typename RedBlackTree<Key, Value>::Iterator
RedBlackTree<Key, Value>::upper_bound(const Key& key) const noexcept {
  return take_bound(key, true);
}

template <typename Key, typename Value>
typename RedBlackTree<Key, Value>::Iterator
RedBlackTree<Key, Value>::take_bound(const Key& key,
                                     bool upper) const noexcept {
  Node* FindNode = FindExistOrNo(key);
  if (FindNode != nullptr) {
    Iterator FindIterator(FindNode);
    if (upper) {
      while (*FindIterator == key) {
        ++FindIterator;
        if (FindIterator == nil) {
          break;
        }
      }
    }
    return FindIterator;
  }
  Iterator TakeIterator(FindFirstElementAkaMinimum());
  while (*TakeIterator < key) {
    ++TakeIterator;
    if (TakeIterator == nil) {
      break;
    }
  }
  return TakeIterator;
}

template <typename Key, typename Value>
std::pair<typename RedBlackTree<Key, Value>::Iterator,
          typename RedBlackTree<Key, Value>::Iterator>
RedBlackTree<Key, Value>::equal_range(const Key& key) const noexcept {
  return {lower_bound(key), upper_bound(key)};
}

template <typename Key, typename Value>
size_t RedBlackTree<Key, Value>::count(const Key& key) const noexcept {
  Iterator IteratorBegin(FindFirstElementAkaMinimum());
  size_t CountKey = 0;
  while (*IteratorBegin <= key) {
    if (IteratorBegin == nil) {
      break;
    }
    if (*IteratorBegin == key) {
      CountKey++;
    }
    ++IteratorBegin;
  }
  return CountKey;
}