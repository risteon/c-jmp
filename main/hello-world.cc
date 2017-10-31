#include <vector>
#include <ctime>
#include <iostream>
#include <random>
#include <functional>
#include <algorithm>

#include "lib/algorithm.h"

int main(int argc, char** argv)
{
  // Specify the engine and distribution.
  std::mt19937 mersenne_engine(1337);
  std::uniform_int_distribution<int> dist(-1000, 2000);
  auto gen = std::bind(dist, mersenne_engine);
  std::vector<int> v(50000);
  std::generate(std::begin(v), std::end(v), gen);

  const clock_t start = clock();

  const auto r = jmp::maxContiguousSubarray(v.begin(), v.end());

  const clock_t end = clock();
  std::cout << "Max value: " << r << "\n";
  std::cout << "Duration: " << (end - start) << "\n";

  return 0;
}

