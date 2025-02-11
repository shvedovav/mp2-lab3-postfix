#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
	ASSERT_NO_THROW(TPostfix p("a*b"));
}
TEST(TPostfix, can_create_postfix_with_brackets)
{
	ASSERT_NO_THROW(TPostfix p("(a+b)*c"));
}
TEST(TPostfix, can_get_short_postfix)
{
	TPostfix p("a*b");
	EXPECT_EQ("ab*", p.GetPostfix());
}
TEST(TPostfix, can_get_postfix_with_brackets)
{
	TPostfix p("(a+b)*c/d");
	EXPECT_EQ("ab+c*d/", p.GetPostfix());
}
TEST(TPostfix, can_get_short_infix)
{
	TPostfix p("a*b");
	EXPECT_EQ("a*b", p.GetInfix());
}
TEST(TPostfix, can_get_infix_with_brackets)
{
	TPostfix p("(a+b)*c/d");
	EXPECT_EQ("(a+b)*c/d", p.GetInfix());
}
TEST(TPostfix, can_get_operands)
{
	TPostfix p("(a+b)*c/d");
	vector<char> op = { 'a','b','c','d' };
	EXPECT_EQ(op, p.GetOperands());
}
TEST(TPostfix, can_calculate_short_expression)
{
	TPostfix p("a*b");
	map<char, double> val;
	val['a'] = 2;
	val['b'] = 3;
	EXPECT_EQ(6, p.Calculate(val));
}
TEST(TPostfix, can_calculate_expression_with_brackets)
{
	TPostfix p("(a+b)*c/d");
	map<char, double> val;
	val['a'] = 1;
	val['b'] = 2;
	val['c'] = 3;
	val['d'] = 4;
	EXPECT_EQ(2.25, p.Calculate(val));
}