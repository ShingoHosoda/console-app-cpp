/*********************************
 * 英大文字が含まれているとは
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

/// @brief 大文字が含まれているかどうかを判定します。
/// @param letter 文字列。
/// @return 大文字が含まれている場合true、そうでない場合はfalseを返します。
bool isContainUpperCase(const std::string letter)
{
  constexpr auto MIN = convertCharToCharCode('A');
  constexpr auto MAX = convertCharToCharCode('Z');
  for (const auto &c : letter)
  {
    auto code = convertCharToCharCode(c);
    if (code >= MIN && code <= MAX)
    {
      return true;
    }
  }
  return false;
}

int main()
{
  // 大文字が含まれていること
  assert(isContainUpperCase("ABC") == true);
  assert(isContainUpperCase("During") == true);

  // 大文字は含まれていないこと
  assert(isContainUpperCase("abc") == false);
  assert(isContainUpperCase("map") == false);

  return 0;
}