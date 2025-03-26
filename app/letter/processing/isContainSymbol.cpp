/*********************************
 * 数字が含まれているとは
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

/// @brief 小文字が含まれているかどうかを判定します。
/// @param letter 文字列。
/// @return 小文字が含まれている場合true、そうでない場合はfalseを返します。
bool isContainLowerCase(const std::string letter)
{
  constexpr auto MIN = convertCharToCharCode('a');
  constexpr auto MAX = convertCharToCharCode('z');
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

/// @brief 数字が含まれているかどうかを判定します。
/// @param letter 文字列。
/// @return 数字が含まれている場合true、そうでない場合はfalseを返します。
bool isContainNumber(const std::string letter)
{
  constexpr auto MIN = convertCharToCharCode('0');
  constexpr auto MAX = convertCharToCharCode('9');
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

/// @brief 記号(@, ?, !)が含まれているかどうかを判定します。
/// @param letter 文字列。
/// @return 記号(@, ?, !)が含まれている場合true、そうでない場合はfalseを返します。
bool isContainSymbol(const std::string letter)
{
  constexpr auto atMark = convertCharToCharCode('@');
  constexpr auto questionMark = convertCharToCharCode('?');
  constexpr auto exclamationMark = convertCharToCharCode('!');
  for (const auto &c : letter)
  {
    auto code = convertCharToCharCode(c);
    if (code == atMark || code == questionMark || code == exclamationMark)
    {
      return true;
    }
  }
  return false;
}

int main()
{
  // 記号が含まれていること
  assert(isContainSymbol("p@55w0rd") == true);
  assert(isContainSymbol("(^_^)!") == true);
  assert(isContainSymbol("(._.)?") == true);

  // 記号が含まれていないこと
  assert(isContainSymbol("password") == false);
  assert(isContainSymbol("mapping(-_-)") == false);

  return 0;
}