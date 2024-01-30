#pragma once

#include "BasedClassForMapAndSet.h"

namespace s21 {
template <typename Key>
class set : public BaseForSetMap<Key, Key> {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type&;
  using const_reference = const value_type&;
  using BaseForSetMap<Key, Key>::RedBlacktree;
  using iterator = typename RedBlackTree<Key, Key>::Iterator;
  using const_iterator = typename RedBlackTree<Key, Key>::const_Iterator;
  set() : BaseForSetMap<Key, Key>(){};
  set(const set& other) : BaseForSetMap<Key, Key>(other) {}
  set(set&& other) : BaseForSetMap<Key, Key>(std::move(other)){};
  set(std::initializer_list<Key> const& items)
      : BaseForSetMap<Key, Key>(items, false){};
  ~set(){};
  set& operator=(set&& OtherTree) noexcept {
    if (this != &OtherTree) {
      this->RedBlacktree = std::move(OtherTree.RedBlacktree);
    }
    return *this;
  }
  set& operator=(set& OtherTree) noexcept {
    if (this != &OtherTree) {
      this->RedBlacktree = OtherTree.RedBlacktree;
    }
    return *this;
  }

  std::pair<iterator, bool> insert(const value_type& value) {
    return RedBlacktree.insert(value);
  }
  // можно менять только через метод ChangeKey
  const_iterator find(const Key& key) noexcept {
    return RedBlacktree.find(key);
  }
  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&... args) noexcept {
    std::vector<std::pair<iterator, bool>> PairKit;
    for (auto& i : {args...}) PairKit.push_back(insert(i));
    return PairKit;
  }
};
}  // namespace s21
