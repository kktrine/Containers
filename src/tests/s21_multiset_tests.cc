#include <set>

#include "../headers/s21_multiset.h"
#include "../source/RedBlackTreeOperations.cc"
#include "gtest/gtest.h"

using s21::multiset;

TEST(Multiset, capacity) {
  multiset<double> v = {-3, 1, -5, 42, 2, -6, 8, 20, 1, 1, 20};
  std::multiset<double> vc = {-3, 1, -5, 42, 2, -6, 8, 20, 1, 1, 20};

  ASSERT_EQ(*v.begin(), *vc.begin());
  ASSERT_EQ(v.empty(), vc.empty());
  ASSERT_EQ(v.size(), vc.size());
}

TEST(Multiset, iterators) {
  multiset<double> v = {-3, 1, -5, 42, 2, -6, 8, 20, 1, 1, 20};
  std::multiset<double> vc = {-3, 1, -5, 42, 2, -6, 8, 20, 1, 1, 20};
  auto x = v.begin();
  auto y = vc.begin();

  for (; x != v.end(); ++x, ++y) {
    ASSERT_EQ(*x, *y);
  }
}

TEST(Multiset, iterators2) {
  multiset<double> v;
  std::multiset<double> vc;
  auto x = v.begin();
  auto y = vc.begin();
  for (; x != v.end(); ++x, ++y) {
    ASSERT_EQ(*x, *y);
  }
}

TEST(Multiset, insert_erase) {
  multiset<double> v = {2, -3, 20, -5, 1, -6, 8, 42, 26, 1, 1, 1, 8, 8, 8};
  std::multiset<double> vc = {2,  -3, 20, -5, 1, -6, 8, 42,
                              26, 1,  1,  1,  8, 8,  8};
  v.insert(15);
  vc.insert(15);
  v.erase(v.begin());
  vc.erase(vc.begin());
  auto x = v.begin();
  auto y = vc.begin();
  for (; x != v.end(); ++x, ++y) {
    ASSERT_EQ(*x, *y);
  }
}

TEST(Multiset, swap) {
  multiset<double> v = {-3, 1, -5, 42, 2, -6, 8, 20, 26};
  std::multiset<double> vc = {-3, 1, -5, 42, 2, -6, 8, 20, 26};
  multiset<double> v1 = {100, 200, 300, 400, 500};
  std::multiset<double> vc1 = {100, 200, 300, 400, 500};
  v.swap(v1);
  vc.swap(vc1);

  auto x = v.begin();
  auto y = vc.begin();
  for (; x != v.end(); ++x, ++y) {
    ASSERT_EQ(*x, *y);
  }
}

TEST(Multiset, merge) {
  multiset<double> v = {-3, 1, -5, 42, 2, -6, 8, 20, 26};
  multiset<double> v1 = {100, 200, 300, 400, 500};
  multiset<double> vc = {-3, 1,  -5,  42,  2,   -6,  8,
                         20, 26, 100, 200, 300, 400, 500};
  v.merge(v1);

  auto x = v.begin();
  auto y = vc.begin();
  for (; x != v.end(); ++x, ++y) {
    ASSERT_EQ(*x, *y);
  }
}

TEST(Multiset, find) {
  multiset<double> v = {-3, 1, -5, 42, 2, -6, 8, 20, 26};
  std::multiset<double> vc = {-3, 1, -5, 42, 2, -6, 8, 20, 26};

  ASSERT_EQ(*v.find(20), *vc.find(20));
}

TEST(Multiset, contains) {
  multiset<double> v = {-3, 1, -5, 42, 2, -6, 8, 20, 26};

  ASSERT_EQ(v.contains(100), false);
}

TEST(Multiset, lower_bound) {
  multiset<double> v = {2, -3, 20, -5, 1, -6, 8, 42, 26, 1, 1, 1};
  multiset<double>::iterator x = v.lower_bound(8);
  ASSERT_EQ(*x, 8);
}

TEST(Multiset, upper_bound1) {
  multiset<double> v = {2, -3, 20, -5, 1, -6, 8, 42, 26, 1, 1, 1, 8, 8, 8};
  auto x = v.upper_bound(8);
  ASSERT_EQ(*x, 20);
}

TEST(Multiset, equal_range) {
  multiset<double> v = {2, -3, 20, -5, 1, -6, 8, 42, 26, 1, 1, 1, 8, 8, 8};
  auto x = v.equal_range(8);
  ASSERT_EQ(*x.first, 8);
  ASSERT_EQ(*x.second, 20);
}

TEST(Multiset, count) {
  multiset<double> v = {2, -3, 20, -5, 1, -6, 8, 42, 26, 1, 1, 1, 8, 8, 8};
  size_t x = v.count(1);
  ASSERT_EQ(x, 4);
}

TEST(Multiset, upper_bound2) {
  multiset<double> v = {2, -3, 20, -5, 1, -6, 8, 42, 26, 1, 1, 1, 8, 8, 8};
  auto x = v.upper_bound(22);
  ASSERT_EQ(*x, 26);
}

TEST(Multiset, insert_many) {
  multiset<int> m1 = {1};
  m1.insert_many(2, 3, 4, 5);
  EXPECT_EQ(m1.size(), 5);
}

TEST(Multiset, copy_constructor) {
  std::multiset<int> std_copy_set{0, 1, 2};
  std::multiset<int> std_set = std_copy_set;

  multiset<int> s21_copy_set{0, 1, 2};
  multiset<int> s21_set = s21_copy_set;

  EXPECT_EQ(std_set.size(), s21_set.size());
}

TEST(Multiset, move_constructor) {
  std::multiset<int> std_moving_set{0, 1, 2};
  std::multiset<int> std_set = std::move(std_moving_set);

  multiset<int> s21_moving_set{0, 1, 2};
  multiset<int> s21_set = std::move(s21_moving_set);

  EXPECT_EQ(std_moving_set.size(), s21_moving_set.size());
  EXPECT_EQ(std_set.size(), s21_set.size());

  // // перемещение пустого словаря
  std::multiset<int> std_null_set;
  std::multiset<int> std_set_2 = std::move(std_moving_set);

  multiset<int> s21_null_set;
  multiset<int> s21_set_2 = std::move(s21_moving_set);

  EXPECT_EQ(std_null_set.size(), s21_null_set.size());
  EXPECT_EQ(std_set_2.size(), s21_set_2.size());
}

TEST(Multiset, operator_assignment_copy) {
  multiset<int> s21_set_1 = {4};
  multiset<int> s21_set_2 = {5, 7};
  s21_set_1 = s21_set_2;

  EXPECT_EQ(s21_set_1.size(), 2);
  EXPECT_EQ(2, s21_set_2.size());
}

TEST(Multiset, operator_assignment_move) {
  multiset<int> s21_set_1 = {4};
  multiset<int> s21_set_2 = {5, 7};
  s21_set_1 = std::move(s21_set_2);

  EXPECT_EQ(s21_set_1.size(), 2);
  EXPECT_EQ(0, s21_set_2.size());
}

// int main(int argc, char **argv) {
//   testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }