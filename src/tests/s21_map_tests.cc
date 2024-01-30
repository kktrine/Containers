#include <map>
#include <vector>

#include "../headers/s21_map.h"
#include "../source/RedBlackTreeOperations.cc"
#include "gtest/gtest.h"

using s21::map;

TEST(map_member_functions, default_constructor) {
  std::map<int, int> std_map;
  std_map[2] = 2;
  map<int, int> s21_map;
  s21_map.insert(2, 2);
  EXPECT_EQ(std_map[2], s21_map[2]);
  EXPECT_EQ(std_map.size(), s21_map.size());
}

TEST(map_member_functions, initializer_list_constructor) {
  std::map<int, char> std_map{{0, 'a'}, {1, 'b'}, {2, 'c'}};
  map<int, char> s21_map{{0, 'a'}, {1, 'b'}, {2, 'c'}};

  for (int i = 0; i <= 2; i++) EXPECT_EQ(std_map[i], s21_map[i]);

  EXPECT_EQ(std_map.size(), s21_map.size());

  // пустой словарь
  std::map<int, char> std_empty_map{};
  std::map<int, char> s21_empty_map{};
  EXPECT_EQ(std_empty_map.size(), s21_empty_map.size());
}

TEST(map_member_functions, copy_constructor) {
  std::map<int, char> std_copy_map{{0, 'a'}, {1, 'b'}, {2, 'c'}};
  std::map<int, char> std_map = std_copy_map;

  map<int, char> s21_copy_map{{0, 'a'}, {1, 'b'}, {2, 'c'}};
  map<int, char> s21_map = s21_copy_map;

  for (int i = 0; i <= 2; i++) EXPECT_EQ(std_map[i], s21_map[i]);

  EXPECT_EQ(std_map.size(), s21_map.size());
}

TEST(map_member_functions, move_constructor) {
  std::map<int, char> std_moving_map{{0, 'a'}, {1, 'b'}, {2, 'c'}};
  std::map<int, char> std_map = std::move(std_moving_map);

  map<int, char> s21_moving_map{{0, 'a'}, {1, 'b'}, {2, 'c'}};
  map<int, char> s21_map = std::move(s21_moving_map);

  EXPECT_EQ(std_moving_map.size(), s21_moving_map.size());
  EXPECT_EQ(std_map.size(), s21_map.size());

  // // перемещение пустого словаря
  std::map<int, char> std_null_map;
  std::map<int, char> std_map_2 = std::move(std_moving_map);

  map<int, char> s21_null_map;
  map<int, char> s21_map_2 = std::move(s21_moving_map);

  EXPECT_EQ(std_null_map.size(), s21_null_map.size());
  EXPECT_EQ(std_map_2.size(), s21_map_2.size());
}

TEST(map_member_functions, operator_assignment_copy) {
  std::map<int, int> std_map_1;
  std_map_1[2] = 4;
  std::map<int, int> std_map_2;
  std_map_2[0] = 5;
  std_map_2[1] = 7;
  std_map_1 = std_map_2;

  map<int, int> s21_map_1;
  s21_map_1.insert(2, 4);
  map<int, int> s21_map_2;
  s21_map_2.insert(0, 5);
  s21_map_2.insert(1, 7);
  s21_map_1 = s21_map_2;

  EXPECT_EQ(std_map_1.size(), s21_map_1.size());
  EXPECT_EQ(2, s21_map_2.size());
  EXPECT_EQ(2, s21_map_2.size());
  for (int i = 0; i <= 1; i++) EXPECT_EQ(std_map_1[i], s21_map_1[i]);
}

TEST(map_member_functions, operator_assignment_move) {
  std::map<int, int> std_map_1;
  std_map_1[2] = 4;
  std::map<int, int> std_map_2;
  std_map_2[0] = 5;
  std_map_2[1] = 7;
  std_map_1 = std::move(std_map_2);

  map<int, int> s21_map_1;
  s21_map_1.insert(2, 4);
  map<int, int> s21_map_2;
  s21_map_2.insert(0, 5);
  s21_map_2.insert(1, 7);
  s21_map_1 = std::move(s21_map_2);

  EXPECT_EQ(std_map_1.size(), s21_map_1.size());
  EXPECT_EQ(0, s21_map_2.size());
  EXPECT_EQ(0, s21_map_2.size());
  for (int i = 0; i <= 1; i++) EXPECT_EQ(std_map_1[i], s21_map_1[i]);
}

