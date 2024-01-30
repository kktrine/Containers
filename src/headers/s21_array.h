#pragma once

#include <initializer_list>
#include <iostream>

namespace s21 {
template <typename T, unsigned N>
class array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = std::size_t;

  array() {}

  array(std::initializer_list<value_type> const &items) {
    size_type index = 0;
    for (auto i : items) {
      data_[index++] = i;
    }
  }

  array(const array &a) { *this = a; }

  array(array &&a) { *this = std::move(a); }

  ~array() = default;

  array &operator=(array &&a) noexcept {
    if (this == &a) {
      return *this;
    } else {
      for (size_type i = 0; i < size_; ++i) {
        data_[i] = a.data_[i];
      }
      return *this;
    }
  }

  array &operator=(const array &a) noexcept {
    if (this == &a) {
      return *this;
    } else {
      for (size_type i = 0; i < size_; ++i) {
        data_[i] = std::move(a.data_[i]);
      }
      return *this;
    }
  }

  reference at(size_type pos) {
    if (pos >= size_) {
      throw std::out_of_range("Incorrect size");
    }
    return data_[pos];
  }

  reference operator[](size_type pos) noexcept { return data_[pos]; }

  const_reference front() const noexcept { return data_[0]; }

  const_reference back() const noexcept { return data_[size_ - 1]; }

  iterator data() noexcept { return data_; }

  iterator begin() noexcept { return data_; }

  const_iterator begin() const noexcept { return data_; }

  iterator end() noexcept { return data_ + size_; }

  const_iterator end() const noexcept { return data_ + size_; }

  bool empty() const noexcept { return size_ == 0; }

  size_type size() const noexcept { return size_; }

  size_type max_size() const noexcept { return size_; }

  void swap(array &a) {
    for (size_type i = 0; i < size_; i++) {
      std::swap(data_[i], a.data_[i]);
    }
    std::swap(size_, a.size_);
  }

  void fill(const_reference value) noexcept {
    for (size_type i = 0; i < size_; ++i) {
      data_[i] = value;
    }
  }

 private:
  value_type data_[N]{};
  size_type size_{N};
};
}  // namespace s21
