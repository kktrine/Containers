#include <gtest/gtest.h>

#include <array>
#include <string>

#include "../headers/s21_array.h"

TEST(array_contructor, without_parameter) {
  s21::array<int, 4> t;
  ASSERT_EQ(t.size(), 4);
  ASSERT_EQ(t[0], 0);
}

TEST(array_contructor, initializated_with_list) {
  s21::array<int, 4> t{0, 15, 25, 35};
  std::array<int, 4> orig{0, 15, 25, 35};
  ASSERT_EQ(t.size(), orig.size());
  ASSERT_EQ(t.empty(), orig.empty());
  ASSERT_EQ(t[0], orig[0]);
  ASSERT_EQ(t[2], orig[2]);
}

TEST(array_set, subtest_1) {
  s21::array<int, 4> t = {0, 15, 25, 35};
  std::array<int, 4> orig = {0, 15, 25, 35};
  ASSERT_EQ(t.size(), orig.size());
  t[2] = 7;
  orig[2] = 7;
  ASSERT_EQ(t[2], orig[2]);
}

TEST(array_contructor, copy) {
  s21::array<int, 4> t1 = {0, 15, 25, 35};
  std::array<int, 4> orig1 = {0, 15, 25, 35};
  s21::array<int, 4> t2(t1);
  std::array<int, 4> orig2(orig1);
  ASSERT_EQ(t1.size(), orig1.size());
  ASSERT_EQ(t1.empty(), orig1.empty());

  ASSERT_EQ(t2.size(), orig2.size());
  ASSERT_EQ(t2.empty(), orig2.empty());

  ASSERT_EQ(t2[0], orig2[0]);
  ASSERT_EQ(t2[2], orig2[2]);
}

TEST(array_contructor, move) {
  s21::array<int, 4> t1 = {0, 15, 25, 35};
  std::array<int, 4> orig1 = {0, 15, 25, 35};
  s21::array<int, 4> t2(std::move(t1));
  std::array<int, 4> orig2(std::move(orig1));
  ASSERT_EQ(t1.size(), orig1.size());
  ASSERT_EQ(t1.empty(), orig1.empty());

  ASSERT_EQ(t2.size(), orig2.size());
  ASSERT_EQ(t2.empty(), orig2.empty());

  ASSERT_EQ(t2[0], orig2[0]);
  ASSERT_EQ(t2[2], orig2[2]);
}

TEST(array_operator, copy_1) {
  s21::array<int, 4> t1 = {0, 15, 25, 35};
  std::array<int, 4> orig1 = {0, 15, 25, 35};
  s21::array<int, 4> t2 = t1;
  std::array<int, 4> orig2 = orig1;
  ASSERT_EQ(t1.size(), orig1.size());
  ASSERT_EQ(t1.empty(), orig1.empty());

  ASSERT_EQ(t2.size(), orig2.size());
  ASSERT_EQ(t2.empty(), orig2.empty());

  ASSERT_EQ(t2[0], orig2[0]);
  ASSERT_EQ(t2[2], orig2[2]);
}

TEST(array_operator, copy_2) {
  s21::array<int, 4> t1 = {0, 15, 25, 35};
  std::array<int, 4> orig1 = {0, 15, 25, 35};
  s21::array<int, 4> t2;
  t2 = t1;
  std::array<int, 4> orig2;
  orig2 = orig1;
  ASSERT_EQ(t1.size(), orig1.size());
  ASSERT_EQ(t1.empty(), orig1.empty());

  ASSERT_EQ(t2.size(), orig2.size());
  ASSERT_EQ(t2.empty(), orig2.empty());

  ASSERT_EQ(t2[0], orig2[0]);
  ASSERT_EQ(t2[2], orig2[2]);
}

TEST(array_operator, move_1) {
  s21::array<int, 4> t1 = {0, 15, 25, 35};
  std::array<int, 4> orig1 = {0, 15, 25, 35};
  s21::array<int, 4> t2 = std::move(t1);
  std::array<int, 4> orig2 = std::move(orig1);
  ASSERT_EQ(t1.size(), orig1.size());
  ASSERT_EQ(t1.empty(), orig1.empty());

  ASSERT_EQ(t2.size(), orig2.size());
  ASSERT_EQ(t2.empty(), orig2.empty());

  ASSERT_EQ(t2[0], orig2[0]);
  ASSERT_EQ(t2[2], orig2[2]);
}

TEST(array_operator, move_2) {
  s21::array<int, 4> t1 = {0, 15, 25, 35};
  std::array<int, 4> orig1 = {0, 15, 25, 35};
  s21::array<int, 4> t2;
  t2 = std::move(t1);
  std::array<int, 4> orig2;
  orig2 = std::move(orig1);
  ASSERT_EQ(t1.size(), orig1.size());
  ASSERT_EQ(t1.empty(), orig1.empty());

  ASSERT_EQ(t2.size(), orig2.size());
  ASSERT_EQ(t2.empty(), orig2.empty());

  ASSERT_EQ(t2[0], orig2[0]);
  ASSERT_EQ(t2[2], orig2[2]);
}

