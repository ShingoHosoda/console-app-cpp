/*********************************
 * 入力された文字が大文字かどうかを判定
 *********************************/
#include <iostream>
#include <cassert>
using char8 = char; // UTF-8の文字型
/// @brief UTF-8の文字を文字コードに変換する。
/// @param character UTF-8の文字。
/// @return UTF-8の文字コードを返します。
[[nodiscard]]
constexpr int convertCharToCharCode(const char8 character)
{
  return (int)character;
}

/// @brief 大文字かどうかを判定します。
/// @param character UTF-8の文字
/// @return 大文字の場合true、そうでない場合はfalseを返します。
constexpr bool isUpperCase(const char8 character)
{
  constexpr auto MIN = convertCharToCharCode('A');
  constexpr auto MAX = convertCharToCharCode('Z');
  const auto code = convertCharToCharCode(character);
  if (code >= MIN && code <= MAX)
  {
    return true;
  }
  return false;
}

int main()
{
  // 大文字であること
  assert(isUpperCase('A') == true);
  assert(isUpperCase('Z') == true);
  // 大文字以外であること
  assert(isUpperCase('a') == false);
  assert(isUpperCase('z') == false);
  assert(isUpperCase('0') == false);
  assert(isUpperCase('!') == false);
  return 0;
}