#pragma once

#include <cmath>
#include <iostream>

namespace s21 {
template <typename ListElemType>
class list {
 private:
  size_t list_size = 0;
  class Node {
   public:
    ListElemType elem;
    Node* next;
    Node(ListElemType arg_elem = ListElemType(), Node* arg_next = nullptr);
    void swap(Node* other);
    bool greather(const Node* other) {
      bool res;
      if constexpr (std::is_same_v<ListElemType, char*>)
        res = (strcmp(elem, other->elem) > 0);
      else
        res = elem > other->elem;
      return res;
    };
  };
  Node* first = nullptr;
  Node* last = nullptr;

 public:
  // List Member type
  using value_type = ListElemType;
  using reference = ListElemType&;
  using const_reference = const ListElemType&;
  using size_type = size_t;

  // Iterator
  class Iterator {
   public:
    Node* CurrentNode;
    using iterator = Iterator;
    Iterator() : CurrentNode(nullptr){};
    Iterator(const Iterator& other) : CurrentNode(other.CurrentNode){};
    Iterator(Node* node) : CurrentNode(node){};
    iterator& operator++();
    iterator operator++(int);
    iterator& operator--();
    reference operator*() const;
    bool operator==(const iterator& other) const noexcept {
      return CurrentNode == other.CurrentNode;
    }
    bool operator!=(const iterator& other) const noexcept {
      return !(*this == other);
    }
    iterator& operator=(const iterator& other);
  };

  class constIterator {
   public:
    Node* CurrentNode;
    using const_iterator = constIterator;
    constIterator() : CurrentNode(nullptr){};
    constIterator(Node* node) : CurrentNode(node){};
    const const_iterator& operator++();
    const const_iterator operator++(int);
    const const_iterator& operator--();
    const_reference operator*() const noexcept;
    bool operator==(const_iterator& other) const noexcept {
      return CurrentNode == other.CurrentNode;
    }
    bool operator!=(const_iterator& other) const noexcept {
      return !(*this == other);
    }
  };
  // List Member type
  using iterator = Iterator;
  using const_iterator = constIterator;
  // Functions
  list& operator=(const list& other);   // ok
  list& operator=(const list&& other);  // ok

  // Constructors
  list();                   // default constructor, creates empty list 
  list(const list& other);  // move constructor
  list(list&& other);       // copy constructor
  list(size_type n);  // parameterized constructor, creates the list of size n
  list(std::initializer_list<value_type> const&
           items);  // initializer list constructor, creates list
                    // initizialized using std::initializer_list

  // List Modifiers
  void push_back(
      const value_type new_value) noexcept;  // adds an element to the end
  void push_front(
      const value_type new_value) noexcept;  // adds an element to the head
  void pop_front() noexcept;                 // removes the first element
  void pop_back() noexcept;                  // removes the last element
  void clear() noexcept;                     // clears the contents
  void swap(list& other) noexcept;           // swaps the contents
  void sort() noexcept;                      // sorts the elements
  void merge(list& other) noexcept;          // merges two sorted lists
  void reverse() noexcept;  // reverses the order of the elements
  iterator insert(
      iterator pos,
      const_reference
          value) noexcept;   // inserts element into concrete pos and returns
                             // the iterator that points to the new element
  void erase(iterator pos);  // erases element at pos
  void unique() noexcept;    // removes consecutive duplicate elements
  void splice(const_iterator pos,
              list& other) noexcept;  // transfers elements from list other
                                      // starting from pos

  template <typename... Args>
  void insert_many_back(Args&&... args) noexcept;  // appends new elements to
                                                   // the end of the container

  template <typename... Args>
  void insert_many_front(Args&&... args) noexcept;  // appends new elements to
                                                    // the top of the container

  template <typename... Args>
  iterator insert_many(
      const_iterator pos,
      Args&&... args) noexcept;  // inserts new elements into the
                                 // container directly before pos

  // List Element access
  const_reference front() const noexcept;  // access the first element
  const_reference back() const noexcept;   // access the last element

  // List Capacity
  bool empty() const noexcept;      // checks whether the container is empty
  size_type size() const noexcept;  // returns the number of elements
  size_type max_size()
      const noexcept;  // returns the maximum possible number of elements

  // Destructor
  ~list();

  // Iterator
  iterator begin() const noexcept;  // returns an iterator to the beginning
  iterator end() const noexcept;    // returns an iterator to the beginning
  const_iterator cbegin()
      const noexcept;  // returns an const iterator to the beginning
  const_iterator cend()
      const noexcept;  // returns an const iterator to the beginning
};
}  // namespace s21
