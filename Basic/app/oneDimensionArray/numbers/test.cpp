#include <iostream>
#include <string>
#include <cassert>
#include "numbers.hpp"
void testAdd()
{
  std::cout << "テスト開始" << std::endl;
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

void testRemove()
{
  std::cout << "テスト開始" << std::endl;
  std::vector<int> numbers1;
  app::add(numbers1, std::to_string(0));
  app::add(numbers1, std::to_string(1));
  app::add(numbers1, std::to_string(2));
  app::add(numbers1, std::to_string(3));
  app::add(numbers1, std::to_string(4));
  app::remove(numbers1, std::to_string(0));
  std::vector<int> numbers2{1, 2, 3, 4};
  auto index = 0;
  for (const auto &v : numbers1)
  {
    assert(v == numbers2.at(index));
    index += 1;
  }

  std::cout << "テスト成功" << std::endl;
}

void testUpdate()
{
  std::cout << "テスト開始" << std::endl;
  std::vector<int> numbers1;
  app::add(numbers1, std::to_string(0));
  app::add(numbers1, std::to_string(1));
  app::add(numbers1, std::to_string(2));
  app::add(numbers1, std::to_string(3));
  app::add(numbers1, std::to_string(4));
  app::update(numbers1, std::to_string(0), std::to_string(10));
  app::update(numbers1, std::to_string(1), std::to_string(11));
  std::vector<int> numbers2{10, 11, 2, 3, 4};
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
  // testAdd();
  // testRemove();
  testUpdate();
  return 0;
}