TEST(map_element_access, at) {
  std::map<int, char> std_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};
  map<int, char> s21_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};

  for (int i = 0; i <= 2; i++) EXPECT_EQ(std_map.at(i), s21_map.at(i));

  std::pair<int, char> p1;
  p1.first = 1;
  p1.second = 'a';
  std::pair<int, char> p2;
  p2.first = 2;
  p2.second = 'b';

  std::map<std::pair<int, char>, std::string> std_map_2{{p1, "first_letter"}};
  map<std::pair<int, char>, std::string> s21_map_2{{p1, "first_letter"}};
  EXPECT_EQ(std_map_2.at(p1), s21_map_2.at(p1));
  EXPECT_THROW(
      {
        s21_map_2.at(p2);
        throw std::out_of_range("Out of range, No matches found for key");
      },
      std::out_of_range);
}

TEST(map_element_access, square_brackets) {
  std::map<int, char> std_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};
  map<int, char> s21_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};

  for (int i = 0; i <= 2; i++) EXPECT_EQ(std_map[i], s21_map[i]);

  std::pair<int, char> p1;
  p1.first = 1;
  p1.second = 'a';

  std::map<std::pair<int, char>, std::string> std_map_2{{p1, "first_letter"}};
  map<std::pair<int, char>, std::string> s21_map_2{{p1, "first_letter"}};
  EXPECT_EQ(std_map_2[p1], s21_map_2[p1]);
}

TEST(map_iterators, begin) {
  std::map<int, char> std_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};
  map<int, char> s21_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};
  auto std_it = std_map.begin();
  auto s21_it = s21_map.begin();
  EXPECT_EQ(std_it->first, s21_it->first);
  EXPECT_EQ(std_it->second, s21_it->second);
}

TEST(map_iterators, end) {
  std::map<int, char> std_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};
  map<int, char> s21_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};
  auto s21_it = s21_map.end();
  auto std_it_1 = std_map.begin();
  auto s21_it_1 = s21_map.begin();
  s21_it_1++;
  s21_it_1++;
  ++s21_it_1;
  std_it_1++;
  std_it_1++;
  ++std_it_1;
  EXPECT_EQ(s21_it_1->first, s21_it->first);
  EXPECT_EQ(s21_it_1->second, s21_it->second);
}

TEST(map_iterators, cbegin) {
  std::map<int, char> std_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};
  map<int, char> s21_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};
  auto std_it = std_map.cbegin();
  auto s21_it = s21_map.cbegin();
  EXPECT_EQ(std_it->first, s21_it->first);
  EXPECT_EQ(std_it->second, s21_it->second);
}

TEST(map_iterators, cend) {
  std::map<int, char> std_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};
  map<int, char> s21_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};
  auto s21_it = s21_map.cend();
  auto std_it_1 = std_map.cbegin();
  auto s21_it_1 = s21_map.cbegin();
  s21_it_1++;
  s21_it_1++;
  ++s21_it_1;
  std_it_1++;
  std_it_1++;
  ++std_it_1;
  EXPECT_EQ(s21_it_1->first, s21_it->first);
  EXPECT_EQ(s21_it_1->second, s21_it->second);
}

TEST(map_Capacity, empty) {
  std::map<int, char> std_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};
  map<int, char> s21_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};
  EXPECT_EQ(std_map.empty(), s21_map.empty());

  std::map<int, char> std_empty_map{};
  std::map<int, char> s21_empty_map{};
  EXPECT_EQ(std_empty_map.empty(), s21_empty_map.empty());
}

TEST(map_iterators_cbegin_Test, size) {
  std::map<int, char> std_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};
  map<int, char> s21_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};
  EXPECT_EQ(std_map.size(), s21_map.size());

  std::map<int, char> std_empty_map{};
  std::map<int, char> s21_empty_map{};
  EXPECT_EQ(std_empty_map.size(), s21_empty_map.size());
}

TEST(map_Capacity, max_size) {
  std::map<int, char> std_empty_map{};
  map<int, char> s21_empty_map{};
  EXPECT_LE(s21_empty_map.max_size() - std_empty_map.max_size(), 1000000);
}

