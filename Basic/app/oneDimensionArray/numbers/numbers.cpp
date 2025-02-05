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

bool app::add(std::vector<int> &numbers, std::string number)
{
  if (isNumber(number) == false)
  {
    std::cout << "入力値が正しくありません。数値を追加できませんでした。\n";
    return false;
  }

  std::cout << "新しい数値を追加します。\n";
  numbers.push_back(std::stoi(number));
  return true;
}

bool app::remove(std::vector<int> &numbers, std::string number)
{
  if (isNumber(number) == false)
  {
    std::cout << "入力値が正しくありません。数値を削除できませんでした。\n";
    return false;
  }
  auto iterator = std::find_if(std::cbegin(numbers), std::cend(numbers), [number](int value)
                               { return value == std::stoi(number); });
  if (iterator == std::cend(numbers))
  {
    std::cout << "指定した数値は存在しませんでした。\n";
    return false;
  }
  numbers.erase(iterator);
  std::cout << "指定した数値は削除しました。\n";
  return true;
}

bool app::update(std::vector<int> &numbers, std::string number1, std::string number2)
{
  std::cout << "数値を更新します\n";
  if (isNumber(number1) == false && isNumber(number2) == false)
  {
    std::cout << "入力値が正しくありません。数値を更新できませんでした。\n";
    return false;
  }

  for (auto &v : numbers)
  {
    if (v == std::stoi(number1))
    {
      v = std::stoi(number2);
    }
  }

  std::cout << "新しい値に更新しました。\n";
  return true;
}

bool app::find(std::vector<int> &numbers, std::string number)
{
  std::cout << "数値を検索します。\n";
  if (isNumber(number) == false)
  {
    std::cout << "入力値が正しくありません。数値を検索できませんでした。\n";
    return false;
  }

  auto iterator = std::find_if(std::cbegin(numbers), std::cend(numbers), [number](int value)
                               { return value == std::stoi(number); });
  if (iterator == std::cend(numbers))
  {
    std::cout << "指定した数値は存在しませんでした。\n";
    return false;
  }

  for (const auto &v : numbers)
  {
    if (v == std::stoi(number))
    {
      std::cout << v << "\n";
    }
  }

  return true;
}

void app::sortAsc(std::vector<int> &numbers)
{
  std::sort(numbers.begin(), numbers.end());
}

void app::sortDesc(std::vector<int> &numbers)
{
  std::sort(numbers.begin(), numbers.end(), std::greater<int>());
}

void app::print(std::vector<int> &numbers)
{
  std::cout << "登録されている数値を出力します。\n";
  for (auto &v : numbers)
  {
    std::cout << v << "\n";
  }
}