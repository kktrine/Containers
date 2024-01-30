#include <gtest/gtest.h>

#include <queue>

#include "../headers/s21_queue.h"

#define EPS_TESTS 1e-06

TEST(Queue_Member_functions, empty_queue) {
  s21::queue<int> s21_lst;
  std::queue<int> lst;
  ASSERT_EQ(s21_lst.size(), lst.size());
}

TEST(Queue_Member_functions, initializer_list_constructor) {
  s21::queue<int> s21_lst({1, 76, 234, 896});
  std::queue<int> lst({1, 76, 234, 896});
  ASSERT_EQ(s21_lst.size(), lst.size());
  while (s21_lst.size() && lst.size()) {
    ASSERT_EQ(s21_lst.front(), lst.front());
    s21_lst.pop();
    lst.pop();
  }
}

TEST(Queue_Member_functions, copy_constructor) {
  s21::queue<int> s21_lst1({1, 76, 234, 896});
  std::queue<int> lst1({1, 76, 234, 896});
  s21::queue<int> s21_lst2(s21_lst1);
  std::queue<int> lst2(lst1);
  ASSERT_EQ(s21_lst1.size(), lst1.size());
  ASSERT_EQ(s21_lst2.size(), lst2.size());
  while (s21_lst1.size() && lst1.size()) {
    ASSERT_EQ(s21_lst1.front(), lst1.front());
    s21_lst1.pop();
    lst1.pop();
  }
  while (s21_lst2.size() && lst2.size()) {
    ASSERT_EQ(s21_lst2.front(), lst2.front());
    s21_lst2.pop();
    lst2.pop();
  }
}

TEST(Queue_Member_functions, move_constructor) {
  s21::queue<int> s21_lst1({1, 76, 234, 896});
  std::queue<int> lst1({1, 76, 234, 896});
  s21::queue<int> s21_lst2(std::move(s21_lst1));
  std::queue<int> lst2(std::move(lst1));
  ASSERT_EQ(s21_lst1.size(), lst1.size());
  ASSERT_EQ(s21_lst2.size(), lst2.size());
  while (s21_lst1.size() && lst1.size()) {
    ASSERT_EQ(s21_lst1.front(), lst1.front());
    s21_lst1.pop();
    lst1.pop();
  }
  while (s21_lst2.size() && lst2.size()) {
    ASSERT_EQ(s21_lst2.front(), lst2.front());
    s21_lst2.pop();
    lst2.pop();
  }
}

TEST(Queue_Member_functions, assignment_operator_overload) {
  s21::queue<int> s21_lst1({1, 76, 234, 896});
  std::queue<int> lst1({1, 76, 234, 896});
  s21::queue<int> s21_lst2(std::move(s21_lst1));
  std::queue<int> lst2(std::move(lst1));
  s21_lst1 = std::move(s21_lst2);
  lst1 = std::move(lst2);
  ASSERT_EQ(s21_lst1.size(), lst1.size());
  ASSERT_EQ(s21_lst2.size(), lst2.size());
  while (s21_lst1.size() && lst1.size()) {
    ASSERT_EQ(s21_lst1.front(), lst1.front());
    s21_lst1.pop();
    lst1.pop();
  }
  while (s21_lst2.size() && lst2.size()) {
    ASSERT_EQ(s21_lst2.front(), lst2.front());
    s21_lst2.pop();
    lst2.pop();
  }
}

TEST(Queue_Element_access, front_back) {
  s21::queue<int> s21_lst1({1, 76, 234, 896});
  std::queue<int> lst1({1, 76, 234, 896});
  ASSERT_EQ(s21_lst1.back(), lst1.back());
  ASSERT_EQ(s21_lst1.front(), lst1.front());
}

TEST(Queue_Capacity, empty) {
  s21::queue<int> s21_lst1({1, 76, 234, 896});
  s21::queue<int> s21_lst2;
  ASSERT_EQ(s21_lst1.empty(), false);
  ASSERT_EQ(s21_lst2.empty(), true);
}

TEST(Queue_Capacity, size) {
  s21::queue<int> s21_lst1({1, 76, 234, 896});
  s21::queue<int> s21_lst2;
  ASSERT_EQ(s21_lst1.size(), 4);
  ASSERT_EQ(s21_lst2.size(), 0);
}

TEST(Queue_Modifiers, push) {
  s21::queue<int> s21_lst({1, 76, 234, 896});
  std::queue<int> lst({1, 76, 234, 896});
  ASSERT_EQ(s21_lst.size(), lst.size());
  lst.push(6744);
  s21_lst.push(6744);
  ASSERT_EQ(s21_lst.size(), lst.size());
  while (s21_lst.size() && lst.size()) {
    ASSERT_EQ(s21_lst.front(), lst.front());
    s21_lst.pop();
    lst.pop();
  }
}

TEST(Queue_Modifiers, pop) {
  s21::queue<int> s21_lst({1, 76, 234, 896});
  std::queue<int> lst({1, 76, 234, 896});
  ASSERT_EQ(s21_lst.size(), lst.size());
  lst.pop();
  s21_lst.pop();
  ASSERT_EQ(s21_lst.size(), lst.size());
  while (s21_lst.size() && lst.size()) {
    ASSERT_EQ(s21_lst.front(), lst.front());
    s21_lst.pop();
    lst.pop();
  }
}

TEST(Queue_Modifiers, swap) {
  s21::queue<int> s21_lst1({1, 76, 234, 896});
  std::queue<int> lst1({1, 76, 234, 896});
  s21::queue<int> s21_lst2(std::move(s21_lst1));
  std::queue<int> lst2(std::move(lst1));
  s21_lst1.swap(s21_lst2);
  lst1.swap(lst2);
  ASSERT_EQ(s21_lst1.size(), lst1.size());
  ASSERT_EQ(s21_lst2.size(), lst2.size());
  while (s21_lst1.size() && lst1.size()) {
    ASSERT_EQ(s21_lst1.front(), lst1.front());
    s21_lst1.pop();
    lst1.pop();
  }
  while (s21_lst2.size() && lst2.size()) {
    ASSERT_EQ(s21_lst2.front(), lst2.front());
    s21_lst2.pop();
    lst2.pop();
  }
}
