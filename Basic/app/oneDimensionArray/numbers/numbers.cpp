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
  if (isNumber(number) == false)
  {
    std::cout << "入力値が正しくありません。数値を追加できませんでした。\n";
  }
  else
  {
    std::cout << "新しい数値を追加します。\n";
    numbers.push_back(std::stoi(number));
  }
}

void app::remove(std::vector<int> &numbers, std::string number)
{
  if (isNumber(number) == false)
  {
    std::cout << "入力値が正しくありません。数値を削除できませんでした。\n";
  }
  else
  {
    auto iterator = std::find_if(std::cbegin(numbers), std::cend(numbers), [number](int value)
                                 { return value == std::stoi(number); });
    if (iterator == std::cend(numbers))
    {
      std::cout << "指定した数値は存在しませんでした。\n";
    }
    else
    {
      numbers.erase(iterator);
      std::cout << "指定した数値は削除しました。\n";
    }
  }
}

void app::update(std::vector<int> &numbers, std::string number1, std::string number2)
{
  std::cout << "数値を更新します\n";
  if (isNumber(number1) == false && isNumber(number2) == false)
  {
    std::cout << "入力値が正しくありません。数値を更新できませんでした。\n";
  }
  else
  {
    for (auto &v : numbers)
    {
      if (v == std::stoi(number1))
      {
        v = std::stoi(number2);
      }
    }

    std::cout << "新しい値に更新しました。\n";
  }
}

void app::find(std::vector<int> &numbers, std::string number)
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