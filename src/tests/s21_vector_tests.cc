#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "../headers/s21_vector.h"

TEST(vector_contructor, without_parameter) {
  s21::vector<std::string> t;
  std::vector<std::string> orig;
  ASSERT_EQ(t.size(), orig.size());
  ASSERT_EQ(t.capacity(), orig.capacity());
  ASSERT_EQ(t.empty(), orig.empty());
}

TEST(vector_contructor, with_parameter) {
  s21::vector<std::string> t(15);
  std::vector<std::string> orig(15);
  ASSERT_EQ(t.size(), orig.size());
  ASSERT_EQ(t.capacity(), orig.capacity());
  ASSERT_EQ(t.empty(), orig.empty());
  ASSERT_EQ(t[0], orig[0]);
  ASSERT_EQ(t[2], orig[2]);
}

TEST(vector_contructor, initializated_with_list_int) {
  s21::vector<int> t{0, 15, 25, 35};
  std::vector<int> orig{0, 15, 25, 35};
  ASSERT_EQ(t.size(), orig.size());
  ASSERT_EQ(t.capacity(), orig.capacity());
  ASSERT_EQ(t.empty(), orig.empty());
  ASSERT_EQ(t[0], orig[0]);
  ASSERT_EQ(t[2], orig[2]);
}

TEST(vector_contructor, initializated_with_list_string) {
  s21::vector<std::string> t{"0", "15", "25", "35"};
  std::vector<std::string> orig{"0", "15", "25", "35"};
  ASSERT_EQ(t.size(), orig.size());
  ASSERT_EQ(t.capacity(), orig.capacity());
  ASSERT_EQ(t.empty(), orig.empty());
  ASSERT_EQ(t[0], orig[0]);
  ASSERT_EQ(t[2], orig[2]);
}

TEST(vector_set, subtest_1) {
  s21::vector<int> t(4);
  std::vector<int> orig(4);
  t[2] = 25;
  orig[2] = 25;
  ASSERT_EQ(t[2], orig[2]);
}

TEST(vector_contructor, copy) {
  s21::vector<std::string> t1{"0", "15", "25", "35"};
  std::vector<std::string> orig1{"0", "15", "25", "35"};
  s21::vector<std::string> t2(t1);
  std::vector<std::string> orig2(orig1);

  ASSERT_EQ(t1.size(), orig1.size());
  ASSERT_EQ(t1.capacity(), orig1.capacity());
  ASSERT_EQ(t1.empty(), orig1.empty());

  ASSERT_EQ(t2.size(), orig2.size());
  ASSERT_EQ(t2.capacity(), orig2.capacity());
  ASSERT_EQ(t2.empty(), orig2.empty());

  ASSERT_EQ(t2[0], orig2[0]);
  ASSERT_EQ(t2[2], orig2[2]);
}

TEST(vector_contructor, move) {
  s21::vector<std::string> t1{"0", "15", "25", "35"};
  std::vector<std::string> orig1{"0", "15", "25", "35"};
  s21::vector<std::string> t2(std::move(t1));
  std::vector<std::string> orig2(std::move(orig1));

  ASSERT_EQ(t1.size(), orig1.size());
  ASSERT_EQ(t1.capacity(), orig1.capacity());
  ASSERT_EQ(t1.empty(), orig1.empty());

  ASSERT_EQ(t2.size(), orig2.size());
  ASSERT_EQ(t2.capacity(), orig2.capacity());
  ASSERT_EQ(t2.empty(), orig2.empty());

  ASSERT_EQ(t2[0], orig2[0]);
  ASSERT_EQ(t2[2], orig2[2]);
}

