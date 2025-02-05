#include "numbers.hpp"

bool app::isNumber(std::string &s)
{
  for (const auto &c : s)
  {
    if (int(c) >= int('0') && int(c) <= int('9'))
    {
      return true;
    }
  }
  return false;
}

void app::add(std::vector<int> &numbers, std::string number)
{
  if (!isNumber(number))
  {
    std::cout << "入力値が正しくありません。数値を追加できませんでした。\n";
  }
  else
  {
    std::cout << "新しい数値を追加します。\n";
    numbers.push_back(std::stoi(number));
  }
}

void app::remove(std::vector<int> &numbers)
{

}

void app::update(std::vector<int> &numbers)
{
}

void app::find(std::vector<int> &numbers)
{
}

void app::sortAsc(std::vector<int> &numbers)
{
}

void app::sortDesc(std::vector<int> &numbers)
{
}

void app::print(std::vector<int> &numbers)
{
  std::cout << "登録されている数値を出力します。\n";
  for (auto &v : numbers)
  {
    std::cout << v << "\n";
  }
}