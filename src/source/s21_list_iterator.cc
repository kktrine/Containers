#include "../headers/s21_list.h"
namespace s21 {

template <typename ListElemType>
typename list<ListElemType>::Iterator&
list<ListElemType>::Iterator::operator--() {
  Iterator previous(CurrentNode);
  while (previous.CurrentNode->next != CurrentNode) {
    ++previous;
  };
  CurrentNode = previous.CurrentNode;
  return *this;
}

template <typename ListElemType>
typename list<ListElemType>::Iterator& list<ListElemType>::Iterator::operator=(
    const Iterator& other) {
  CurrentNode = other.CurrentNode;
  return *this;
}

template <typename ListElemType>
typename list<ListElemType>::Iterator&
list<ListElemType>::Iterator::operator++() {
  CurrentNode = CurrentNode->next;
  return *this;
}

template <typename ListElemType>
typename list<ListElemType>::Iterator list<ListElemType>::Iterator::operator++(
    int) {
  Iterator res = *this;
  ++(*this);

  return res;
}

template <typename ListElemType>
typename list<ListElemType>::reference list<ListElemType>::Iterator::operator*()
    const {
  return CurrentNode->elem;
}

template <typename ListElemType>
typename list<ListElemType>::Iterator list<ListElemType>::begin()
    const noexcept {
  Iterator res(first);
  return res;
}

template <typename ListElemType>
typename list<ListElemType>::Iterator list<ListElemType>::end() const noexcept {
  Iterator res(last);
  return res;
}

// =========================
// =========================
// =========================
// =========================
// =========================
// =========================
template <typename ListElemType>
typename list<ListElemType>::constIterator list<ListElemType>::cbegin()
    const noexcept {
  constIterator res(first);
  return res;
}

template <typename ListElemType>
typename list<ListElemType>::constIterator list<ListElemType>::cend()
    const noexcept {
  constIterator res(last);
  return res;
}

template <typename ListElemType>
typename list<ListElemType>::const_reference
list<ListElemType>::constIterator::operator*() const noexcept {
  return CurrentNode->elem;
}

template <typename ListElemType>
const typename list<ListElemType>::constIterator&
list<ListElemType>::constIterator::operator++() {
  CurrentNode = CurrentNode->next;
  return *this;
}

template <typename ListElemType>
const typename list<ListElemType>::constIterator
list<ListElemType>::constIterator::operator++(int) {
  constIterator res(CurrentNode);
  ++(*this);
  return res;
}

template <typename ListElemType>
const typename list<ListElemType>::constIterator&
list<ListElemType>::constIterator::operator--() {
  Iterator tmp(CurrentNode);
  --tmp;
  CurrentNode = tmp.CurrentNode;
  return *this;
}
}  // namespace s21