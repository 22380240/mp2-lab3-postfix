#include "stack.h"
#include <gtest.h>

#define TEST_IT(test_name) TEST(Stack, test_name)

TEST_IT(should_be_constructable_with_given_size) {
  EXPECT_NO_THROW(Stack<int>(5));
}

TEST_IT(should_have_push) {
  Stack<int> s;

  EXPECT_NO_THROW(s.push(1));
}

TEST_IT(should_tell_if_it_is_empty) {
  Stack<int> s;

  EXPECT_TRUE(s.isEmpty());
}

TEST_IT(should_properly_calculate_size) {
  Stack<int> s;

  s.push(1);
  s.push(2);

  EXPECT_EQ(2, s.getSize());
}

TEST_IT(should_have_top) {
  Stack<int> s;

  s.push(1);
  s.push(2);

  EXPECT_NO_THROW(s.top());
  EXPECT_EQ(2, s.top());
}

TEST_IT(should_throw_when_calling_top_on_empty) {
  Stack<int> s;

  EXPECT_ANY_THROW(s.top());
}

TEST_IT(should_have_pop) {
  Stack<int> s;

  s.push(1);
  s.push(2);
  s.push(3);

  EXPECT_NO_THROW(s.pop());
  EXPECT_EQ(2, s.pop());
  EXPECT_EQ(1, s.getSize());
}

TEST_IT(should_throw_when_calling_pop_on_empty) {
  Stack<int> s;

  EXPECT_ANY_THROW(s.pop());
}

TEST_IT(should_be_assignable) {
  Stack<int> s1;
  s1.push(1);
  s1.push(2);
  s1.push(3);
  Stack<int> s2(50);
  s2 = s1;

  EXPECT_EQ(s1, s2);
}

TEST_IT(should_resize_on_overflow) {
  Stack<int> s(2);
  size_t initial_size = s.allocated_size;
  s.push(1);
  s.push(2);
  s.push(3);

  EXPECT_EQ(2, initial_size);
  EXPECT_EQ(4, s.allocated_size);
  EXPECT_EQ(1, s.begin[0]);
  EXPECT_EQ(2, s.begin[1]);
  EXPECT_EQ(3, s.begin[2]);
}
