#pragma once

#include "BasedClassForMapAndSet.h"

namespace s21 {
template <typename Key, typename Value>
class map : public BaseForSetMap<Key, Value> {
 public:
  using mapped_type = Value;
  using value_type = std::pair<const Key, Value>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using BaseForSetMap<Key, Value>::RedBlacktree;
  using key_type = Key;
  using iterator = typename RedBlackTree<Key, Value>::Iterator;
  using const_iterator = typename RedBlackTree<Key, Value>::const_Iterator;
  map() : BaseForSetMap<Key, Value>(){};
  map(const map& other) : BaseForSetMap<Key, Value>(other) {}
  map(map&& other) : BaseForSetMap<Key, Value>(std::move(other)){};
  map(std::initializer_list<std::pair<const Key, Value>> const& items)
      : BaseForSetMap<Key, Value>(items){};
  ~map(){};
  map& operator=(map&& OtherTree) noexcept {
    if (this != &OtherTree) {
      this->RedBlacktree = std::move(OtherTree.RedBlacktree);
    }
    return *this;
  }
  map& operator=(map& OtherTree) noexcept {
    if (this != &OtherTree) {
      this->RedBlacktree = OtherTree.RedBlacktree;
    }
    return *this;
  }

  Value& at(const Key& key) { return RedBlacktree.at(key); }
  Value& operator[](const Key& key) noexcept { return RedBlacktree[key]; }

  std::pair<iterator, bool> insert(
      const std::pair<const Key, Value>& value) noexcept {
    return RedBlacktree.insert(value);
  }

  std::pair<iterator, bool> insert(const Key& key, const Value& obj) noexcept {
    return RedBlacktree.insert(key, obj);
  }

  std::pair<iterator, bool> insert_or_assign(const Key& key,
                                             const Value& obj) noexcept {
    return RedBlacktree.insert_or_assign(key, obj);
  }

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&... args) noexcept {
    std::vector<std::pair<iterator, bool>> PairKit;
    for (auto& i : {args...}) PairKit.push_back(insert(i));
    return PairKit;
  }
};
}  // namespace s21
