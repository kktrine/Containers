#pragma once

#include <initializer_list>
#include <iostream>

namespace s21 {
template <typename T>
class vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = std::size_t;

  vector();
  vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &v);
  vector(vector &&v);
  ~vector();

  vector &operator=(vector &&v);
  vector &operator=(const vector &v);

  reference at(size_type pos);
  reference operator[](size_type pos) noexcept;
  const_reference front() const noexcept;
  const_reference back() const noexcept;
  iterator data() noexcept;

  iterator begin() noexcept;
  const_iterator begin() const noexcept;
  iterator end() noexcept;
  const_iterator end() const noexcept;

  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;
  void reserve(size_type size);
  size_type capacity() const noexcept;
  void shrink_to_fit();

  void clear() noexcept;
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back() noexcept;
  void swap(vector &other);

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <typename... Args>
  void insert_many_back(Args &&...args);

 private:
  T *data_{nullptr};
  size_type size_{0};
  size_type capacity_{0};

  void resize_capacity();
};
}  // namespace s21

using namespace s21;

template <typename T>
vector<T>::vector() {}

template <typename T>
vector<T>::vector(size_type n) {
  if (n > 0) {
    size_ = n;
    capacity_ = n;
    data_ = new T[capacity_]{};
  }
}

template <typename T>
vector<T>::vector(std::initializer_list<value_type> const &items) {
  capacity_ = items.size();
  data_ = new T[capacity_];
  for (auto i : items) {
    data_[size_++] = i;
  }
}

template <typename T>
vector<T>::vector(const vector &v) {
  *this = v;
}

template <typename T>
vector<T>::vector(vector &&v) {
  *this = std::move(v);
}

template <typename T>
vector<T>::~vector() {
  if (data_ != nullptr) {
    delete[] data_;
    data_ = nullptr;
  }
  size_ = 0;
  capacity_ = 0;
}

template <typename T>
typename vector<T>::vector &vector<T>::operator=(vector &&v) {
  if (data_ != nullptr) {
    delete[] data_;
    data_ = nullptr;
  }
  swap(v);
  v.size_ = 0;
  v.capacity_ = 0;
  return *this;
}

template <typename T>
typename vector<T>::vector &vector<T>::operator=(const vector &v) {
  if (this == &v) {
    return *this;
  }
  if (data_ != nullptr) {
    delete[] data_;
    data_ = nullptr;
  }
  size_ = 0;
  capacity_ = v.capacity_;
  data_ = new T[capacity_];
  for (; size_ < v.size_; ++size_) {
    data_[size_] = v.data_[size_];
  }
  return *this;
}

template <typename T>
typename vector<T>::reference vector<T>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("Index out of range");
  }
  return data_[pos];
}

template <typename T>
typename vector<T>::reference vector<T>::operator[](size_type pos) noexcept {
  return data_[pos];
}

template <typename T>
typename vector<T>::const_reference vector<T>::front() const noexcept {
  return data_[0];
}

template <typename T>
typename vector<T>::const_reference vector<T>::back() const noexcept {
  return data_[size_ - 1];
}

template <typename T>
typename vector<T>::iterator vector<T>::data() noexcept {
  return data_;
}

template <typename T>
typename vector<T>::iterator vector<T>::begin() noexcept {
  return data_;
}

template <typename T>
typename vector<T>::const_iterator vector<T>::begin() const noexcept {
  return data_;
}

template <typename T>
typename vector<T>::iterator vector<T>::end() noexcept {
  return data_ + size_;
}

template <typename T>
typename vector<T>::const_iterator vector<T>::end() const noexcept {
  return data_ + size_;
}

template <typename T>
bool vector<T>::empty() const noexcept {
  return data_ == nullptr;
}

template <typename T>
typename vector<T>::size_type vector<T>::size() const noexcept {
  return size_;
}

template <typename T>
typename vector<T>::size_type vector<T>::max_size() const noexcept {
  return SIZE_MAX / sizeof(T);
}

template <typename T>
typename vector<T>::size_type vector<T>::capacity() const noexcept {
  return capacity_;
}

template <typename T>
void vector<T>::reserve(size_type size) {
  if (size > max_size()) {
    throw std::length_error(
        "The new size is larger than the maximum available for this "
        "container.");
  }
  if (size > capacity_) {
    capacity_ = size;
    resize_capacity();
  }
}

template <typename T>
void vector<T>::shrink_to_fit() {
  if (capacity_ > size_) {
    capacity_ = size_;
    resize_capacity();
  }
}

template <typename T>
void vector<T>::resize_capacity() {
  T *tmp = nullptr;
  std::swap(tmp, data_);
  data_ = new T[capacity_];
  for (size_type i = 0; i < size_; ++i) {
    data_[i] = tmp[i];
  }
  if (tmp != nullptr) {
    delete[] tmp;
  }
}

template <typename T>
void vector<T>::clear() noexcept {
  size_ = 0;
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(iterator pos,
                                               const_reference value) {
  size_type index = pos - begin();
  if (index > size_) {
    throw std::out_of_range("Index out of range");
  }
  if (size_ == capacity_) {
    capacity_ *= 2;
  }
  T *tmp = new T[capacity_]{};
  for (size_type i = 0; i < index; ++i) {
    tmp[i] = data_[i];
  }
  for (size_type i = index; i < size_; ++i) {
    tmp[i + 1] = data_[i];
  }
  size_++;
  tmp[index] = value;
  delete[] data_;
  data_ = tmp;
  return data_ + index;
}

template <typename T>
void vector<T>::erase(iterator pos) {
  size_type index = pos - begin();
  if (index > size_) {
    throw std::out_of_range("Index out of range");
  }
  T *tmp = new T[capacity_]{};
  for (size_type i = 0; i < index; ++i) {
    tmp[i] = data_[i];
  }
  for (size_type i = index + 1; i < size_; ++i) {
    tmp[i - 1] = data_[i];
  }
  size_--;
  delete[] data_;
  data_ = tmp;
}

template <typename T>
void vector<T>::push_back(const_reference value) {
  insert(end(), value);
}

template <typename T>
void vector<T>::pop_back() noexcept {
  if (size_ > 0) {
    size_--;
  }
}

template <typename T>
void vector<T>::swap(vector &other) {
  std::swap(data_, other.data_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

template <typename T>
template <typename... Args>
typename vector<T>::iterator vector<T>::insert_many(const_iterator pos,
                                                    Args &&...args) {
  size_type index = pos - begin();
  iterator iter = begin() + index;
  for (auto arg : {args...}) {
    iter = insert(iter, arg);
    iter += 1;
  }
  return begin() + index;
}

template <typename T>
template <typename... Args>
void vector<T>::insert_many_back(Args &&...args) {
  for (auto arg : {args...}) {
    push_back(arg);
  }
}
