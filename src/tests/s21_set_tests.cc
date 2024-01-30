#include <set>

#include "../headers/s21_set.h"
#include "../source/RedBlackTreeOperations.cc"
#include "gtest/gtest.h"

using s21::set;

TEST(set_test, default_constructor) {
  set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::set<int> s2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  set<int>::iterator it1 = s1.begin();
  for (auto it2 = s2.begin(); it2 != s2.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
}

TEST(set_test, construcotr_list) {
  set<int> s1 = {2, 1, 3, 5, 4, 6, 8, 7};
  std::set<int> s2 = {2, 1, 3, 5, 4, 6, 8, 7};
  auto it1 = s1.begin();
  for (auto it2 = s2.begin(); it2 != s2.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
}

TEST(set_test, constructor_size) {
  set<int> s1;
  std::set<int> s2;
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, constr_move) {
  set<int> s1 = {1, 2, 3};
  std::set<int> s2 = {1, 2, 3};
  auto s11 = std::move(s1);
  auto s22 = std::move(s2);
  auto it1 = s11.begin();
  for (auto it2 = s22.begin(); it2 != s22.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
}

TEST(set_test, constructor_list2) {
  set<int> s1 = {1, 2, 3};
  std::set<int> s2 = {1, 2, 3};
  auto s11 = s1;
  auto s22 = s2;
  auto it1 = s11.begin();
  for (auto it2 = s22.begin(); it2 != s22.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
}

TEST(set_test, constr_size_2) {
  set<int> s1 = {-100, -200, -15};
  std::set<int> s2 = {-100, -200, -15};
  auto it1 = s1.begin();
  for (auto it2 = s2.begin(); it2 != s2.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, construcotr_size_move) {
  set<int> s1 = {1, 2, 3};
  std::set<int> s2 = {1, 2, 3};
  set<int> s11;
  std::set<int> s22;
  s11 = std::move(s1);
  s22 = std::move(s2);
  auto it1 = s11.begin();
  for (auto it2 = s22.begin(); it2 != s22.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
}

TEST(set_test, begin1) {
  set<int> s1 = {1, 2, 3};
  std::set<int> s2 = {1, 2, 3};
  auto it1 = s1.begin();
  auto it2 = s2.begin();
  EXPECT_EQ(*it1, *it2);
}

TEST(set_test, cbegin) {
  set<int> s1 = {1, 2, 3};
  std::set<int> s2 = {1, 2, 3};
  auto it1 = s1.cbegin();
  auto it2 = s2.cbegin();
  EXPECT_EQ(*it1, *it2);
}

TEST(set_test, empty) {
  set<int> s1 = {1, 2, 3};
  std::set<int> s2 = {1, 2, 3};
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, empty_clear) {
  set<int> s1 = {1, 2, 3};
  std::set<int> s2 = {1, 2, 3};
  s1.clear();
  s2.clear();
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, size_insert) {
  set<int> s1;
  std::set<int> s2;
  s1.insert(1);
  s2.insert(1);
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, size) {
  set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<int> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, size_clear) {
  set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<int> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  s1.clear();
  s2.clear();
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, clear_size_empty) {
  set<double> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<double> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  s1.clear();
  s2.clear();
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, clear_size_empty_2) {
  set<double> s1;
  std::set<double> s2;
  s1.clear();
  s2.clear();
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, clear_size_empty_3) {
  set<double> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<double> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  s1.clear();
  s2.clear();
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.empty(), s2.empty());
  s1.clear();
  s2.clear();
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.empty(), s2.empty());
}

TEST(set_test, clear_size_empty_4) {
  set<double> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<double> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  EXPECT_EQ(s1.size(), s2.size());
  auto it1 = s1.begin();
  for (auto it2 = s2.begin(); it2 != s2.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, insert_size) {
  set<double> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<double> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.insert(-1).second, s2.insert(-1).second);
  auto it1 = s1.begin();
  for (auto it2 = s2.begin(); it2 != s2.end(); ++it1, ++it2) {
    EXPECT_EQ(*it1, *it2);
  }
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, clear_size_empty_5) {
  set<double> s1 = {3, 2, 1, 4, 6, 5, 7, 8};
  std::set<double> s2 = {3, 2, 1, 4, 6, 5, 7, 8};
  EXPECT_EQ(s1.size(), s2.size());
  auto it1 = s1.begin();
  for (auto it2 = s2.begin(); it2 != s2.end(); ++it1, ++it2) {
    EXPECT_EQ(*it1, *it2);
  }
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, erase_size) {
  set<double> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<double> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  EXPECT_EQ(s1.size(), s2.size());
  s1.erase(s1.begin());
  s2.erase(s2.begin());
  EXPECT_EQ(s1.size(), s2.size());
}

TEST(set_test, erase_size_2) {
  set<double> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<double> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  s1.erase(s1.begin());
  s2.erase(s2.begin());
  auto it1 = s1.begin();
  auto it2 = s2.begin();
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(*it1, *it2);
}

TEST(set_test, swap_size) {
  set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<int> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  set<int> s11;
  std::set<int> s22;
  s1.swap(s11);
  s2.swap(s22);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
  auto it1 = s11.begin();
  for (auto it2 = s22.begin(); it2 != s22.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
}

TEST(set_test, swap_size_2) {
  set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<int> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  set<int> s11 = {389, 3829, 111, 189, 11};
  std::set<int> s22 = {389, 3829, 111, 189, 11};
  s1.swap(s11);
  s2.swap(s22);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s11.size(), s22.size());
  auto it1 = s11.begin();
  for (auto it2 = s22.begin(); it2 != s22.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
}

TEST(set_test, merge_begin_end) {
  set<int> m1 = {1, 2, 3, 4, 5};
  set<int> m11 = {6, 7, 8};
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8};
  m1.merge(m11);
  auto i = 0;
  for (auto it1 = m1.begin(); it1 != m1.end(); ++it1, ++i)
    EXPECT_EQ((*it1), vec[i]);
}

TEST(set_test, find) {
  set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<int> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  EXPECT_EQ(*(s1.find(3)), *(s2.find(3)));
}

TEST(set_test, contains) {
  set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  EXPECT_EQ(s1.contains(1), true);
}

TEST(set_test, contains_2) {
  set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  EXPECT_EQ(s1.contains(0), false);
}

TEST(set_test, iterator_begin) {
  set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<int> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  auto it1 = s1.begin();
  auto it2 = s2.begin();
  for (int i = 0; i < 4; i++) ++it1, ++it2;
  EXPECT_EQ(*it1, *it2);
}

TEST(set_test, iterator_end) {
  set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  auto it1 = s1.end();
  auto it2 = s1.end();
  EXPECT_EQ(it1 == it2, true);
}

TEST(set_test, iterator_end_2) {
  set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  auto it1 = s1.end();
  auto it2 = s1.end();
  EXPECT_EQ(it1 != it2, false);
}

TEST(set_test, iterator_end_3) {
  set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  auto it1 = s1.end();
  auto it2 = s1.end();
  ++it2;
  EXPECT_EQ(it1 == it2, true);
}

TEST(set_test, iterator_cend) {
  set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  auto it1 = s1.cend();
  auto it2 = s1.cend();
  ++it2;
  EXPECT_EQ(it1 == it2, true);
}

TEST(set_test, iterator_cbegin) {
  set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<int> s2 = {1, 2, 3, 4, 5, 6, 7, 8};
  auto it1 = s1.cbegin();
  auto it2 = s2.cbegin();
  for (int i = 0; i < 4; i++) ++it1, ++it2;
  EXPECT_EQ(*it1, *it2);
}

TEST(set_test, merge_begin) {
  set<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::set<int> s2 = {1, 2, 3, 4, 5, 6, 7, 8, 11, 111, 189, 389, 3829};
  set<int> s11 = {11, 111, 189, 389, 3829};
  s1.merge(s11);
  EXPECT_EQ(s1.size(), s2.size());
  auto it1 = s1.begin();
  for (auto it2 = s2.begin(); it2 != s2.end(); ++it1, ++it2)
    EXPECT_EQ(*it1, *it2);
}

TEST(Set_Functions, default_constructor) {
  std::set<int> std_set;
  set<int> s21_set;

  EXPECT_EQ(std_set.size(), s21_set.size());
}

TEST(Set_Functions, initializer_constructor) {
  std::set<int> std_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};
  set<int> s21_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};
  EXPECT_EQ(std_set.size(), s21_set.size());

  std::set<int> std_empty_set{};
  set<int> s21_empty_set{};
  EXPECT_EQ(std_empty_set.size(), s21_empty_set.size());
}

TEST(Set_Functions, copy_constructor) {
  std::set<int> std_copy_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};
  std::set<int> std_set = std_copy_set;

  set<int> s21_copy_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};
  set<int> s21_set = s21_copy_set;

  auto std_it = std_set.begin();
  auto s21_it = s21_set.begin();

  for (; std_it != std_set.end(); ++std_it, ++s21_it)
    EXPECT_EQ(*std_it, *s21_it);
}

