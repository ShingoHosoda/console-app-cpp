/*********************************
 * 小文字を大文字に変換する
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

/// @brief 大文字かどうかを判定します。
/// @param character UTF-8の文字
/// @return 大文字の場合true、そうでない場合はfalseを返します。
[[nodiscard]]
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

/// @brief 小文字を大文字に変換します。
/// @param character UTF8の文字型。
/// @return 大文字を返します。
[[nodiscard]]
constexpr char8 convertLowerCaseToUpperCase(const char8 character)
{
  if (isUpperCase(character))
  {
    return character;
  }

  auto characterCode = convertCharToCharCode(character);

  return convertCharCodeToChar(characterCode - 32);
}

int main()
{

  // 小文字を大文字に変換すること
  assert(convertLowerCaseToUpperCase('a') == 'A');
  assert(convertLowerCaseToUpperCase('x') == 'X');
  assert(convertLowerCaseToUpperCase('z') == 'Z');

  return 0;
}