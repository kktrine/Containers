#include <gtest/gtest.h>

#include <list>

#include "../headers/s21_list.h"
#include "../source/s21_list.cc"
#include "../source/s21_list_iterator.cc"
#define EPS_TESTS 1e-06

TEST(CREATE_LIST, empty_list) {
  s21::list<int> s21_lst;
  std::list<int> lst;
  ASSERT_EQ(s21_lst.size(), lst.size());
}

TEST(CREATE_LIST, size_5) {
  s21::list<int> s21_lst(5);
  std::list<int> lst(5);
  ASSERT_EQ(s21_lst.size(), lst.size());
}

TEST(CREATE_LIST, initializer_list) {
  s21::list<int> s21_lst = {1, 7, 2, 5, 89, -9};
  std::list<int> lst = {1, 7, 2, 5, 89, -9};
  s21::list<int>::iterator j = s21_lst.begin();
  for (auto i = lst.begin(); i != lst.end() && j != s21_lst.end(); ++i) {
    ASSERT_EQ(*i, *j);
    ++j;
  }
  ASSERT_EQ(s21_lst.size(), lst.size());
}

TEST(CREATE_LIST, copy_constructor) {
  s21::list<double> s21_lst1 = {1, 7, 2, 5, 89, -9};
  s21::list<double> s21_lst2(s21_lst1);
  std::list<double> lst1 = {1, 7, 2, 5, 89, -9};
  std::list<double> lst2(lst1);
  auto j = s21_lst2.begin();
  for (auto i = lst2.begin(); i != lst2.end() && j != s21_lst2.end(); ++i) {
    ASSERT_EQ(*i, *j);
    ++j;
  }
  ASSERT_EQ(s21_lst2.size(), lst2.size());
  ASSERT_EQ(s21_lst1.size(), lst1.size());
}

TEST(CREATE_LIST, move_constructor) {
  s21::list<double> s21_lst1 = {1, 7, 2, 5, 89, -9};
  s21::list<double> s21_lst2(std::move(s21_lst1));
  std::list<double> lst1 = {1, 7, 2, 5, 89, -9};
  std::list<double> lst2(move(lst1));
  auto j = s21_lst2.begin();
  for (auto i = lst2.begin(); i != lst2.end() && j != s21_lst2.end(); ++i) {
    ASSERT_EQ(*i, *j);
    ++j;
  }
  ASSERT_EQ(s21_lst2.size(), lst2.size());
  ASSERT_EQ(s21_lst1.size(), lst1.size());
}

TEST(CREATE_LIST, operator_eq) {
  s21::list<double> s21_lst1 = {1, 7, 2, 5, 89, -9};
  s21::list<double> s21_lst2 = s21_lst1;
  std::list<double> lst1 = {1, 7, 2, 5, 89, -9};
  std::list<double> lst2(lst1);
  auto j = s21_lst2.begin();
  for (auto i = lst2.begin(); i != lst2.end() && j != s21_lst2.end(); ++i) {
    ASSERT_EQ(*i, *j);
    ++j;
  }
  ASSERT_EQ(s21_lst2.size(), lst2.size());
  ASSERT_EQ(s21_lst1.size(), lst1.size());
}

TEST(List_Element_access, front_back) {
  s21::list<int> s21_lst1 = {1, 7, 2, 5, 89, -9};
  ASSERT_EQ(s21_lst1.front(), 1);
  ASSERT_EQ(s21_lst1.back(), -9);
}

TEST(List_Iterators, empty_list) {
  s21::list<int> s21_lst1;
  ASSERT_EQ(s21_lst1.begin() == s21_lst1.end(), true);
}

TEST(List_Capacity, empty_list) {
  s21::list<int> s21_lst1;
  ASSERT_EQ(s21_lst1.empty(), true);
}

TEST(List_Capacity, not_empty_list) {
  s21::list<int> s21_lst1 = {1, 7, 2, 5, 89, -9};
  ASSERT_EQ(s21_lst1.size(), 6);
}

// TEST(List_Capacity, max_size) {
//   s21::list<int> s21_lst1 = {1, 7, 2, 5, 89, -9};
//   std::list<int> lst1 = {1, 7, 2, 5, 89, -9};
//   ASSERT_NEAR(s21_lst1.max_size(), lst1.max_size(), 1e4);
// }