TEST(Set_Functions, move_constructor) {
  std::set<int> std_moving_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};
  std::set<int> std_set = std::move(std_moving_set);

  set<int> s21_moving_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};
  set<int> s21_set = std::move(s21_moving_set);

  auto std_it = std_set.begin();
  auto s21_it = s21_set.begin();

  for (; std_it != std_set.end(); ++std_it, ++s21_it)
    EXPECT_EQ(*std_it, *s21_it);

  std::set<int> std_null_set;
  std::set<int> std_set_2 = std::move(std_null_set);

  set<int> s21_null_set;
  set<int> s21_set_2 = std::move(s21_null_set);

  EXPECT_EQ(std_null_set.size(), s21_null_set.size());
  EXPECT_EQ(std_set_2.size(), s21_set_2.size());
}

TEST(Set_Functions, assignment_operator_overload) {
  std::set<int> std_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};
  set<int> s21_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};

  std::set<int> std_set_2{55, 43, 45, 23, 46, 12, -123};
  set<int> s21_set_2{55, 43, 45, 23, 46, 12, -123};

  std_set_2 = std::move(std_set);
  s21_set_2 = std::move(s21_set);

  auto std_it = std_set_2.begin();
  auto s21_it = s21_set_2.begin();

  for (; std_it != std_set_2.end(); ++std_it, ++s21_it)
    EXPECT_EQ(*std_it, *s21_it);
}