TEST(map_Modifiers, clear) {
  std::map<int, char> std_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};
  map<int, char> s21_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};

  std_map.clear();
  s21_map.clear();

  std::map<int, char> std_empty_map{};
  std::map<int, char> s21_empty_map{};

  EXPECT_EQ(std_map.size(), std_empty_map.size());
  EXPECT_EQ(s21_map.size(), s21_empty_map.size());
}

TEST(map_Modifier, insert_type_one) {
  std::map<int, char> std_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};
  map<int, char> s21_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};

  auto std_insert_pair = std_map.insert({4, 'd'});
  auto s21_insert_pair = s21_map.insert({4, 'd'});
  EXPECT_EQ(std_insert_pair.first->first, s21_insert_pair.first->first);
  EXPECT_EQ(std_insert_pair.first->second, s21_insert_pair.first->second);
  EXPECT_EQ(std_insert_pair.second, s21_insert_pair.second);
  EXPECT_EQ(std_map[4], s21_map[4]);
}

TEST(Map_Modifier, insert_type_two) {
  std::map<int, char> std_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};
  map<int, char> s21_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};

  auto std_insert_pair = std_map.insert({4, 'd'});
  auto s21_insert_pair = s21_map.insert({4, 'd'});
  EXPECT_EQ(std_insert_pair.first->first, s21_insert_pair.first->first);
  EXPECT_EQ(std_insert_pair.first->second, s21_insert_pair.first->second);
  EXPECT_EQ(std_insert_pair.second, s21_insert_pair.second);

  EXPECT_EQ(std_map[4], s21_map[4]);
}

TEST(Map_Modifier, insert_or_assign) {
  map<int, char> s21_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};

  auto s21_insert_pair = s21_map.insert_or_assign(4, 'd');
  EXPECT_EQ(true, s21_insert_pair.second);
  EXPECT_EQ('d', s21_map[4]);

  s21_insert_pair = s21_map.insert_or_assign(0, 'z');
  EXPECT_EQ(false, s21_insert_pair.second);
  EXPECT_EQ('z', s21_map[0]);
}

TEST(Map_Modifier, erase) {
  std::map<int, char> std_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};
  map<int, char> s21_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};

  auto std_it = std_map.begin();
  auto s21_it = s21_map.begin();

  ++std_it;
  ++s21_it;

  std_map.erase(std_it);
  s21_map.erase(s21_it);

  std_it = std_map.begin();
  s21_it = s21_map.begin();
  for (; std_it != std_map.end(); ++std_it, ++s21_it) {
    EXPECT_EQ(std_it->first, std_it->first);
    EXPECT_EQ(std_it->second, std_it->second);
  }
}

TEST(Map_Modifier, swap) {
  std::map<int, char> std_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};
  map<int, char> s21_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};

  std::map<int, char> std_map_2 = {{26, 'z'}, {25, 'y'}, {24, 'x'}};
  map<int, char> s21_map_2 = {{26, 'z'}, {25, 'y'}, {24, 'x'}};

  std_map.swap(std_map_2);
  s21_map.swap(s21_map_2);

  for (int i = 0; i <= 2; i++) EXPECT_EQ(std_map_2[i], s21_map_2[i]);

  for (int i = 26; i >= 24; i--) EXPECT_EQ(std_map[i], s21_map[i]);
}

TEST(Map_Modifier, merge) {
  map<int, char> s21_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};
  map<int, char> s21_map_2 = {{26, 'z'}, {25, 'y'}, {24, 'x'}};
  map<int, char> s21_map_3 = {{0, 'a'},  {1, 'b'},  {2, 'c'},
                              {26, 'z'}, {25, 'y'}, {24, 'x'}};
  s21_map.merge(s21_map_2);

  auto s21_it = s21_map.begin();
  auto s21_it_3 = s21_map_3.begin();
  for (; s21_it != s21_map.end(); ++s21_it, ++s21_it_3) {
    EXPECT_EQ(s21_it->first, s21_it_3->first);
    EXPECT_EQ(s21_it->second, s21_it_3->second);
  }
}

TEST(Map_Lookup, contains) {
  std::map<int, char> std_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};
  map<int, char> s21_map = {{0, 'a'}, {1, 'b'}, {2, 'c'}};

  EXPECT_EQ(true, s21_map.contains(0));
  EXPECT_EQ(false, s21_map.contains(95));
}