TEST(List_Modifiers, clear) {
  s21::list<int> s21_lst1 = {1, 7, 2, 5, 89, -9};
  s21_lst1.clear();
  ASSERT_EQ(s21_lst1.size(), 0);
}

TEST(List_Modifiers, insert) {
  s21::list<int> s21_lst1 = {1, 7, 2, 5, 89, -9};
  std::list<int> lst1 = {1, 7, 2, 5, 89, -9};
  s21::list<int>::Iterator s21_ptr = s21_lst1.begin();
  auto ptr = lst1.begin();
  ++(++s21_ptr);
  ++(++ptr);
  s21_lst1.insert(s21_ptr, 100);
  lst1.insert(ptr, 100);
  auto j = s21_lst1.begin();
  for (auto i = lst1.begin(); i != lst1.end() && j != s21_lst1.end(); ++i) {
    ASSERT_EQ(*i, *j);
    ++j;
  }
  ASSERT_EQ(s21_lst1.size(), lst1.size());
}

TEST(List_Modifiers, erase) {
  s21::list<int> s21_lst1 = {1, 7, 2, 5, 89, -9};
  std::list<int> lst1 = {1, 7, 2, 5, 89, -9};
  auto s21_ptr = s21_lst1.begin();
  auto ptr = lst1.begin();
  ++(++s21_ptr);
  ++(++ptr);
  s21_lst1.erase(s21_ptr);
  lst1.erase(ptr);
  auto j = s21_lst1.begin();
  for (auto i = lst1.begin(); i != lst1.end() && j != s21_lst1.end(); ++i) {
    ASSERT_EQ(*i, *j);
    ++j;
  }
  ASSERT_EQ(s21_lst1.size(), lst1.size());
}

TEST(List_Modifiers, push_back) {
  s21::list<char> s21_lst1 = {1, 7, 2, 5, 89, -9};
  std::list<char> lst1 = {1, 7, 2, 5, 89, -9};
  s21_lst1.push_back(100);
  lst1.push_back(100);
  auto j = s21_lst1.begin();
  for (auto i = lst1.begin(); i != lst1.end() && j != s21_lst1.end(); ++i) {
    ASSERT_EQ(*i, *j);
    ++j;
  }
  ASSERT_EQ(s21_lst1.size(), lst1.size());
}

TEST(List_Modifiers, pop_back) {
  s21::list<double> s21_lst1 = {1, 7, 2, 5, 89, -9};
  std::list<double> lst1 = {1, 7, 2, 5, 89, -9};
  s21_lst1.pop_back();
  lst1.pop_back();
  auto j = s21_lst1.begin();
  for (auto i = lst1.begin(); i != lst1.end() && j != s21_lst1.end(); ++i) {
    ASSERT_EQ(*i, *j);
    ++j;
  }
  ASSERT_EQ(s21_lst1.size(), lst1.size());
}

TEST(List_Modifiers, push_front) {
  s21::list<int> s21_lst1 = {1, 7, 2, 5, 89, -9};
  std::list<int> lst1 = {1, 7, 2, 5, 89, -9};
  s21_lst1.push_front(100);
  lst1.push_front(100);
  auto j = s21_lst1.begin();
  for (auto i = lst1.begin(); i != lst1.end() && j != s21_lst1.end(); ++i) {
    ASSERT_EQ(*i, *j);
    ++j;
  }
  ASSERT_EQ(s21_lst1.size(), lst1.size());
}

TEST(List_Modifiers, pop_front) {
  s21::list<double> s21_lst1 = {1, 7, 2, 5, 89, -9};
  std::list<double> lst1 = {1, 7, 2, 5, 89, -9};
  s21_lst1.pop_front();
  lst1.pop_front();
  auto j = s21_lst1.begin();
  for (auto i = lst1.begin(); i != lst1.end() && j != s21_lst1.end(); ++i) {
    ASSERT_EQ(*i, *j);
    ++j;
  }
  ASSERT_EQ(s21_lst1.size(), lst1.size());
}