TEST(Set_Iterators, begin) {
  std::set<int> std_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};
  set<int> s21_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};

  EXPECT_EQ(*(std_set.begin()), *(s21_set.begin()));
}

TEST(Set_Capacity, empty) {
  std::set<int> std_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};
  set<int> s21_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};
  EXPECT_EQ(std_set.empty(), s21_set.empty());

  std::set<int> std_empty_set{};
  std::set<int> s21_empty_set{};
  EXPECT_EQ(std_empty_set.empty(), s21_empty_set.empty());
}

TEST(Set_Capacity, size) {
  std::set<int> std_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};
  set<int> s21_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};
  EXPECT_EQ(std_set.size(), s21_set.size());

  std::set<int> std_empty_set{};
  std::set<int> s21_empty_set{};
  EXPECT_EQ(std_empty_set.size(), s21_empty_set.size());
}

TEST(Set_Capacity, max_size) {
  std::set<int> std_empty_set{};
  std::set<int> s21_empty_set{};
  EXPECT_EQ(std_empty_set.max_size(), s21_empty_set.max_size());
}

TEST(Set_Modifiers, clear) {
  std::set<int> std_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};
  set<int> s21_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};

  std_set.clear();
  s21_set.clear();

  std::set<int> std_empty_set{};
  std::set<int> s21_empty_set{};

  EXPECT_EQ(std_set.size(), std_empty_set.size());
  EXPECT_EQ(s21_set.size(), s21_empty_set.size());
}

TEST(Set_Modifiers, insert) {
  std::set<int> std_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};
  set<int> s21_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};

  auto std_insert_pair = std_set.insert(350);
  auto s21_insert_pair = s21_set.insert(350);

  EXPECT_EQ(std_insert_pair.second, s21_insert_pair.second);

  auto std_it = std_set.begin();
  auto s21_it = s21_set.begin();

  for (; std_it != std_set.end(); ++std_it, ++s21_it)
    EXPECT_EQ(*std_it, *s21_it);
}

