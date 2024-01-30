#pragma once

#include "BasedClassForMapAndSet.h"

namespace s21 {
template <typename Key>
class multiset : public BaseForSetMap<Key, Key> {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type&;
  using const_reference = const value_type&;
  using BaseForSetMap<Key, Key>::RedBlacktree;
  using iterator = typename RedBlackTree<Key, Key>::Iterator;
  using const_iterator = typename RedBlackTree<Key, Key>::const_Iterator;
  using size_type = size_t;
  multiset() : BaseForSetMap<Key, Key>(){};
  multiset(const multiset& ms) : BaseForSetMap<Key, Key>(ms) {}
  multiset(multiset&& ms) : BaseForSetMap<Key, Key>(std::move(ms)){};
  multiset(std::initializer_list<Key> const& items)
      : BaseForSetMap<Key, Key>(items, true){};
  ~multiset(){};
  multiset& operator=(multiset&& OtherTree) noexcept {
    if (this != &OtherTree) {
      this->RedBlacktree = std::move(OtherTree.RedBlacktree);
    }
    return *this;
  }
  multiset& operator=(multiset& OtherTree) noexcept {
    if (this != &OtherTree) {
      this->RedBlacktree = OtherTree.RedBlacktree;
    }
    return *this;
  }

  iterator insert(const value_type& value) noexcept {
    return RedBlacktree.insert_multiset(value);
  }

  size_type count(const Key& key) const noexcept {
    return RedBlacktree.count(key);
  }
  const_iterator find(const Key& key) noexcept {
    return RedBlacktree.find(key);
  }
  std::pair<iterator, iterator> equal_range(const Key& key) const noexcept {
    return RedBlacktree.equal_range(key);
  }
  iterator lower_bound(const Key& key) const noexcept {
    return RedBlacktree.lower_bound(key);
  }
  iterator upper_bound(const Key& key) const noexcept {
    return RedBlacktree.upper_bound(key);
  }
  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&... args) noexcept {
    std::vector<std::pair<iterator, bool>> PairKit;
    for (auto& i : {args...}) PairKit.push_back({this->insert(i), true});
    return PairKit;
  }
};
}  // namespace s21