#include <gtest/gtest.h>
#include <lowercase.h>

#include <string>
#include <tuple>

TEST(UnitTest, FirstTest) {
  EXPECT_EQ(to_lower("ABC"), "abc");
  EXPECT_EQ(to_lower("A1B2C3"), "a1b2c3");
}

class FixtureTest : public ::testing::Test {
 protected:
  void SetUp() override {
    a = "DEF";
    b = "D1E2F3";
  }
  std::string a;
  std::string b;
};

TEST_F(FixtureTest, SecondTest) {
  EXPECT_EQ(to_lower(a), "def");
  EXPECT_EQ(to_lower(b), "d1e2f3");
}

class ParamTest : public ::testing::TestWithParam<std::tuple<std::string, std::string>> {};

TEST_P(ParamTest, ThirdTest) {
  auto [org, expect] = GetParam();
  EXPECT_EQ(to_lower(org), expect);
}

INSTANTIATE_TEST_SUITE_P(Prefix, ParamTest,
                         ::testing::Values(std::make_tuple("GHI", "ghi"),
                                           std::make_tuple("G1H2I3", "g1h2i3")));