TEST(map_test, constr1) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  auto it1 = m1.begin();
  for (auto it2 = m2.begin(); it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ(it1->second, it2->second);
  it1 = m1.begin();
  for (auto it2 = m2.begin(); it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ(it1->first, it2->second);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, constr2) {
  map<int, int> m1;
  std::map<int, int> m2;
  EXPECT_EQ(m1.size(), m2.size());
  m1.insert({1, 1});
  m2.insert({1, 1});
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, constr3) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  auto m11 = m1;
  auto m22 = m2;
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); ++it2, ++it1)
    EXPECT_EQ(it1->second, it2->second);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
}

TEST(map_test, constr4) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  auto m11 = std::move(m1);
  auto m22 = std::move(m2);
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); ++it2, ++it1)
    EXPECT_EQ(it1->second, it2->second);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
}

TEST(map_test, at1) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
  for (size_t i = 1; i < m1.size(); i++) EXPECT_EQ(m1.at(i), m2.at(i));
}

TEST(map_test, at3) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1.at(100), m2.at(100));
}

TEST(map_test, begin1) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  auto it1 = m1.begin();
  auto it2 = m2.begin();
  EXPECT_EQ(it1->second, it2->second);
}

TEST(map_test, empty1) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, empty2) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, size1) {
  map<int, int> m1;
  std::map<int, int> m2;
  std::pair<int, int> pair = {1, 1};
  m1.insert(pair);
  m2.insert(pair);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, size2) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, size3) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, clear1) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, clear2) {
  map<int, int> m1;
  std::map<int, int> m2;
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, clear3) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
  m1.clear();
  m2.clear();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m1.empty(), m2.empty());
}

TEST(map_test, insert1) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::pair<int, int> pair = {3, 1};
  EXPECT_EQ(m1.insert(pair).second, m2.insert(pair).second);
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, insert2) {
  map<int, int> m1;
  std::map<int, int> m2;
  EXPECT_EQ(m1.empty(), m2.empty());
  std::pair<int, int> pair = {3, 1};
  EXPECT_EQ(m1.insert(pair).second, m2.insert(pair).second);
  EXPECT_EQ(m1.empty(), m2.empty());
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, erase1) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1.size(), m2.size());
  m1.erase(m1.begin());
  m2.erase(m2.begin());
  EXPECT_EQ(m1.size(), m2.size());
}

TEST(map_test, erase2) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  m1.erase(m1.begin());
  m2.erase(m2.begin());
  auto it1 = m1.begin();
  auto it2 = m2.begin();
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(it1->second, it2->second);
}

TEST(map_test, swap1) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  map<int, int> m11;
  std::map<int, int> m22;
  m1.swap(m11);
  m2.swap(m22);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); ++it1, ++it2)
    EXPECT_EQ(it1->second, it2->second);
}

TEST(map_test, swap2) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  map<int, int> m11 = {{389, 12}, {3829, 12}, {111, 12},
                       {189, 12}, {11, 12},   {33, 33}};
  std::map<int, int> m22 = {{389, 12}, {3829, 12}, {111, 12},
                            {189, 12}, {11, 12},   {33, 33}};
  EXPECT_EQ(m1.size(), m2.size());
  m1.swap(m11);
  m2.swap(m22);
  EXPECT_EQ(m1.size(), m2.size());
  EXPECT_EQ(m11.size(), m22.size());
  auto it1 = m11.begin();
  for (auto it2 = m22.begin(); it2 != m22.end(); ++it1, ++it2)
    EXPECT_EQ(it1->second, it2->second);
}

TEST(map_test, contains1) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1.contains(1), true);
}

TEST(map_test, contains2) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  EXPECT_EQ(m1.contains(5), true);
}

TEST(map_test, merge2) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  map<int, int> m11 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  m1.merge(m11);
  EXPECT_EQ(m1.size(), m2.size());
  auto it1 = m1.begin();
  for (auto it2 = m2.begin(); it2 != m2.end(); ++it1, ++it2)
    EXPECT_EQ(it1->second, it2->second);
}

TEST(map_test, change_key) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  auto it_1 = m1.begin();
  auto it_2 = m1.ChangeKey(it_1, 7);
  EXPECT_EQ(it_2->first, 7);
}

TEST(map_test, erase) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  m1.erase(m1.end());
  EXPECT_EQ(m1.size(), 5);
}

TEST(map_test, operator_square_brackets) {
  map<int, int> m1 = {{2, 2}, {100, 3}, {4, 4}, {5, 5}};
  m1[1];
  auto iter = m1.begin();
  EXPECT_EQ(iter->first, 1);
}

