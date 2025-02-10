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
    assert(todo.title == todos2[index].title && todo.dueDate == todos2[index].dueDate && todo.completed == todos2[index].completed);
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
    assert(todo.title == todos2[index].title && todo.dueDate == todos2[index].dueDate && todo.completed == todos2[index].completed);
    index += 1;
  }

  std::cout << "テスト成功" << std::endl;
}

void TestUpdate()
{
  std::cout << "テスト開始" << std::endl;
  std::vector<app::Todo> todos1{
      {"01234567-00000000", "タイトル0", "2025-02-10", 0},
      {"01234567-00000001", "タイトル1", "2025-02-10", 0},
      {"01234567-00000002", "タイトル2", "2025-02-15", 0},
      {"01234567-00000003", "タイトル3", "2025-02-20", 0},
      {"01234567-00000004", "タイトル4", "2025-02-25", 0},
      {"01234567-00000005", "タイトル5", "2025-02-10", 0},
      {"01234567-00000006", "タイトル6", "2025-02-10", 0},
      {"01234567-00000007", "タイトル7", "2025-02-10", 0},
  };

  app::update(todos1);

  std::vector<app::Todo> todos2{
      {"01234567-00000000", "タイトル10", "2025-02-10", 1},
      {"01234567-00000001", "タイトル1", "2025-02-10", 0},
      {"01234567-00000002", "タイトル2", "2025-02-15", 0},
      {"01234567-00000003", "タイトル3", "2025-02-20", 0},
      {"01234567-00000004", "タイトル4", "2025-02-25", 0},
      {"01234567-00000005", "タイトル5", "2025-02-10", 0},
      {"01234567-00000006", "タイトル6", "2025-02-10", 0},
      {"01234567-00000007", "タイトル7", "2025-02-10", 0},
  };

  auto index = 0;
  for (const auto &todo : todos1)
  {
    assert(todo.title == todos2[index].title && todo.dueDate == todos2[index].dueDate && todo.completed == todos2[index].completed);
    index += 1;
  }

  std::cout << "テスト成功" << std::endl;
}

void TestFindByTitle()
{
  std::cout << "テスト開始" << std::endl;
  std::vector<app::Todo> todos;
  app::readTSV(todos, "data/todo.tsv");
  std::vector<app::Todo> todos1 = app::findByTitle(todos);
  std::vector<app::Todo> todos2{{"01234567-00000003", "タイトル3", "2025-02-20", 0}};
  auto index = 0;
  for (const auto &todo : todos1)
  {
    assert(todo.title == todos2[index].title && todo.dueDate == todos2[index].dueDate && todo.completed == todos2[index].completed);
    index += 1;
  }
  std::cout << "テスト成功" << std::endl;
}

void TestFindByDueDate()
{
  std::cout << "テスト開始" << std::endl;
  std::vector<app::Todo> todos;
  app::readTSV(todos, "data/todo.tsv");
  std::vector<app::Todo> todos1 = app::findByDueDate(todos);
  std::vector<app::Todo> todos2{
      {"01234567-00000000", "タイトル0", "2025-02-10", 0},
      {"01234567-00000001", "タイトル1", "2025-02-10", 0},
      {"01234567-00000005", "タイトル5", "2025-02-10", 0},
      {"01234567-00000006", "タイトル6", "2025-02-10", 0},
      {"01234567-00000007", "タイトル7", "2025-02-10", 0},
  };
  auto index = 0;
  for (const auto &todo : todos1)
  {
    assert(todo.title == todos2[index].title && todo.dueDate == todos2[index].dueDate && todo.completed == todos2[index].completed);
    index += 1;
  }
  std::cout << "テスト成功" << std::endl;
}



void TestWriteTSV()
{
  std::cout << "テスト開始" << std::endl;
  std::vector<app::Todo> todos1{
      {"01234567-00000000", "タイトル0", "2025-02-10", 0},
      {"01234567-00000001", "タイトル1", "2025-02-10", 0},
      {"01234567-00000002", "タイトル2", "2025-02-15", 0},
      {"01234567-00000003", "タイトル3", "2025-02-20", 0},
      {"01234567-00000004", "タイトル4", "2025-02-25", 0},
      {"01234567-00000005", "タイトル5", "2025-02-10", 0},
      {"01234567-00000006", "タイトル6", "2025-02-10", 0},
      {"01234567-00000007", "タイトル7", "2025-02-10", 0},
  };
  assert(app::writeTSV(todos1, "data/todo.tsv") == true);
  std::cout << "テスト成功" << std::endl;
}

