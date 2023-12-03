#include "postfix.h"
#include <gtest.h>

#define TEST_IT(test_name) TEST(TPostfix, test_name)

TEST_IT(should_have_default_constructor) {
  TPostfix p;

  EXPECT_EQ("a + b", p.GetInfix());
}

TEST_IT(should_not_throw_on_create) {
  EXPECT_NO_THROW(TPostfix p("((1 + 2 * 2)) * 5 + 1 * 2 + 1"));
}

TEST_IT(should_return_infix) {
  TPostfix p("((1 + 2 * 2)) * 5 + 1 * 2 + 1");

  EXPECT_EQ("((1 + 2 * 2)) * 5 + 1 * 2 + 1", p.GetInfix());
}

TEST_IT(should_parse_simple_expr) {
  TPostfix p("1 + 2");

  EXPECT_EQ("12+", p.GetStringifiedPostfix());
}

TEST_IT(should_parse_simple_expr_with_parens) {
  TPostfix p("(1 + 2) * 3");

  EXPECT_EQ("12+3*", p.GetStringifiedPostfix());
}

TEST_IT(should_properly_convert_to_postfix) {
  TPostfix p("(((1 + 2 * 2)) * 5 + 1 * 2 + 7) / 5");

  EXPECT_EQ("122*+5*12*+7+5/", p.GetStringifiedPostfix());
}

TEST_IT(should_ignore_any_spaces) {
  TPostfix p(" 1    \t    +   \n 2+3  ");

  EXPECT_EQ("12+3+", p.GetStringifiedPostfix());
}

TEST_IT(should_strip_out_redundant_parens) {
  TPostfix p("(1) + (2)");

  EXPECT_EQ("12+", p.GetStringifiedPostfix());
}

TEST_IT(should_throw_on_unsupported_operations) {
  TPostfix p("1 ^ 2");

  EXPECT_ANY_THROW(p.GetPostfix());
}

TEST_IT(should_calculate_expression_correctly) {
  TPostfix p("(((1 + 2 * 2)) * 5 + 1 * 2 + 7) / 5");

  EXPECT_EQ(6.8, p.Calculate());
}