TEST(map_test, erase_root_1) {
  map<int, int> m1 = {{1, 1}};
  m1.erase(m1.begin());
  EXPECT_EQ(m1.size(), 0);
}

TEST(map_test, erase_root_2) {
  map<int, int> m1 = {{1, 1}, {2, 2}};
  m1.erase(m1.begin());
  EXPECT_EQ(m1.size(), 1);
}

TEST(map_test, erase_nonroot_1) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {4, 4}, {6, 6}};
  auto x = m1.begin();
  ++x;
  ++x;
  m1.erase(x);
  EXPECT_EQ(m1.size(), 3);
}

TEST(map_test, erase_nonroot_2) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {4, 4}, {3, 3}};
  auto x = m1.begin();
  ++x;
  ++x;
  ++x;
  m1.erase(x);
  EXPECT_EQ(m1.size(), 3);
}

TEST(map_test, iterator_decrement_1) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  auto s21_iter = m1.end();
  auto std_iter = m2.end();
  --s21_iter;
  --std_iter;
  EXPECT_EQ(s21_iter->first, std_iter->first);
  --s21_iter;
  --std_iter;
  EXPECT_EQ(s21_iter->first, std_iter->first);
  --s21_iter;
  --std_iter;
  EXPECT_EQ(s21_iter->first, std_iter->first);
}

TEST(map_test, iterator_decrement_2) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  auto s21_iter = m1.cend();
  auto std_iter = m2.cend();
  --s21_iter;
  --std_iter;
  EXPECT_EQ(s21_iter->first, std_iter->first);
  --s21_iter;
  --std_iter;
  EXPECT_EQ(s21_iter->first, std_iter->first);
  --s21_iter;
  --std_iter;
  EXPECT_EQ(s21_iter->first, std_iter->first);
}

TEST(map_test, iterator_decrement_3) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  auto s21_iter = m1.end();
  auto std_iter = m2.end();
  --s21_iter;
  --std_iter;
  EXPECT_EQ(s21_iter->first, std_iter->first);
  --s21_iter;
  --std_iter;
  EXPECT_EQ(s21_iter->first, std_iter->first);
  --s21_iter;
  --std_iter;
  EXPECT_EQ(s21_iter->first, std_iter->first);
  --s21_iter;
  --std_iter;
  EXPECT_EQ(s21_iter->first, std_iter->first);
  --s21_iter;
  --std_iter;
  EXPECT_EQ(s21_iter->first, std_iter->first);
  --s21_iter;
  --std_iter;
  EXPECT_EQ(s21_iter->first, 1);
  --s21_iter;
  --std_iter;
  EXPECT_EQ(s21_iter->first, 1);
}

TEST(map_test, iterator_decrement_4) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  auto s21_iter = m1.cend();
  auto std_iter = m2.cend();
  --s21_iter;
  --std_iter;
  EXPECT_EQ(s21_iter->first, std_iter->first);
  --s21_iter;
  --std_iter;
  EXPECT_EQ(s21_iter->first, std_iter->first);
  --s21_iter;
  --std_iter;
  EXPECT_EQ(s21_iter->first, std_iter->first);
  --s21_iter;
  --std_iter;
  EXPECT_EQ(s21_iter->first, std_iter->first);
  --s21_iter;
  --std_iter;
  EXPECT_EQ(s21_iter->first, std_iter->first);
  --s21_iter;
  --std_iter;
  EXPECT_EQ(s21_iter->first, 1);
  --s21_iter;
  --std_iter;
  EXPECT_EQ(s21_iter->first, 1);
}

TEST(map_test, insert_1) {
  map<int, int> m1 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  std::map<int, int> m2 = {{1, 1}, {2, 2}, {100, 3}, {4, 4}, {5, 5}};
  auto iterator_insert = m1.insert({1, 5});
  auto iterator_begin = m1.begin();
  EXPECT_EQ(iterator_insert.first->second, iterator_begin->second);
}

TEST(map_test, insert_many) {
  map<int, int> m1 = {{1, 1}};
  std::vector<std::pair<map<int, int>::iterator, bool>> result_vector =
      m1.insert_many(std::pair<int, int>{2, 2}, std::pair<int, int>{3, 3},
                     std::pair<int, int>{4, 4}, std::pair<int, int>{5, 5});
  EXPECT_EQ(result_vector.size(), 4);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}