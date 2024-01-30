#pragma once

#include <stdarg.h>

#include <iostream>

namespace s21 {
template <typename ListElemType>
class queue {
 private:
  class Node {
   public:
    ListElemType elem;
    Node* next;
    Node(ListElemType arg_elem = ListElemType())
        : elem(arg_elem), next(nullptr){};
  };
  Node* first;
  Node* last;
  size_t _size;

 public:
  // Queue Member type
  using value_type = ListElemType;
  using reference = ListElemType&;
  using const_reference = const ListElemType&;
  using size_type = size_t;

  // Queue Member functions
  queue();  // default constructor, creates empty queue
  queue(std::initializer_list<value_type> const&
            items);           // initializer list constructor, creates queue
                              // initizialized using std::initializer_list
  queue(const queue& other);  // copy constructor
  queue(queue&& other);       // move constructor
  ~queue();                   // destructor
  queue& operator=(
      queue&& other);  // assignment operator overload for moving object

  // Queue Element access
  const_reference front() const noexcept {  // access the first element
    return first->elem;
  };
  const_reference back() const noexcept {  // access the last element
    return last->elem;
  };

  // Queue Capacity
  bool empty() const noexcept {  // checks whether the container is empty
    return _size == 0;
  }
  size_type size() const noexcept {  // returns the number of elements
    return _size;
  }

  // Queue Modifiers
  void push(const_reference value);  // inserts element at the end
  void pop();                        // removes the first element
  void swap(queue& other);           // swaps the contents

  template <typename... Args>
  void emplace_back(Args&&... args) noexcept;  // appends new elements to the
                                               // end of the container
};

template <typename ListElemType>
queue<ListElemType>::queue() : _size(0) {
  first = new Node();
  last = first;
}

template <typename ListElemType>
queue<ListElemType>::queue(const queue& other) : queue() {
  Node* iter = other.first;
  while (iter) {
    push(iter->elem);
    iter = iter->next;
  }
}

template <typename ListElemType>
queue<ListElemType>::queue(queue&& other) {
  _size = other._size;
  first = other.first;
  last = other.last;
  other.last = nullptr;
  other.first = nullptr;
  other._size = 0;
}

template <typename ListElemType>
queue<ListElemType>::queue(std::initializer_list<ListElemType> const& items)
    : queue() {
  for (ListElemType const& i : items) {
    push(i);
  }
}

template <typename ListElemType>
queue<ListElemType>& queue<ListElemType>::operator=(
    s21::queue<ListElemType>&& other) {
  while (_size) {
    pop();
  }

  this->first = other.first;
  this->_size = other._size;
  other.first = nullptr;
  other._size = 0;
  last = other.last;
  other.last = nullptr;
  return *this;
}

template <typename ListElemType>
queue<ListElemType>::~queue() {
  if (!_size) delete first;
  while (_size) {
    pop();
  }
}

template <typename ListElemType>
void queue<ListElemType>::push(const_reference value) {
  if (first == nullptr) {
    first = new Node(value);
    last = first;
  } else if (_size == 0) {
    first->elem = value;
  } else {
    last->next = new Node(value);
    last = last->next;
  }
  ++_size;
}

template <typename ListElemType>
void queue<ListElemType>::pop() {
  if (_size) {
    Node* second = first->next;
    delete first;
    first = second;
    --_size;
    if (_size == 0) last = nullptr;
  }
}

template <typename ListElemType>
void queue<ListElemType>::swap(queue& other) {
  std::swap(_size, other._size);
  std::swap(first, other.first);
  std::swap(last, other.last);
}

template <typename ListElemType>
template <typename... Args>
void queue<ListElemType>::emplace_back(Args&&... args) noexcept {
  for (auto& arg : {args...}) {
    push(arg);
  }
}

}  // namespace s21