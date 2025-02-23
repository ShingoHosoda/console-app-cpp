#include <iostream>
#include <algorithm>
#include <cassert>
/// @brief 10進数の値をN進数に変換します。
/// @param decimal 10進数の値。
/// @param base 変換したい基数。
/// @return 基数変換後の数値を返します。
[[nodiscard]]
std::string convertBase10ToBaseN(unsigned long long decimal, const unsigned long long base)
{
  constexpr char digits[] = "0123456789ABCDEF";
  std::string value{};
  do
  {
    value.push_back(digits[decimal % base]);
    decimal /= base;
  } while (decimal);

  std::reverse(std::begin(value), std::end(value));

  return value;
}

int main()
{
  assert(convertBase10ToBaseN(13, 2) == "1101");
  assert(convertBase10ToBaseN(18014398509481983, 8) == "777777777777777777");
  assert(convertBase10ToBaseN(2022, 5) == "31042");
  assert(convertBase10ToBaseN(0, 3) == "0");
  assert(convertBase10ToBaseN(10, 16) == "A");
  assert(convertBase10ToBaseN(255, 16) == "FF");
  // unsigned long long n, base;
  // std::cin >> base >> n;
  // std::cout << convertBase10ToBaseN(n, base) << std::endl;
  return 0;
}