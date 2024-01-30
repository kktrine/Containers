#pragma once

#include "../source/s21_list.cc"
#include "../source/s21_list_iterator.cc"
#include "s21_list.h"

namespace s21 {
template <typename T, typename Container = list<T>>
class stack {
 public:
  using value_type = typename Container::value_type;
  using reference = typename Container::reference;
  using const_reference = typename Container::const_reference;
  using size_type = typename Container::size_type;

  stack() : container_() {}

  stack(std::initializer_list<value_type> const &items) : container_(items) {}

  stack(stack const &other) : container_(other.container_) {}

  stack(stack &&other) : container_(std::move(other.container_)) {}

  ~stack() = default;

  stack<T> &operator=(stack &&other) {
    container_ = std::move(other.container_);
    return *this;
  }

  stack<T> &operator=(stack const &other) {
    container_ = other.container_;
    return *this;
  }

  const_reference top() { return container_.back(); }

  bool empty() const noexcept { return container_.empty(); }

  size_type size() const noexcept { return container_.size(); }

  void push(const_reference value) { container_.push_back(value); }

  void pop() { container_.pop_back(); }

  void swap(stack &other) { container_.swap(other.container_); }

  template <typename... Args>
  void insert_many_front(Args &&...args) {
    container_.insert_many_back(std::forward<Args>(args)...);
  }

 private:
  Container container_;
};
}  // namespace s21
