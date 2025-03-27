/*********************************
 * 入力された文字が数字かどうかを判定
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

/// @brief 小文字かどうかを判定します。
/// @param character UTF-8の文字
/// @return 小文字の場合true、そうでない場合はfalseを返します。
constexpr bool isLowerCase(const char8 character)
{
  constexpr auto MIN = convertCharToCharCode('a');
  constexpr auto MAX = convertCharToCharCode('z');
  const auto code = convertCharToCharCode(character);
  if (code >= MIN && code <= MAX)
  {
    return true;
  }
  return false;
}

/// @brief 数字かどうかを判定します。
/// @param character UTF-8の文字
/// @return 数字の場合true、そうでない場合はfalseを返します。
constexpr bool isNumber(const char8 character)
{
  constexpr auto MIN = convertCharToCharCode('0');
  constexpr auto MAX = convertCharToCharCode('9');
  const auto code = convertCharToCharCode(character);
  if (code >= MIN && code <= MAX)
  {
    return true;
  }
  return false;
}

int main()
{
  // 数字であること
  assert(isNumber('0') == true);
  assert(isNumber('9') == true);
  // 数字以外であること
  assert(isNumber('A') == false);
  assert(isNumber('Z') == false);
  assert(isNumber('a') == false);
  assert(isNumber('!') == false);
  return 0;
}