TEST(vector_operator, copy_1) {
  s21::vector<std::string> t1{"0", "15", "25", "35"};
  std::vector<std::string> orig1{"0", "15", "25", "35"};
  s21::vector<std::string> t2 = t1;
  std::vector<std::string> orig2 = orig1;

  ASSERT_EQ(t1.size(), orig1.size());
  ASSERT_EQ(t1.capacity(), orig1.capacity());
  ASSERT_EQ(t1.empty(), orig1.empty());

  ASSERT_EQ(t2.size(), orig2.size());
  ASSERT_EQ(t2.capacity(), orig2.capacity());
  ASSERT_EQ(t2.empty(), orig2.empty());

  ASSERT_EQ(t2[0], orig2[0]);
  ASSERT_EQ(t2[2], orig2[2]);
}

TEST(vector_operator, copy_2) {
  s21::vector<std::string> t1{"0", "15", "25", "35"};
  std::vector<std::string> orig1{"0", "15", "25", "35"};
  s21::vector<std::string> t2;
  t2 = t1;
  std::vector<std::string> orig2;
  orig2 = orig1;

  ASSERT_EQ(t1.size(), orig1.size());
  ASSERT_EQ(t1.capacity(), orig1.capacity());
  ASSERT_EQ(t1.empty(), orig1.empty());

  ASSERT_EQ(t2.size(), orig2.size());
  ASSERT_EQ(t2.capacity(), orig2.capacity());
  ASSERT_EQ(t2.empty(), orig2.empty());

  ASSERT_EQ(t2[0], orig2[0]);
  ASSERT_EQ(t2[2], orig2[2]);
}

TEST(vector_operator, copy_3) {
  s21::vector<std::string> t1{"0", "15", "25", "35"};
  std::vector<std::string> orig1{"0", "15", "25", "35"};
  s21::vector<std::string> t2(2);
  t2 = t1;
  std::vector<std::string> orig2(2);
  orig2 = orig1;

  ASSERT_EQ(t1.size(), orig1.size());
  ASSERT_EQ(t1.capacity(), orig1.capacity());
  ASSERT_EQ(t1.empty(), orig1.empty());

  ASSERT_EQ(t2.size(), orig2.size());
  ASSERT_EQ(t2.capacity(), orig2.capacity());
  ASSERT_EQ(t2.empty(), orig2.empty());

  ASSERT_EQ(t2[0], orig2[0]);
  ASSERT_EQ(t2[2], orig2[2]);
}

TEST(vector_operator, copy_4) {
  s21::vector<std::string> t1{"0", "15", "25", "35"};
  std::vector<std::string> orig1{"0", "15", "25", "35"};
  t1 = t1;
  orig1 = orig1;
  ASSERT_EQ(t1.size(), orig1.size());
  ASSERT_EQ(t1.capacity(), orig1.capacity());
  ASSERT_EQ(t1.empty(), orig1.empty());
}

TEST(vector_operator, move_1) {
  s21::vector<std::string> t1{"0", "15", "25", "35"};
  std::vector<std::string> orig1{"0", "15", "25", "35"};
  s21::vector<std::string> t2 = std::move(t1);
  std::vector<std::string> orig2 = std::move(orig1);

  ASSERT_EQ(t1.size(), orig1.size());
  ASSERT_EQ(t1.capacity(), orig1.capacity());
  ASSERT_EQ(t1.empty(), orig1.empty());

  ASSERT_EQ(t2.size(), orig2.size());
  ASSERT_EQ(t2.capacity(), orig2.capacity());
  ASSERT_EQ(t2.empty(), orig2.empty());

  ASSERT_EQ(t2[0], orig2[0]);
  ASSERT_EQ(t2[2], orig2[2]);
}

TEST(vector_operator, move_2) {
  s21::vector<std::string> t1{"0", "15", "25", "35"};
  std::vector<std::string> orig1{"0", "15", "25", "35"};
  s21::vector<std::string> t2;
  t2 = std::move(t1);
  std::vector<std::string> orig2;
  orig2 = std::move(orig1);

  ASSERT_EQ(t1.size(), orig1.size());
  ASSERT_EQ(t1.capacity(), orig1.capacity());
  ASSERT_EQ(t1.empty(), orig1.empty());

  ASSERT_EQ(t2.size(), orig2.size());
  ASSERT_EQ(t2.capacity(), orig2.capacity());
  ASSERT_EQ(t2.empty(), orig2.empty());

  ASSERT_EQ(t2[0], orig2[0]);
  ASSERT_EQ(t2[2], orig2[2]);
}