TEST(List_Modifiers, swap) {
  s21::list<int> s21_lst1 = {1, 7, 2, 5, 89, -9};
  s21::list<int> s21_lst2 = {10, 200, 134};
  std::list<int> lst1 = {1, 7, 2, 5, 89, -9};
  std::list<int> lst2 = {10, 200, 134};
  s21_lst1.swap(s21_lst2);
  lst1.swap(lst2);
  auto j = s21_lst2.begin();
  for (auto i = lst2.begin(); i != lst2.end() && j != s21_lst2.end(); ++i) {
    ASSERT_EQ(*i, *j);
    ++j;
  }

  j = s21_lst1.begin();
  for (auto i = lst1.begin(); i != lst1.end() && j != s21_lst1.end(); ++i) {
    ASSERT_EQ(*i, *j);
    ++j;
  }
  ASSERT_EQ(s21_lst2.size(), lst2.size());
  ASSERT_EQ(s21_lst1.size(), lst1.size());
}

TEST(List_Modifiers, splice) {
  s21::list<int> s21_lst1 = {1, 7, 2, 5, 89, -9};
  s21::list<int> s21_lst2 = {10, 200, 134};
  std::list<int> lst1 = {1, 7, 2, 5, 89, -9};
  std::list<int> lst2 = {10, 200, 134};
  s21::list<int>::constIterator s21_iter = s21_lst1.cbegin();
  std::list<int>::const_iterator iter = lst1.cbegin();
  ++iter;
  ++s21_iter;
  s21_lst1.splice(s21_iter, s21_lst2);
  lst1.splice(iter, lst2);

  auto j = s21_lst2.begin();
  for (auto i = lst2.begin(); i != lst2.end() && j != s21_lst2.end(); ++i) {
    ASSERT_EQ(*i, *j);
    ++j;
  }

  j = s21_lst1.begin();
  for (auto i = lst1.begin(); i != lst1.end() && j != s21_lst1.end(); ++i) {
    ASSERT_EQ(*i, *j);
    ++j;
  }
  ASSERT_EQ(s21_lst2.size(), lst2.size());
  ASSERT_EQ(s21_lst1.size(), lst1.size());
}

TEST(List_Modifiers, reverse) {
  s21::list<int> s21_lst1 = {1, 7, 2, 5, 89, -9};
  std::list<int> lst1 = {1, 7, 2, 5, 89, -9};
  s21_lst1.reverse();
  lst1.reverse();

  auto j = s21_lst1.begin();
  for (auto i = lst1.begin(); i != lst1.end() && j != s21_lst1.end(); ++i) {
    ASSERT_EQ(*i, *j);
    ++j;
  }
  ASSERT_EQ(s21_lst1.size(), lst1.size());
}

TEST(List_Modifiers, unique) {
  s21::list<int> s21_lst1 = {1, 1, 1, 2, 1, 1,  1,  5, 5,
                             5, 7, 5, 8, 3, 87, 87, 0};
  std::list<int> lst1 = {1, 1, 1, 2, 1, 1, 1, 5, 5, 5, 7, 5, 8, 3, 87, 87, 0};
  s21_lst1.unique();
  lst1.unique();

  auto j = s21_lst1.begin();
  for (auto i = lst1.begin(); i != lst1.end() && j != s21_lst1.end(); ++i) {
    ASSERT_EQ(*i, *j);
    ++j;
  }
  ASSERT_EQ(s21_lst1.size(), lst1.size());
}

TEST(List_Modifiers, sort) {
  s21::list<int> s21_lst1 = {1, 1, 1, 2, 1, 1,  1,  5, 5,
                             5, 7, 5, 8, 3, 87, 87, 0};
  std::list<int> lst1 = {1, 1, 1, 2, 1, 1, 1, 5, 5, 5, 7, 5, 8, 3, 87, 87, 0};
  s21_lst1.sort();
  lst1.sort();

  auto j = s21_lst1.begin();
  for (auto i = lst1.begin(); i != lst1.end() && j != s21_lst1.end(); ++i) {
    ASSERT_EQ(*i, *j);
    ++j;
  }
  ASSERT_EQ(s21_lst1.size(), lst1.size());
}

