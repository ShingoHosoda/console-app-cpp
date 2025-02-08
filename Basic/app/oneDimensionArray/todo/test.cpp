#include <iostream>
#include <cassert>
#include "Todo.hpp"
void TestAdd()
{
  std::cout << "テスト開始" << std::endl;
  std::vector<app::Todo> todos1{
      {"ID1", "タイトル1", "2025-02-10", 0},
      {"ID2", "タイトル2", "2025-02-15", 0},
      {"ID3", "タイトル3", "2025-02-20", 0},
      {"ID4", "タイトル4", "2025-02-25", 0},
  };

  app::add(todos1);
  app::add(todos1);

  std::vector<app::Todo> todos2{
      {"ID1", "タイトル1", "2025-02-10", 0},
      {"ID2", "タイトル2", "2025-02-15", 0},
      {"ID3", "タイトル3", "2025-02-20", 0},
      {"ID4", "タイトル4", "2025-02-25", 0},
      {"ID5", "タイトル5", "2025-02-10", 0},
      {"ID6", "タイトル6", "2025-02-10", 0},
  };

  auto index = 0;
  for (const auto &todo : todos1)
  {
    assert(todo.title == todos2[index].title);
    index += 1;
  }

  std::cout << "テスト成功" << std::endl;
}

void TestRemove()
{
  std::cout << "テスト開始" << std::endl;
  std::vector<app::Todo> todos1{
      {"ID1", "タイトル1", "2025-02-10", 0},
      {"ID2", "タイトル2", "2025-02-15", 0},
      {"ID3", "タイトル3", "2025-02-20", 0},
      {"ID4", "タイトル4", "2025-02-25", 0},
      {"ID5", "タイトル5", "2025-02-10", 0},
      {"ID6", "タイトル6", "2025-02-10", 0},
  };

  app::remove(todos1);
  app::remove(todos1);

  std::vector<app::Todo> todos2{
      {"ID1", "タイトル1", "2025-02-10", 0},
      {"ID2", "タイトル2", "2025-02-15", 0},
      {"ID3", "タイトル3", "2025-02-20", 0},
      {"ID4", "タイトル4", "2025-02-25", 0},
  };

  auto index = 0;
  for (const auto &todo : todos1)
  {
    assert(todo.title == todos2[index].title);
    index += 1;
  }

  std::cout << "テスト成功" << std::endl;
}

int main()
{
  // TestAdd();
  TestRemove();
  return 0;
}