/*********************************
 * 大文字を小文字に変換する
 *********************************/
#include <iostream>
#include <cassert>
using char8 = char; // UTF-8の文字型

/// @brief UTF-8の文字を文字コードに変換します。
/// @param character UTF-8の文字。
/// @return UTF-8の文字コードを返します。
[[nodiscard]]
constexpr int convertCharToCharCode(const char8 character)
{
  return (int)character;
}

/// @brief UTF8の文字コードをUTF8の文字型に変換します。
/// @param characterCode UTF8の文字コード。
/// @return UTF8の文字型を返す。
[[nodiscard]]
constexpr char convertCharCodeToChar(int characterCode)
{
  return (char)(characterCode);
}

/// @brief 小文字かどうかを判定します。
/// @param character UTF-8の文字
/// @return 小文字の場合true、そうでない場合はfalseを返します。
[[nodiscard]]
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

/// @brief 大文字を小文字に変換します。
/// @param character UTF8の文字型。
/// @return 小文字を返します。
[[nodiscard]]
constexpr char8 convertUpperCaseToLowerCase(const char8 character)
{
  if (isLowerCase(character))
  {
    return character;
  }

  auto characterCode = convertCharToCharCode(character);

  return convertCharCodeToChar(characterCode + 32);
}

int main()
{

  // 大文字を小文字に変換すること
  assert(convertUpperCaseToLowerCase('A') == 'a');
  assert(convertUpperCaseToLowerCase('X') == 'x');
  assert(convertUpperCaseToLowerCase('Z') == 'z');

  return 0;
}