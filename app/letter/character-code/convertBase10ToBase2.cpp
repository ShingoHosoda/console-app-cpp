#include <iostream>
#include <cassert>
/// @brief 10進数の値を2進数に変換します。
/// @param decimal 10進数の値。
/// @return 2進数の値を返します。
[[nodiscard]]
std::string convertBase10ToBase2(unsigned int decimal)
{
  std::string binary{""};
  while (decimal > 0)
  {
    binary = std::to_string(decimal % 2) + binary;
    decimal /= 2;
  }

  return binary;
}

int main()
{
  // 10進数から2進数の変換テスト
  assert(convertBase10ToBase2(10) == "1010");
  assert(convertBase10ToBase2(11) == "1011");
  assert(convertBase10ToBase2(12) == "1100");
  assert(convertBase10ToBase2(13) == "1101");
  return 0;
}