TEST(array_at, correct_int) {
  s21::array<int, 4> t = {0, 15, 25, 35};
  std::array<int, 4> orig = {0, 15, 25, 35};
  ASSERT_EQ(t.at(0), orig.at(0));
  ASSERT_EQ(t.at(1), orig.at(1));
  ASSERT_EQ(t.at(2), orig.at(2));
  ASSERT_EQ(t.at(3), orig.at(3));
}

TEST(array_at, correct_string) {
  s21::array<std::string, 4> t = {"0", "15", "25", "35"};
  std::array<std::string, 4> orig = {"0", "15", "25", "35"};
  ASSERT_EQ(t.at(0), orig.at(0));
  ASSERT_EQ(t.at(1), orig.at(1));
  ASSERT_EQ(t.at(2), orig.at(2));
  ASSERT_EQ(t.at(3), orig.at(3));
}

TEST(array_at, exception) {
  s21::array<int, 4> t = {0, 15, 25, 35};
  std::array<int, 4> orig = {0, 15, 25, 35};
  EXPECT_THROW(t.at(7), std::out_of_range);
  EXPECT_THROW(orig.at(7), std::out_of_range);
}

TEST(array_front, front) {
  s21::array<int, 4> t = {0, 15, 25, 35};
  std::array<int, 4> orig = {0, 15, 25, 35};
  ASSERT_EQ(t.at(0), t.front());
  ASSERT_EQ(t.front(), orig.front());
}

TEST(array_back, back) {
  s21::array<int, 4> t = {0, 15, 25, 35};
  std::array<int, 4> orig = {0, 15, 25, 35};
  ASSERT_EQ(t.at(3), t.back());
  ASSERT_EQ(t.back(), orig.back());
}

TEST(array_iterator, data) {
  s21::array<std::string, 4> t{"0", "15", "25", "35"};
  std::array<std::string, 4> orig{"0", "15", "25", "35"};
  std::string* p_t = t.data();
  std::string* p_orig = orig.data();
  ASSERT_EQ(*p_t, *p_orig);
}

TEST(array_iterator, begin) {
  s21::array<int, 4> t = {0, 15, 25, 35};
  std::array<int, 4> orig = {0, 15, 25, 35};
  s21::array<int, 4>::iterator it_t = t.begin();
  std::array<int, 4>::iterator it_orig = orig.begin();
  ASSERT_EQ(*it_t, *it_orig);
}

TEST(array_iterator, end) {
  s21::array<int, 4> t = {0, 15, 25, 35};
  std::array<int, 4> orig = {0, 15, 25, 35};
  s21::array<int, 4>::iterator it_t = t.end();
  std::array<int, 4>::iterator it_orig = orig.end();
  ASSERT_EQ(*(it_t - 1), *(it_orig - 1));
}

TEST(array_max_size, max_size) {
  s21::array<int, 8> t = {0, 15, 25, 35, 17, 27, 37, 47};
  std::array<int, 8> orig = {0, 15, 25, 35, 17, 27, 37, 47};
  ASSERT_EQ(t.max_size(), orig.max_size());
}

TEST(array_swap, swap) {
  s21::array<int, 4> t1 = {0, 15, 25, 35};
  s21::array<int, 4> t2 = {17, 27, 37, 47};
  std::array<int, 4> orig1 = {0, 15, 25, 35};
  std::array<int, 4> orig2 = {17, 27, 37, 47};
  t1.swap(t2);
  orig1.swap(orig2);
  ASSERT_EQ(t1.size(), orig1.size());
  ASSERT_EQ(t2.size(), orig2.size());
  ASSERT_EQ(t1.at(0), orig1.at(0));
  ASSERT_EQ(t1.at(1), orig1.at(1));
  ASSERT_EQ(t1.at(3), orig1.at(3));
  ASSERT_EQ(t2.at(0), orig2.at(0));
  ASSERT_EQ(t2.at(1), orig2.at(1));
  ASSERT_EQ(t2.at(2), orig2.at(2));
  ASSERT_EQ(t2.at(3), orig2.at(3));
}

TEST(array_fill, fill) {
  s21::array<int, 4> t = {0, 15, 25, 35};
  std::array<int, 4> orig = {0, 15, 25, 35};
  t.fill(111);
  orig.fill(111);
  ASSERT_EQ(t.at(0), 111);
  ASSERT_EQ(t.at(1), 111);
  ASSERT_EQ(t.at(2), 111);
  ASSERT_EQ(t.at(3), 111);
  ASSERT_EQ(t.at(0), orig.at(0));
  ASSERT_EQ(t.at(1), orig.at(1));
  ASSERT_EQ(t.at(2), orig.at(2));
  ASSERT_EQ(t.at(3), orig.at(3));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
