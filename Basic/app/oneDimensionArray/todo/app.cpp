#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Todo.hpp"
int main()
{
  std::vector<app::Todo> todos{};
  bool isChanged = false; // 変更があった場合Trueそうでない場合はFalse
  while (true)
  {
    std::cout << "-------------------------------------------\n"
              << "add: " << "TODOを新規に追加します。" << "\n"
              << "remove: " << "TODOを削除します。" << "\n"
              << "update: " << "TODOを更新します。" << "\n"
              << "findByTitle: " << "タイトル名からTODOを検索します。" << "\n"
              << "findByDueDate: " << "期限日からTODOを検索します。" << "\n"
              << "findByCompleted: " << "完了済みかどうかTODOを検索します。。" << "\n"
              << "print: " << "TODOアプリを表示します。" << "\n"
              << "exit: " << "TODOアプリを終了します。" << "\n"
              << "-------------------------------------------\n";
    std::string command{};
    std::getline(std::cin, command);
    if (command == "add")
    {
      if (app::add(todos))
      {
        isChanged = true; // 変更あり
      }
    }
    else if (command == "remove")
    {
      if (app::remove(todos))
      {
        isChanged = true; // 変更あり
      }
    }
    else if (command == "update")
    {
      if (app::update(todos))
      {
        isChanged = true; // 変更あり
      }
    }
    else if (command == "findByTitle")
    {
      auto title = app::findByTitle(todos);
      app::print(title);
    }
    else if (command == "findByDueDate")
    {
      auto dueDate = app::findByDueDate(todos);
      app::print(dueDate);
    }
    else if (command == "findByCompleted")
    {
      auto completed = app::findByCompleted(todos);
      app::print(completed);
    }
    else if (command == "print")
    {
      app::print(todos);
    }
    else if (command == "exit")
    {
      app::exit(isChanged);
      return 0;
    }
  }
  return 0;
}