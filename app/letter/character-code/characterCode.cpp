#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using char8 = char;      // ASCII and UTF-8
using char16 = char16_t; // UTF-16 参考程度で今回は使用しません。
using char32 = char32_t; // UTF-32 参考程度で今回は使用しません。
// constexpr unsigned int BIT = 8;

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

/// @brief UTF8の文字型をUTF8の文字コードに変換します。
/// @param character UTF8の文字型。
/// @return UTF-8の文字コードを返します。
[[nodiscard]]
constexpr int convertCharToCharCode(const char8 character)
{
  return (int)character;
}

int main()
{
  // 10進数から2進数の変換テスト
  assert(convertBase10ToBase2(10) == "1010");
  assert(convertBase10ToBase2(11) == "1011");
  assert(convertBase10ToBase2(12) == "1100");
  assert(convertBase10ToBase2(13) == "1101");
  // 文字コードとは？のコードです。
  
  constexpr int charCodeA = convertCharToCharCode('A');
  assert(convertBase10ToBase2(charCodeA) == "1000001");
  
  constexpr int charCodeB = convertCharToCharCode('B');
  assert(convertBase10ToBase2(charCodeB) == "1000010");
  
  return 0;
}