#include <gtest/gtest.h>

#include <stack>
#include <string>

#include "../headers/s21_list.h"
#include "../headers/s21_stack.h"

TEST(stack_contructor, without_parameter) {
  s21::stack<int> t;
  std::stack<int> orig;
  ASSERT_EQ(t.size(), orig.size());
  ASSERT_EQ(t.empty(), orig.empty());
}

TEST(stack_contructor, initializated_with_list) {
  s21::stack<int> t{0, 15, 25, 35};
  std::stack<int> orig;
  orig.push(0);
  orig.push(15);
  orig.push(25);
  orig.push(35);
  ASSERT_EQ(t.size(), orig.size());
  ASSERT_EQ(t.empty(), orig.empty());
  ASSERT_EQ(t.top(), orig.top());
}

TEST(stack_contructor, copy) {
  s21::stack<int> t1{0, 15, 25, 35};
  s21::stack<int> t2(t1);
  std::stack<int> orig1;
  orig1.push(0);
  orig1.push(15);
  orig1.push(25);
  orig1.push(35);
  std::stack<int> orig2(orig1);

  ASSERT_EQ(t1.size(), orig1.size());
  ASSERT_EQ(t1.top(), orig1.top());

  ASSERT_EQ(t2.size(), orig2.size());
  ASSERT_EQ(t2.top(), orig2.top());
}

TEST(stack_contructor, move) {
  s21::stack<int> t1{0, 15, 25, 35};
  s21::stack<int> t2(std::move(t1));
  std::stack<int> orig1;
  orig1.push(0);
  orig1.push(15);
  orig1.push(25);
  orig1.push(35);
  std::stack<int> orig2(std::move(orig1));
  ASSERT_EQ(t2.size(), orig2.size());
  ASSERT_EQ(t2.top(), orig2.top());
}

TEST(stack_operator, copy) {
  s21::stack<int> t1{0, 15, 25, 35};
  s21::stack<int> t2 = t1;
  std::stack<int> orig1;
  orig1.push(0);
  orig1.push(15);
  orig1.push(25);
  orig1.push(35);
  std::stack<int> orig2 = orig1;
  ASSERT_EQ(t1.size(), orig1.size());
  ASSERT_EQ(t1.top(), orig1.top());

  ASSERT_EQ(t2.size(), orig2.size());
  ASSERT_EQ(t2.top(), orig2.top());
}

TEST(stack_operator, move) {
  s21::stack<int> t1{0, 15, 25, 35};
  s21::stack<int> t2 = std::move(t1);
  std::stack<int> orig1;
  orig1.push(0);
  orig1.push(15);
  orig1.push(25);
  orig1.push(35);
  std::stack<int> orig2 = std::move(orig1);
  ASSERT_EQ(t2.size(), orig2.size());
  ASSERT_EQ(t2.top(), orig2.top());
}

TEST(stack_push, subtest_1) {
  s21::stack<int> t{0, 15, 25, 35};
  ASSERT_EQ(t.top(), 35);
  t.push(17);
  ASSERT_EQ(t.top(), 17);
}

TEST(stack_pop, subtest_1) {
  s21::stack<int> t{0, 15, 25, 35};
  std::stack<int> orig;
  orig.push(0);
  orig.push(15);
  orig.push(25);
  orig.push(35);
  ASSERT_EQ(t.top(), orig.top());
  t.pop();
  orig.pop();
  ASSERT_EQ(t.top(), orig.top());
}

TEST(stack_swap, subtest_1) {
  s21::stack<int> t1{0, 15, 25, 35};
  s21::stack<int> t2{17, 27, 37};
  t1.swap(t2);
  std::stack<int> orig1;
  orig1.push(0);
  orig1.push(15);
  orig1.push(25);
  orig1.push(35);
  std::stack<int> orig2;
  orig2.push(17);
  orig2.push(27);
  orig2.push(37);
  orig1.swap(orig2);
  ASSERT_EQ(t1.size(), orig1.size());
  ASSERT_EQ(t1.top(), orig1.top());
  ASSERT_EQ(t2.size(), orig2.size());
  ASSERT_EQ(t2.top(), orig2.top());
}

TEST(stack_insert_many_front, one_arg) {
  s21::stack<int> t{0, 15, 25, 35};
  ASSERT_EQ(t.size(), 4);
  ASSERT_EQ(t.top(), 35);
  t.insert_many_front(1);
  ASSERT_EQ(t.size(), 5);
  ASSERT_EQ(t.top(), 1);
}

TEST(stack_insert_many_front, five_args) {
  s21::stack<int> t{0, 15, 25, 35};
  ASSERT_EQ(t.size(), 4);
  ASSERT_EQ(t.top(), 35);
  t.insert_many_front(1, 2, 3, 4, 5);
  ASSERT_EQ(t.size(), 9);
  ASSERT_EQ(t.top(), 5);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}