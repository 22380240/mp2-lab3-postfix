#include "postfix.h"
#include <gtest.h>

#define TEST_IT(test_name) TEST(TPostfix, test_name)

TEST_IT(should_return_infix) {
  TPostfix p("((1 + 2 * 2)) * 5 + 1 * 2 + 1");

  EXPECT_EQ("((1 + 2 * 2)) * 5 + 1 * 2 + 1", p.GetInfix());
}

TEST_IT(should_properly_convert_to_postfix) {
  TPostfix p("(((1 + 2 * 2)) * 5 + 1 * 2 + 7) / 5");

  EXPECT_EQ("122*+5*12*+7+5/", p.GetStringifiedPostfix());
}

TEST_IT(should_throw_on_unsupported_operations) {
  TPostfix p("1 ^ 2");

  EXPECT_ANY_THROW(p.GetPostfix());
}

TEST_IT(should_calculate_expression_correctly) {
  TPostfix p("(((1 + 2 * 2)) * 5 + 1 * 2 + 7) / 5");

  EXPECT_EQ(6.8, p.Calculate());
}
