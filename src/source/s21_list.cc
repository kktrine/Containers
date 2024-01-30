#include "../headers/s21_list.h"
namespace s21 {
template <typename ListElemType>
list<ListElemType>::Node::Node(ListElemType arg_elem, Node* arg_next) {
  elem = arg_elem;
  next = arg_next;
}

template <typename ListElemType>
void list<ListElemType>::Node::swap(Node* other) {
  std::swap(elem, other->elem);
}

template <typename ListElemType>
list<ListElemType>::list() : list_size(0) {
  first = new Node();
  last = first;
  first->next = first;
}

template <typename ListElemType>
list<ListElemType>::list(size_t n) : list() {
  for (size_t i = 0; i < n; ++i) {
    push_back(ListElemType());
  }
}

template <typename ListElemType>
list<ListElemType>::list(const list& other) : list() {
  for (Iterator ptr = other.begin(); ptr != other.end(); ++ptr) {
    push_back(*ptr);
  }
}

template <typename ListElemType>
list<ListElemType>::list(std::initializer_list<ListElemType> const& items)
    : list() {
  for (ListElemType const& i : items) {
    push_back(i);
  }
}

template <typename ListElemType>
list<ListElemType>::list(list&& other)
    : list_size(other.list_size), first(other.first), last(other.last) {
  other.list_size = 0;
  other.first = nullptr;
  other.last = nullptr;
}

template <typename ListElemType>
list<ListElemType>::~list() {
  clear();
}

template <typename ListElemType>
void list<ListElemType>::push_back(const ListElemType new_value) noexcept {
  Iterator iter(last);
  insert(iter, new_value);
}

template <typename ListElemType>
void list<ListElemType>::push_front(const ListElemType new_value) noexcept {
  Iterator pos(first);
  insert(pos, new_value);
}

template <typename ListElemType>
void list<ListElemType>::pop_front() noexcept {
  erase(begin());
}

template <typename ListElemType>
void list<ListElemType>::pop_back() noexcept {
  Node* tmp = first;
  while (tmp->next->next != last) {
    tmp = tmp->next;
  }
  delete tmp->next;
  tmp->next = last;
  --list_size;
}

template <typename ListElemType>
void list<ListElemType>::swap(list& other) noexcept {
  std::swap(first, other.first);
  std::swap(last, other.last);
  std::swap(list_size, other.list_size);
}

template <typename ListElemType>
void list<ListElemType>::clear() noexcept {
  while (list_size) pop_front();
  if (last) {
    delete last;
    last = nullptr;
  }
}

template <typename ListElemType>
bool list<ListElemType>::empty() const noexcept {
  return list_size == 0;
}

template <typename ListElemType>
size_t list<ListElemType>::size() const noexcept {
  return list_size;
}

template <typename ListElemType>
const ListElemType& list<ListElemType>::front() const noexcept {
  return first->elem;
}

template <typename ListElemType>
const ListElemType& list<ListElemType>::back() const noexcept {
  Node* current = first;
  while (current->next != last) current = current->next;
  return current->elem;
}

template <typename ListElemType>
list<ListElemType>& list<ListElemType>::operator=(const list& other) {
  this->clear();
  Node* tmp = other.first;
  while (tmp->next) {
    this->push_back(tmp->elem);
    tmp = tmp->next;
  }
  return *this;
}

template <typename ListElemType>
list<ListElemType>& list<ListElemType>::operator=(const list&& other) {
  clear();
  this->first = other.first;
  this->list_size = other.list_size;
  other->first = nullptr;
  other.list_size = 0;
  last = other.last;
  other.last == nullptr;
  return *this;
}

template <typename ListElemType>
void list<ListElemType>::sort() noexcept {
  for (int i = (int)list_size - 1; i > 0; --i) {
    Node* current_node = first;
    Node* next_node = current_node->next;
    for (int j = 0; j < i; ++j) {
      if (current_node->greather(next_node)) current_node->swap(next_node);
      current_node = current_node->next;
      next_node = next_node->next;
    }
  }
}

template <typename ListElemType>
size_t list<ListElemType>::max_size() const noexcept {
  return pow(2, sizeof(void*) * 8) / (2 * sizeof(Node) - 1);
}

template <typename ListElemType>
void list<ListElemType>::merge(list<ListElemType>& other) noexcept {
  if (list_size + other.list_size == 0) return;
  Iterator ThisPtr(first);
  Iterator OtherPtr(other.first);
  while (ThisPtr != end() && OtherPtr != other.end()) {
    if (ThisPtr.CurrentNode->greather(OtherPtr.CurrentNode)) {
      insert(ThisPtr, *OtherPtr);
      ++OtherPtr;
    } else {
      ++ThisPtr;
    }
  }
  while (OtherPtr != other.end()) {
    push_back(*OtherPtr);
    ++OtherPtr;
  }
  other.clear();
}

template <typename ListElemType>
void list<ListElemType>::reverse() noexcept {
  Node* right = first;
  Node* left = first;

  for (size_t i = 0; i < list_size / 2; ++i) {
    for (size_t j = 0; j < list_size - i - 1; ++j) {
      right = right->next;
    }
    left->swap(right);
    left = left->next;
    right = first;
  }
}

template <typename ListElemType>
typename list<ListElemType>::Iterator list<ListElemType>::insert(
    list<ListElemType>::Iterator pos,
    list<ListElemType>::const_reference value) noexcept {
  Iterator res;
  Iterator previous = first;
  while (previous.CurrentNode->next != pos.CurrentNode) {
    ++previous;
  }
  Iterator tmp = previous;
  previous.CurrentNode->next = new Node(value, tmp.CurrentNode->next);
  if (pos.CurrentNode == first) {
    first = last->next;
  }
  res = ++previous;
  ++list_size;
  return res;
}

template <typename ListElemType>
void list<ListElemType>::erase(list<ListElemType>::Iterator pos) {
  if (pos == end()) {
    clear();
    throw std::invalid_argument("Invalid pointer");
  }
  Iterator previous(first);
  while (previous.CurrentNode->next != pos.CurrentNode) {
    ++previous;
  }
  previous.CurrentNode->next = pos.CurrentNode->next;
  if (pos == first) first = first->next;
  delete pos.CurrentNode;
  --list_size;
}

template <typename ListElemType>
void list<ListElemType>::unique() noexcept {
  Iterator tmp = first, tmp2 = first->next;
  while (tmp2 != end()) {
    if (*tmp == *tmp2) {
      erase(tmp++);
      ++tmp2;
    } else {
      ++tmp;
      ++tmp2;
    }
  }
}

template <typename ListElemType>
void list<ListElemType>::splice(list<ListElemType>::constIterator pos,
                                list<ListElemType>& other) noexcept {
  if (other.list_size == 0) return;
  constIterator next = pos;
  --pos;
  constIterator prev = pos;
  constIterator LastElemOfOther = --(other.cend());
  if (prev.CurrentNode == last) first = other.first;
  prev.CurrentNode->next = other.first;
  LastElemOfOther.CurrentNode->next = next.CurrentNode;
  list_size += other.list_size;
  other.list_size = 0;
  other.first = nullptr;
  other.clear();
}

template <typename ListElemType>
template <typename... Args>
void list<ListElemType>::insert_many_back(Args&&... args) noexcept {
  for (auto& arg : {args...}) {
    push_back(arg);
  }
}

template <typename ListElemType>
template <typename... Args>
void list<ListElemType>::insert_many_front(Args&&... args) noexcept {
  constIterator pos(cbegin());
  insert_many(pos, args...);
}

template <typename ListElemType>
template <typename... Args>
typename list<ListElemType>::Iterator list<ListElemType>::insert_many(
    list<ListElemType>::constIterator pos, Args&&... args) noexcept {
  Iterator iter(pos.CurrentNode);
  Iterator res(pos.CurrentNode);
  --res;
  for (auto& arg : {args...}) {
    iter = insert(iter, arg);
    ++iter;
  }

  return ++res;
}
}  // namespace s21