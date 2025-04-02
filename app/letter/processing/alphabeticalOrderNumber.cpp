/***********************************
 * 大文字と小文字のアルファベット順の番号を出力する
 **********************************/
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

/// @brief 文字型をアルファベット順の番号に変換します。
/// @param character UTF8の文字型。
/// @return アルファベット順の番号を返します。
constexpr int convertCharToAlphabeticalNumber(const char8 character)
{
  auto charCode = convertCharToCharCode(character);
  if (isUpperCase(character))
  {
    constexpr auto minUpperCaseCode = convertCharToCharCode('A');
    return charCode - minUpperCaseCode;
  }

  constexpr auto minLowerCaseCode = convertCharToCharCode('a');
  return charCode - minLowerCaseCode;
}

int main()
{
  // アルファベット順の番号に変換されること
  assert(convertCharToAlphabeticalNumber('A') == 0);
  assert(convertCharToAlphabeticalNumber('B') == 1);
  assert(convertCharToAlphabeticalNumber('Z') == 25);

  assert(convertCharToAlphabeticalNumber('a') == 0);
  assert(convertCharToAlphabeticalNumber('b') == 1);
  assert(convertCharToAlphabeticalNumber('z') == 25);
  return 0;
}