TEST(vector_operator, move_3) {
  s21::vector<std::string> t1{"0", "15", "25", "35"};
  std::vector<std::string> orig1{"0", "15", "25", "35"};
  s21::vector<std::string> t2(3);
  t2 = std::move(t1);
  std::vector<std::string> orig2(3);
  orig2 = std::move(orig1);

  ASSERT_EQ(t1.size(), orig1.size());
  ASSERT_EQ(t1.capacity(), orig1.capacity());
  ASSERT_EQ(t1.empty(), orig1.empty());

  ASSERT_EQ(t2.size(), orig2.size());
  ASSERT_EQ(t2.capacity(), orig2.capacity());
  ASSERT_EQ(t2.empty(), orig2.empty());

  ASSERT_EQ(t2[0], orig2[0]);
  ASSERT_EQ(t2[2], orig2[2]);
}

TEST(vector_operator, move_4) {
  s21::vector<std::string> t1{"0", "15", "25", "35"};
  std::vector<std::string> orig1{"0", "15", "25", "35"};
  t1 = std::move(t1);
  orig1 = std::move(orig1);
  ASSERT_EQ(t1.size(), orig1.size());
  ASSERT_EQ(t1.capacity(), orig1.capacity());
  ASSERT_EQ(t1.empty(), orig1.empty());
}

TEST(vector_at, correct_int) {
  s21::vector<int> t = {0, 15, 25, 35};
  std::vector<int> orig = {0, 15, 25, 35};
  ASSERT_EQ(t.at(0), orig.at(0));
  ASSERT_EQ(t.at(1), orig.at(1));
  ASSERT_EQ(t.at(2), orig.at(2));
  ASSERT_EQ(t.at(3), orig.at(3));
}

TEST(vector_at, correct_string) {
  s21::vector<std::string> t{"0", "15", "25", "35"};
  std::vector<std::string> orig{"0", "15", "25", "35"};
  ASSERT_EQ(t.at(0), orig.at(0));
  ASSERT_EQ(t.at(1), orig.at(1));
  ASSERT_EQ(t.at(2), orig.at(2));
  ASSERT_EQ(t.at(3), orig.at(3));
}

TEST(vector_at, exception) {
  s21::vector<int> t = {0, 15, 25, 35};
  std::vector<int> orig = {0, 15, 25, 35};
  EXPECT_THROW(t.at(7), std::out_of_range);
  EXPECT_THROW(orig.at(7), std::out_of_range);
}

TEST(vector_front, front_int) {
  s21::vector<int> t = {0, 15, 25, 35};
  std::vector<int> orig = {0, 15, 25, 35};
  ASSERT_EQ(t.at(0), t.front());
  ASSERT_EQ(orig.at(0), orig.front());
}

TEST(vector_front, front_string) {
  s21::vector<std::string> t{"0", "15", "25", "35"};
  std::vector<std::string> orig{"0", "15", "25", "35"};
  ASSERT_EQ(t.at(0), t.front());
  ASSERT_EQ(orig.at(0), orig.front());
}

TEST(vector_back, back_int) {
  s21::vector<int> t = {0, 15, 25, 35};
  std::vector<int> orig = {0, 15, 25, 35};
  ASSERT_EQ(t.at(t.size() - 1), t.back());
  ASSERT_EQ(orig.at(orig.size() - 1), orig.back());
}

TEST(vector_back, back_string) {
  s21::vector<std::string> t{"0", "15", "25", "35"};
  std::vector<std::string> orig{"0", "15", "25", "35"};
  ASSERT_EQ(t.at(t.size() - 1), t.back());
  ASSERT_EQ(orig.at(orig.size() - 1), orig.back());
}

