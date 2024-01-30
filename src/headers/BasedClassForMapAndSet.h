#pragma once

#include <vector>

#include "RedBlackTree.h"

namespace s21 {
template <class Key, class Value>
class BaseForSetMap {
 public:
  BaseForSetMap() : RedBlacktree(){};
  BaseForSetMap(const BaseForSetMap& other)
      : RedBlacktree(other.RedBlacktree) {}
  BaseForSetMap(BaseForSetMap&& other)
      : RedBlacktree(std::move(other.RedBlacktree)){};
  BaseForSetMap(std::initializer_list<std::pair<const Key, Value>> const& items)
      : RedBlacktree(items){};
  BaseForSetMap(std::initializer_list<Key> const& items, bool isMultiset)
      : RedBlacktree(items, isMultiset){};
  ~BaseForSetMap(){};
  BaseForSetMap& operator=(BaseForSetMap&& OtherTree) noexcept {
    if (this != &OtherTree) {
      this->RedBlacktree = std::move(OtherTree.RedBlacktree);
    }
    return *this;
  }
  BaseForSetMap& operator=(BaseForSetMap& OtherTree) noexcept {
    if (this != &OtherTree) {
      this->RedBlacktree = OtherTree.RedBlacktree;
    }
  }
  // general Member type
  using size_type = size_t;
  using iterator = typename RedBlackTree<Key, Value>::Iterator;
  using const_iterator = typename RedBlackTree<Key, Value>::const_Iterator;
  using key_type = Key;

  // iterators
  iterator begin() noexcept { return RedBlacktree.begin(); }
  iterator end() noexcept { return RedBlacktree.end(); }
  const_iterator cbegin() noexcept { return RedBlacktree.cbegin(); }
  const_iterator cend() noexcept { return RedBlacktree.cend(); }

  // Capacity
  bool empty() const noexcept { return RedBlacktree.empty(); }
  size_type size() const noexcept { return RedBlacktree.size(); }
  size_type max_size() const noexcept { return RedBlacktree.max_size(); }

  // Modifiers
  void clear() noexcept { RedBlacktree.clear(); }
  void erase(iterator pos) noexcept { RedBlacktree.erase(pos); }
  void swap(BaseForSetMap& other) noexcept {
    RedBlacktree.swap(other.RedBlacktree);
  }
  void merge(BaseForSetMap& other) noexcept {
    RedBlacktree.merge(other.RedBlacktree);
  }

  bool contains(const Key& key) const noexcept {
    return RedBlacktree.contains(key);
  }
  const_iterator ChangeKey(iterator& position, const Key& Newkey) noexcept {
    return RedBlacktree.ChangeKey(position, Newkey);
  }

 protected:
  RedBlackTree<Key, Value> RedBlacktree;
};
}  // namespace s21