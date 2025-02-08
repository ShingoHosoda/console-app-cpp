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