TEST(vector_reserve, new_capacity) {
  s21::vector<std::string> t{"0", "15", "25", "35"};
  std::vector<std::string> orig{"0", "15", "25", "35"};
  t.reserve(7);
  orig.reserve(7);
  ASSERT_EQ(t.size(), orig.size());
  ASSERT_EQ(t.capacity(), orig.capacity());
  ASSERT_EQ(t[0], orig[0]);
  ASSERT_EQ(t[3], orig[3]);
}

TEST(vector_reserve, old_capacity) {
  s21::vector<std::string> t{"0", "15", "25", "35"};
  std::vector<std::string> orig{"0", "15", "25", "35"};
  t.reserve(4);
  orig.reserve(4);
  ASSERT_EQ(t.size(), orig.size());
  ASSERT_EQ(t.capacity(), orig.capacity());
  ASSERT_EQ(t[3], orig[3]);
}

TEST(vector_reserve, exception) {
  s21::vector<int> t = {0, 15, 25, 35};
  std::vector<int> orig = {0, 15, 25, 35};
  EXPECT_THROW(t.reserve(t.max_size() + 1), std::length_error);
  EXPECT_THROW(orig.reserve(orig.max_size() + 1), std::length_error);
}

TEST(vector_shrink_to_fit, new_capacity) {
  s21::vector<int> t = {0, 15, 25, 35};
  std::vector<int> orig = {0, 15, 25, 35};
  t.reserve(5);
  orig.reserve(5);
  t.shrink_to_fit();
  ASSERT_EQ(t.size(), t.capacity());
  ASSERT_EQ(t.size(), orig.size());
}

TEST(vector_shrink_to_fit, old_capacity) {
  s21::vector<int> t = {0, 15, 25, 35};
  std::vector<int> orig = {0, 15, 25, 35};
  t.shrink_to_fit();
  ASSERT_EQ(t.size(), t.capacity());
  ASSERT_EQ(t.size(), orig.size());
}

TEST(vector_clear, clear) {
  s21::vector<int> t = {0, 15, 25, 35};
  std::vector<int> orig = {0, 15, 25, 35};
  t.clear();
  orig.clear();
  ASSERT_EQ(t.size(), 0);
  ASSERT_EQ(t.size(), orig.size());
  ASSERT_EQ(t.capacity(), orig.capacity());
}

TEST(vector_iterator, data) {
  s21::vector<std::string> t{"0", "15", "25", "35"};
  std::vector<std::string> orig{"0", "15", "25", "35"};
  std::string* p_t = t.data();
  std::string* p_orig = orig.data();
  ASSERT_EQ(*p_t, *p_orig);
}

TEST(vector_iterator, begin) {
  s21::vector<int> t = {0, 15, 25, 35};
  std::vector<int> orig = {0, 15, 25, 35};
  s21::vector<int>::iterator it_t = t.begin();
  std::vector<int>::iterator it_orig = orig.begin();
  ASSERT_EQ(*it_t, *it_orig);
}

TEST(vector_iterator, end) {
  s21::vector<int> t = {0, 15, 25, 35};
  std::vector<int> orig = {0, 15, 25, 35};
  s21::vector<int>::iterator it_t = t.end();
  std::vector<int>::iterator it_orig = orig.end();
  ASSERT_EQ(*(it_t - 1), *(it_orig - 1));
}

TEST(vector_insert, begin) {
  s21::vector<std::string> t{"0", "15", "25", "35"};
  std::vector<std::string> orig{"0", "15", "25", "35"};
  t.insert(t.begin(), "allo");
  orig.insert(orig.begin(), "allo");
  ASSERT_EQ(t.size(), orig.size());
  ASSERT_EQ(t.capacity(), orig.capacity());
  ASSERT_EQ(t.at(0), "allo");
  ASSERT_EQ(t.at(0), orig.at(0));
  ASSERT_EQ(t.at(1), orig.at(1));
  ASSERT_EQ(t.at(2), orig.at(2));
}

