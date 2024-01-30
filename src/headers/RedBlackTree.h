#pragma once

#include <cmath>
#include <iostream>

namespace s21 {
template <typename Key, typename Value>
class RedBlackTree {
 private:
  enum NodeColor { RED, BLACK };
  struct Node {
    Key key;
    Value value;
    NodeColor color;
    Node* left;
    Node* right;
    Node* parent;

    Node(Key key, Value value) : key(key), value(value) {
      left = nullptr;
      right = nullptr;
      parent = nullptr;
      color = RED;
    }
  };
  Node* root;
  Node* nil;
  enum RotateDirection { RIGHT, LEFT };

  // rotation of the subtree in the given direction, the node relative to which
  // the rotation takes place is supplied
  Node* Rotate(Node* node, RotateDirection direction) noexcept;
  // Search node, return node or nullptr if not found
  Node* FindExistOrNo(const Key& key) const noexcept;
  // Finding the parent of a node if there is no node in the tree with the
  // current key
  Node* FindParentIfNoExist(Key& key) const noexcept;
  Node* FindFirstElementAkaMinimum() const noexcept;
  Node* FindLastElementAkaMaximum() const noexcept;
  // search for the minimum node in the right subtree of the current node
  Node* FindMinBeginCurrentNode(Node* node) const noexcept;

  Node* GetUncle(Node* node) const noexcept;
  Node* GetGrandparent(Node* node) const noexcept;

  // helper methods for erase node
  void EraseIfNodeIsRoot(Node* node) noexcept;
  void EraseIfNodeNonRoot(Node* node) noexcept;
  void EraseIfNeedDeleteAnotherNode(Node* node) noexcept;
  void EraseAndBalanceAfterDelete(Node* node) noexcept;
  void EraseEasyCase(Node* DeletedNode) noexcept;
  void BalanceCaseThree(Node* Sibling, Node* Parent, Node* DistantNephew,
                        Node* CloseNephew, RotateDirection& Direction) noexcept;
  void BalanceCaseFour(Node* Sibling, Node* Parent) noexcept;
  void BalanceCaseFive(Node* Sibling, Node* Parent, Node* DistantNephew,
                       Node* CloseNephew, RotateDirection& Direction) noexcept;
  void BalanceCaseSix(Node* Parent, Node* DistantNephew,
                      RotateDirection& Direction) noexcept;

  // helper methods to insert
  void BalanceTreeAfterInsert(Node* ParentForNewNode, Node* NewNode) noexcept;
  void InsertCaseGrandParentNoExist() noexcept;
  void InsertCaseUncleBlack(Node* NewNode,
                            RotateDirection DirectionUncle) noexcept;
  // deleting all nodes except the dummy one(NIL)
  void destroy(Node* root) noexcept;
  // recursive node count
  void RecursivSize(Node* node, size_t& size) const noexcept;
  // inserting another tree into the current tree
  void InsertSecondTree(Node* node, Node* OtherNil) noexcept;

 public:
  class Iterator {
   private:
    Node* CurrentNode;
    std::pair<Key, Value>* AddressPair;
    std::pair<Key, Value> pair;

    Node* FindMaximum() noexcept;
    Node* FindMinimum() noexcept;

   public:
    Iterator() : pair(Key(), Value()) {
      this->CurrentNode = nil;
      AddressPair = &pair;
    }
    Iterator(Node* node) : CurrentNode(node), pair(Key(), Value()) {
      AddressPair = &pair;
    };
    bool operator==(const Iterator& other) const noexcept {
      return CurrentNode == other.CurrentNode;
    }

    bool operator!=(const Iterator& other) const noexcept {
      return !(CurrentNode == other.CurrentNode);
    }

    const Key& operator*() const noexcept { return CurrentNode->key; }

    std::pair<Key, Value>* operator->() noexcept;

    Iterator& operator--() noexcept;
    Iterator& operator++() noexcept;
    Iterator operator++(int) noexcept;
  };

  class const_Iterator {
   private:
    Node* CurrentNode;
    std::pair<Key, Value>* AddressPair;
    std::pair<Key, Value> pair;

    Node* FindMaximum() noexcept;
    Node* FindMinimum() noexcept;

   public:
    const_Iterator() : pair(Key(), Value()) {
      this->CurrentNode = nil;
      AddressPair = &pair;
    }
    const_Iterator(Node* node) : CurrentNode(node), pair(Key(), Value()) {
      AddressPair = &pair;
    };
    bool operator==(const const_Iterator& other) const noexcept {
      return CurrentNode == other.CurrentNode;
    }

    bool operator!=(const const_Iterator& other) const noexcept {
      return !(CurrentNode == other.CurrentNode);
    }

    const Key& operator*() const noexcept { return CurrentNode->key; }

    const std::pair<Key, Value>* operator->() noexcept;

    const const_Iterator& operator--() noexcept;
    const const_Iterator& operator++() noexcept;
    const const_Iterator operator++(int) noexcept;
  };

  RedBlackTree();
  ~RedBlackTree();
  RedBlackTree(const RedBlackTree& OtherTree);
  RedBlackTree(RedBlackTree&& OtherTree);
  // initializer_list_constructor for map
  RedBlackTree(std::initializer_list<std::pair<const Key, Value>> const& items);
  // initializer_list_constructor for set and multiset
  // if isMultiset - 0 then set, else multiset
  RedBlackTree(std::initializer_list<Key> const& items, bool isMultiset);
  RedBlackTree& operator=(RedBlackTree&& OtherTree) noexcept;
  RedBlackTree& operator=(const RedBlackTree& OtherTree) noexcept;
  std::pair<Iterator, bool> TreeInsert(Key key, Value value = Value());
  Iterator begin() noexcept;
  Iterator end() noexcept;
  const_Iterator cbegin() noexcept;
  const_Iterator cend() noexcept;
  const_Iterator find(const Key& key) noexcept;
  bool contains(const Key& key) const noexcept;
  void clear() noexcept;
  bool empty() const noexcept;
  size_t size() const noexcept;
  constexpr size_t max_size() const noexcept;
  Value& at(const Key& key);
  void swap(RedBlackTree& other) noexcept;
  std::pair<Iterator, bool> insert(
      const std::pair<Key, Value>& PairValue) noexcept;
  std::pair<Iterator, bool> insert(const Key& key,
                                   const Value& value = Value()) noexcept;
  std::pair<Iterator, bool> insert_or_assign(
      const Key& key, const Value& value = Value()) noexcept;

  void erase(Iterator position) noexcept;
  void merge(RedBlackTree& other) noexcept;
  const_Iterator ChangeKey(Iterator& position, const Key& Newkey) noexcept;
  // Redefining square brackets
  Value& operator[](const Key& key) noexcept;

  size_t count(const Key& key) const noexcept;
  std::pair<Iterator, Iterator> equal_range(const Key& key) const noexcept;
  Iterator lower_bound(const Key& key) const noexcept;
  Iterator upper_bound(const Key& key) const noexcept;
  // helper bound method
  Iterator take_bound(const Key& key, bool upper) const noexcept;
  Iterator insert_multiset(const Key& key) noexcept;
};
}  // namespace s21