void TestReadTSV()
{
  std::cout << "テスト開始" << std::endl;
  std::vector<app::Todo> todos1{
      {"01234567-10000000", "タイトル0", "2025-02-10", 0},
      {"01234567-10000001", "タイトル1", "2025-02-10", 0},
      {"01234567-10000002", "タイトル2", "2025-02-15", 0},
      {"01234567-10000003", "タイトル3", "2025-02-20", 0},
      {"01234567-10000004", "タイトル4", "2025-02-25", 0},
      {"01234567-10000005", "タイトル5", "2025-02-10", 0},
      {"01234567-10000006", "タイトル6", "2025-02-10", 0},
      {"01234567-10000007", "タイトル7", "2025-02-10", 0},
  };

  assert(app::readTSV(todos1, "data/todo.tsv") == true);

  std::vector<app::Todo> todos2{
      {"01234567-00000000", "タイトル0", "2025-02-10", 0},
      {"01234567-00000001", "タイトル1", "2025-02-10", 0},
      {"01234567-00000002", "タイトル2", "2025-02-15", 0},
      {"01234567-00000003", "タイトル3", "2025-02-20", 0},
      {"01234567-00000004", "タイトル4", "2025-02-25", 0},
      {"01234567-00000005", "タイトル5", "2025-02-10", 0},
      {"01234567-00000006", "タイトル6", "2025-02-10", 0},
      {"01234567-00000007", "タイトル7", "2025-02-10", 0},
  };

  auto index = 0;
  for (const auto &todo : todos1)
  {
    assert(todo.title == todos2[index].title && todo.dueDate == todos2[index].dueDate && todo.completed == todos2[index].completed);
    index += 1;
  }

  std::cout << "テスト成功" << std::endl;
}

void TestWriteReadTSV()
{
  std::cout << "テスト開始" << std::endl;
  std::vector<app::Todo> todos1{
      {"01234567-00000000", "タイトル0", "2025-02-10", 0},
      {"01234567-00000001", "タイトル1", "2025-02-10", 0},
      {"01234567-00000002", "タイトル2", "2025-02-15", 0},
      {"01234567-00000003", "タイトル3", "2025-02-20", 0},
      {"01234567-00000004", "タイトル4", "2025-02-25", 0},
      {"01234567-00000005", "タイトル5", "2025-02-10", 0},
      {"01234567-00000006", "タイトル6", "2025-02-10", 0},
      {"01234567-00000007", "タイトル7", "2025-02-10", 0},
  };

  assert(app::writeTSV(todos1, "data/todo.tsv") == true);
  assert(app::readTSV(todos1, "data/todo.tsv") == true);

  std::vector<app::Todo> todos2{
      {"01234567-00000000", "タイトル0", "2025-02-10", 0},
      {"01234567-00000001", "タイトル1", "2025-02-10", 0},
      {"01234567-00000002", "タイトル2", "2025-02-15", 0},
      {"01234567-00000003", "タイトル3", "2025-02-20", 0},
      {"01234567-00000004", "タイトル4", "2025-02-25", 0},
      {"01234567-00000005", "タイトル5", "2025-02-10", 0},
      {"01234567-00000006", "タイトル6", "2025-02-10", 0},
      {"01234567-00000007", "タイトル7", "2025-02-10", 0},
  };

  auto index = 0;
  for (const auto &todo : todos1)
  {
    assert(todo.title == todos2[index].title && todo.dueDate == todos2[index].dueDate && todo.completed == todos2[index].completed);
    index += 1;
  }

  std::cout << "テスト成功" << std::endl;
}

int main()
{
  // TestAdd();
  // TestRemove();
  // TestUpdate();
  // TestFindByTitle();
  TestFindByDueDate();
  // TestWriteTSV();
  // TestReadTSV();
  // TestWriteReadTSV();
  return 0;
}