TEST(vector_insert, middle) {
  s21::vector<std::string> t{"0", "15", "25", "35"};
  std::vector<std::string> orig{"0", "15", "25", "35"};
  t.insert(t.begin() + 2, "allo");
  orig.insert(orig.begin() + 2, "allo");
  ASSERT_EQ(t.size(), orig.size());
  ASSERT_EQ(t.capacity(), orig.capacity());
  ASSERT_EQ(t.at(2), "allo");
  ASSERT_EQ(t.at(0), orig.at(0));
  ASSERT_EQ(t.at(1), orig.at(1));
  ASSERT_EQ(t.at(2), orig.at(2));
}

TEST(vector_insert, end) {
  s21::vector<std::string> t{"0", "15", "25", "35"};
  std::vector<std::string> orig{"0", "15", "25", "35"};
  t.insert(t.begin() + 3, "allo");
  orig.insert(orig.begin() + 3, "allo");
  ASSERT_EQ(t.size(), orig.size());
  ASSERT_EQ(t.capacity(), orig.capacity());
  ASSERT_EQ(t.at(3), "allo");
  ASSERT_EQ(t.at(0), orig.at(0));
  ASSERT_EQ(t.at(1), orig.at(1));
  ASSERT_EQ(t.at(3), orig.at(3));
}

TEST(vector_insert, end_without_extension) {
  s21::vector<std::string> t{"0", "15", "25", "35"};
  std::vector<std::string> orig{"0", "15", "25", "35"};
  t.reserve(7);
  orig.reserve(7);
  t.insert(t.begin() + 4, "allo");
  orig.insert(orig.begin() + 4, "allo");
  ASSERT_EQ(t.size(), orig.size());
  ASSERT_EQ(t.capacity(), orig.capacity());
  ASSERT_EQ(t.at(4), "allo");
  ASSERT_EQ(t.at(0), orig.at(0));
  ASSERT_EQ(t.at(1), orig.at(1));
  ASSERT_EQ(t.at(3), orig.at(3));
}

TEST(vector_insert, exception) {
  s21::vector<std::string> t{"0", "15", "25", "35"};
  EXPECT_THROW(t.insert(t.begin() + 7, "allo"), std::out_of_range);
}

TEST(vector_erase, begin) {
  s21::vector<int> t = {0, 15, 25, 35};
  std::vector<int> orig = {0, 15, 25, 35};
  t.erase(t.begin());
  orig.erase(orig.begin());
  ASSERT_EQ(t.size(), orig.size());
  ASSERT_EQ(t.capacity(), orig.capacity());
  ASSERT_EQ(t.at(0), orig.at(0));
  ASSERT_EQ(t.at(1), orig.at(1));
  ASSERT_EQ(t.at(2), orig.at(2));
}

TEST(vector_erase, middle) {
  s21::vector<int> t = {0, 15, 25, 35};
  std::vector<int> orig = {0, 15, 25, 35};
  t.erase(t.begin() + 2);
  orig.erase(orig.begin() + 2);
  ASSERT_EQ(t.size(), orig.size());
  ASSERT_EQ(t.capacity(), orig.capacity());
  ASSERT_EQ(t.at(0), orig.at(0));
  ASSERT_EQ(t.at(1), orig.at(1));
  ASSERT_EQ(t.at(2), orig.at(2));
}

TEST(vector_erase, end) {
  s21::vector<int> t = {0, 15, 25, 35};
  std::vector<int> orig = {0, 15, 25, 35};
  t.erase(t.begin() + 3);
  orig.erase(orig.begin() + 3);
  ASSERT_EQ(t.size(), orig.size());
  ASSERT_EQ(t.capacity(), orig.capacity());
  ASSERT_EQ(t.at(0), orig.at(0));
  ASSERT_EQ(t.at(1), orig.at(1));
  ASSERT_EQ(t.at(2), orig.at(2));
}

TEST(vector_erase, exception) {
  s21::vector<std::string> t{"0", "15", "25", "35"};
  EXPECT_THROW(t.erase(t.begin() + 7), std::out_of_range);
}

