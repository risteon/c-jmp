#include "greet.h"

void hello()
{
  std::cout <<"Hi there.\n";
}

int testFunc()
{
  // use generic lambda as c++14 feature
  auto f = [](auto a, auto b){ return a + b;};
  return f(30, 12);
}

