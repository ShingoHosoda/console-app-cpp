/**
 * @todo 入力を番号に変更し条件分岐はswitch文に変更する。
 */
#include <iostream>
#include <vector>
#include "numbers.hpp"
int main()
{
  std::vector<int> numbers;
  while (true)
  {
    std::cout << "-------------------------------------------\n"
              << "add: " << "値を追加します。" << "\n"
              << "remove: " << "値を削除します。" << "\n"
              << "update: " << "値を更新します。" << "\n"
              << "find: " << "値を検索します。" << "\n"
              << "sortAsc: " << "昇順に値をソートします。" << "\n"
              << "sortDesc: " << "降順に値をソートします。" << "\n"
              << "print: " << "値を出力します。" << "\n"
              << "exit: " << "アプリケーションの終了。" << "\n"
              << "-------------------------------------------\n";
    std::string command{};
    std::getline(std::cin, command);
    if (command == "add")
    {
      std::cout << "新しい数値を入力してください。\n";
      std::string number;
      std::getline(std::cin, number);
      app::add(numbers, number);
    }
    else if (command == "remove")
    {
    }
    else if (command == "update")
    {
    }
    else if (command == "find")
    {
    }
    else if (command == "sortAsc")
    {
    }
    else if (command == "sortDesc")
    {
    }
    else if (command == "print")
    {
      app::print(numbers);
    }
    else if (command == "exit")
    {
      return 0;
    }
    else
    {
      std::cout << "無効な入力です。" << std::endl;
      continue;
    }
  }

  return 0;
}