TEST(vector_push, push) {
  s21::vector<int> t = {0, 15, 25, 35};
  std::vector<int> orig = {0, 15, 25, 35};
  t.push_back(8);
  orig.push_back(8);
  ASSERT_EQ(t.size(), orig.size());
  ASSERT_EQ(t.capacity(), orig.capacity());
  ASSERT_EQ(t.at(0), orig.at(0));
  ASSERT_EQ(t.at(1), orig.at(1));
  ASSERT_EQ(t.at(2), orig.at(2));
  ASSERT_EQ(t.at(3), orig.at(3));
  ASSERT_EQ(t.at(4), orig.at(4));
}

TEST(vector_pop, pop) {
  s21::vector<int> t = {0, 15, 25, 35};
  std::vector<int> orig = {0, 15, 25, 35};
  t.pop_back();
  orig.pop_back();
  ASSERT_EQ(t.size(), orig.size());
  ASSERT_EQ(t.capacity(), orig.capacity());
  ASSERT_EQ(t.at(0), orig.at(0));
  ASSERT_EQ(t.at(1), orig.at(1));
  ASSERT_EQ(t.at(2), orig.at(2));
}

TEST(vector_swap, swap) {
  s21::vector<int> t1 = {0, 15, 25, 35};
  s21::vector<int> t2 = {17, 27, 37, 47, 57};
  t1.swap(t2);
  std::vector<int> orig1 = {0, 15, 25, 35};
  std::vector<int> orig2 = {17, 27, 37, 47, 57};
  orig1.swap(orig2);
  ASSERT_EQ(t1.size(), orig1.size());
  ASSERT_EQ(t1.capacity(), orig1.capacity());
  ASSERT_EQ(t2.size(), orig2.size());
  ASSERT_EQ(t2.capacity(), orig2.capacity());
  ASSERT_EQ(t1.at(0), orig1.at(0));
  ASSERT_EQ(t1.at(1), orig1.at(1));
  ASSERT_EQ(t1.at(4), orig1.at(4));
  ASSERT_EQ(t2.at(0), orig2.at(0));
  ASSERT_EQ(t2.at(1), orig2.at(1));
  ASSERT_EQ(t2.at(2), orig2.at(2));
  ASSERT_EQ(t2.at(3), orig2.at(3));
}

TEST(vector_insert_many, begin) {
  s21::vector<int> t = {0, 15, 25, 35};
  std::vector<int> orig = {10, 100, 1000, 1000, 0, 15, 25, 35};

  s21::vector<int>::iterator it_t =
      t.insert_many(t.begin(), 10, 100, 1000, 1000);
  std::vector<int>::iterator it_orig = orig.begin();

  auto j = t.begin();
  for (auto i = orig.begin(); i != orig.end() && j != t.end();) {
    ASSERT_EQ(*i, *j);
    ++i;
    ++j;
  }
  ASSERT_EQ(*it_t, *it_orig);
}

TEST(vector_insert_many, middle) {
  s21::vector<int> t = {0, 15, 25, 35};
  std::vector<int> orig = {0, 10, 100, 1000, 1000, 15, 25, 35};

  s21::vector<int>::iterator it_t =
      t.insert_many(t.begin() + 1, 10, 100, 1000, 1000);
  std::vector<int>::iterator it_orig = orig.begin() + 1;

  auto j = t.begin();
  for (auto i = orig.begin(); i != orig.end() && j != t.end();) {
    ASSERT_EQ(*i, *j);
    ++i;
    ++j;
  }
  ASSERT_EQ(*it_t, *it_orig);
}

TEST(vector_insert_many_back, insert_many_back) {
  s21::vector<int> t = {0, 15, 25, 35};
  std::vector<int> orig = {0, 15, 25, 35, 10, 100, 1000, 1000};
  t.insert_many_back(10, 100, 1000, 1000);
  auto j = t.begin();
  for (auto i = orig.begin(); i != orig.end() && j != t.end();) {
    ASSERT_EQ(*i, *j);
    ++i;
    ++j;
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}