TEST(Set_Modifiers, erase) {
  std::set<int> std_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};
  set<int> s21_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};

  auto std_it = std_set.begin();
  auto s21_it = s21_set.begin();

  std_set.erase(std_it);
  s21_set.erase(s21_it);

  std_it = std_set.begin();
  s21_it = s21_set.begin();
  for (; std_it != std_set.end(); ++std_it, ++s21_it)
    EXPECT_EQ(*std_it, *s21_it);
}

TEST(Set_Modifier, swap_begin_end) {
  std::set<int> std_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};
  set<int> s21_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};

  std::set<int> std_set_2{55, 43, 45, 23, 46, 12, -123};
  set<int> s21_set_2{55, 43, 45, 23, 46, 12, -123};

  std_set.swap(std_set_2);
  s21_set.swap(s21_set_2);

  auto std_it = std_set.begin();
  auto s21_it = s21_set.begin();

  for (; std_it != std_set.end(); ++std_it, ++s21_it)
    EXPECT_EQ(*std_it, *s21_it);

  std_it = std_set_2.begin();
  s21_it = s21_set_2.begin();
  for (; std_it != std_set_2.end(); ++std_it, ++s21_it)
    EXPECT_EQ(*std_it, *s21_it);
}

TEST(Set_Modifier, merge_begin_end_6) {
  std::set<int> std_set{3, 2,  0,  5,  3,  2,  9,  -10, 9,
                        0, 55, 43, 45, 23, 46, 12, -123};
  set<int> s21_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};

  set<int> s21_set_2{55, 43, 45, 23, 46, 12, -123};

  s21_set.merge(s21_set_2);

  auto std_it = std_set.begin();
  auto s21_it = s21_set.begin();
  for (; std_it != std_set.end(); ++std_it, ++s21_it)
    EXPECT_EQ(*std_it, *s21_it);
}

TEST(Set_Lookup, find_3) {
  std::set<int> std_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};
  set<int> s21_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};

  auto std_it = std_set.find(9);
  auto s21_it = s21_set.find(9);
  EXPECT_EQ(*std_it, *s21_it);
}

TEST(Set_Lookup, contains_2) {
  std::set<int> std_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};
  set<int> s21_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};

  EXPECT_EQ(true, s21_set.contains(-10));
  EXPECT_EQ(false, s21_set.contains(9555));
}

TEST(Set_Lookup, find_exist) {
  set<int> s21_set{3, 2, 0, 5, 3, 2, 9, -10, 9, 0};
  auto iter_find = s21_set.find(17);
  auto iter_begin = s21_set.cend();

  EXPECT_EQ(iter_find, iter_begin);
}

TEST(set_test, insert_many) {
  set<int> m1 = {1};
  m1.insert_many(2, 3, 4, 5);
  EXPECT_EQ(m1.size(), 5);
}

TEST(set_member_functions, copy_constructor) {
  std::set<int> std_copy_set{0, 1, 2};
  std::set<int> std_set = std_copy_set;

  set<int> s21_copy_set{0, 1, 2};
  set<int> s21_set = s21_copy_set;

  EXPECT_EQ(std_set.size(), s21_set.size());
}

TEST(set_member_functions, move_constructor) {
  std::set<int> std_moving_set{0, 1, 2};
  std::set<int> std_set = std::move(std_moving_set);

  set<int> s21_moving_set{0, 1, 2};
  set<int> s21_set = std::move(s21_moving_set);

  EXPECT_EQ(std_moving_set.size(), s21_moving_set.size());
  EXPECT_EQ(std_set.size(), s21_set.size());

  // // перемещение пустого словаря
  std::set<int> std_null_set;
  std::set<int> std_set_2 = std::move(std_moving_set);

  set<int> s21_null_set;
  set<int> s21_set_2 = std::move(s21_moving_set);

  EXPECT_EQ(std_null_set.size(), s21_null_set.size());
  EXPECT_EQ(std_set_2.size(), s21_set_2.size());
}

TEST(set_member_functions, operator_assignment_copy) {
  set<int> s21_set_1 = {4};
  set<int> s21_set_2 = {5, 7};
  s21_set_1 = s21_set_2;

  EXPECT_EQ(s21_set_1.size(), 2);
  EXPECT_EQ(2, s21_set_2.size());
}

// int main(int argc** argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }