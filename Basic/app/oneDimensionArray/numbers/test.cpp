#include <iostream>
#include <string>
#include <cassert>
#include "numbers.hpp"
void testAdd()
{
  std::vector<int> numbers1;
  app::add(numbers1, std::to_string(0));
  app::add(numbers1, std::to_string(1));
  app::add(numbers1, std::to_string(2));
  app::add(numbers1, std::to_string(3));
  app::add(numbers1, std::to_string(4));
  std::vector<int> numbers2{0, 1, 2, 3, 4};
  auto index = 0;
  for (const auto &v : numbers1)
  {
    assert(v == numbers2.at(index));
    index += 1;
  }

  std::cout << "テスト成功" << std::endl;
}

int main()
{
  testAdd();
  return 0;
}