TEST(List_Modifiers, merge_sorted) {
  s21::list<int> s21_lst1 = {1, 7, 2, 5, 89, -9};
  s21::list<int> s21_lst2 = {10, 200, 134};
  std::list<int> lst1 = {1, 7, 2, 5, 89, -9};
  std::list<int> lst2 = {10, 200, 134};

  s21_lst1.sort();
  lst1.sort();
  s21_lst2.sort();
  lst2.sort();
  s21_lst1.merge(s21_lst2);
  lst1.merge(lst2);

  auto j = s21_lst1.begin();
  for (auto i = lst1.begin(); i != lst1.end() && j != s21_lst1.end(); ++i) {
    ASSERT_EQ(*i, *j);
    ++j;
  }
  ASSERT_EQ(s21_lst1.size(), lst1.size());
}

TEST(List_Modifiers, merge_not_sorted) {
  s21::list<int> s21_lst1 = {1, 7, 2, 5, 89, -9};
  s21::list<int> s21_lst2 = {10, 200, 134};
  std::list<int> lst1 = {1, 7, 2, 5, 89, -9};
  std::list<int> lst2 = {10, 200, 134};

  s21_lst1.merge(s21_lst2);
  lst1.merge(lst2);

  auto j = s21_lst1.begin();
  for (auto i = lst1.begin(); i != lst1.end() && j != s21_lst1.end(); ++i) {
    ASSERT_EQ(*i, *j);
    ++j;
  }
  ASSERT_EQ(s21_lst1.size(), lst1.size());
}

TEST(List_Modifiers, merge_sorted_2) {
  s21::list<int> s21_lst1 = {1, 10, 10, 7, 2, 5, 89, -9};
  s21::list<int> s21_lst2 = {1, 1, 1, 10, 200, 134};
  std::list<int> lst1 = {1, 10, 10, 7, 2, 5, 89, -9};
  std::list<int> lst2 = {1, 1, 1, 10, 200, 134};

  s21_lst1.sort();
  lst1.sort();
  s21_lst2.sort();
  lst2.sort();
  s21_lst1.merge(s21_lst2);
  lst1.merge(lst2);

  auto j = s21_lst1.begin();
  for (auto i = lst1.begin(); i != lst1.end() && j != s21_lst1.end(); ++i) {
    ASSERT_EQ(*i, *j);
    ++j;
  }
  ASSERT_EQ(s21_lst1.size(), lst1.size());
}

TEST(List_Modifiers, insert_many_back) {
  s21::list<int> s21_lst1 = {1, 10, 10, 7, 2, 5, 89, -9};
  std::list<int> lst1 = {1, 10, 10, 7, 2, 5, 89, -9};
  s21_lst1.insert_many_back(65, 325, 98677, 231, 65);
  lst1.insert(lst1.end(), {65, 325, 98677, 231, 65});

  auto j = s21_lst1.begin();
  for (auto i = lst1.begin(); i != lst1.end() && j != s21_lst1.end(); ++i) {
    ASSERT_EQ(*i, *j);
    ++j;
  }
  ASSERT_EQ(s21_lst1.size(), lst1.size());
}

TEST(List_Modifiers, insert_many_front) {
  s21::list<int> s21_lst1 = {1, 10, 10, 7, 2, 5, 89, -9};
  std::list<int> lst1 = {1, 10, 10, 7, 2, 5, 89, -9};
  s21_lst1.insert_many_front(650, 325, 98677, 231, 65);
  lst1.insert(lst1.begin(), {650, 325, 98677, 231, 65});

  auto j = s21_lst1.begin();
  for (auto i = lst1.begin(); i != lst1.end() && j != s21_lst1.end(); ++i) {
    ASSERT_EQ(*i, *j);
    ++j;
  }
  ASSERT_EQ(s21_lst1.size(), lst1.size());
}

TEST(List_Modifiers, insert_many) {
  s21::list<int> s21_lst1 = {1, 10, 10, 7, 2, 5, 89, -9};
  std::list<int> lst1 = {1, 10, 10, 7, 2, 5, 89, -9};
  auto s21_iter =
      s21_lst1.insert_many(++s21_lst1.cbegin(), 650, 325, 98677, 231, 65);
  auto iter = lst1.insert(++lst1.begin(), {650, 325, 98677, 231, 65});

  auto j = s21_lst1.begin();
  for (auto i = lst1.begin(); i != lst1.end() && j != s21_lst1.end(); ++i) {
    ASSERT_EQ(*i, *j);
    ++j;
  }
  ASSERT_EQ(s21_lst1.size(), lst1.size());
  ASSERT_EQ(*s21_iter, *iter);
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}