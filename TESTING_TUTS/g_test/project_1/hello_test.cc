#include <gtest/gtest.h>

TEST(HelloTest, BasicAssertions) {
	
	// Expect two strings to be equal
	EXPECT_STRNE("hello", "world");

	// Expect Equality
	EXPECT_EQ(7 * 6, 42);


}
