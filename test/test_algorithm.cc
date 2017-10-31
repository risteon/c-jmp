#include "gtest/gtest.h"

#include <vector>
#include <random>
#include <functional>
#include <algorithm>

#include "lib/algorithm.h"


TEST(test_algorithm, max_contiguous_subarray)
{
  const std::vector<int> v{-2, 1, -3, 4, -1, 2, 1, -5, 4};

  std::vector<int>::const_iterator a, b;
  EXPECT_EQ(jmp::maxContiguousSubarray<std::vector<int>::const_iterator>(v.begin(), v.end(), &a, &b), 6);

  std::vector<int> sub(a, b);

  for (const auto i : sub)
    std::cout << i << "\n";

  std::vector<int> ex{4, -1, 2, 1};
  EXPECT_EQ(ex, sub);

  // Specify the engine and distribution.
  std::mt19937 mersenne_engine(1337);
  std::uniform_int_distribution<int> dist(0, 2000);
  auto gen = std::bind(dist, mersenne_engine);
  std::vector<int> v_long(1000);
  std::generate(std::begin(v_long), std::end(v_long), gen);

  const int sum = std::accumulate(v_long.cbegin(), v_long.cend(), 0);
  EXPECT_EQ(sum, jmp::maxContiguousSubarray(v_long.cbegin(), v_long.cend(), &a, &b));
  EXPECT_EQ(a, v_long.cbegin());
  EXPECT_EQ(b, v_long.cend());
}
