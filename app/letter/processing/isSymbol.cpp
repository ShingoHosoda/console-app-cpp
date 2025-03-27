/*********************************
 * 入力された文字が記号かどうかを判定
 * 記号セット1 ! - /
 * 記号セット2 : - @
 * 記号セット3 [ - `
 * 記号セット4 { - ~
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

/// @brief 記号セット1かどうかを判定します。
/// @param character UTF-8の文字
/// @return 記号セット1の場合true、そうでない場合はfalseを返します。
constexpr bool isSymbolSet1(const char8 character)
{
  constexpr auto MIN = convertCharToCharCode('!');
  constexpr auto MAX = convertCharToCharCode('/');
  const auto code = convertCharToCharCode(character);
  if (code >= MIN && code <= MAX)
  {
    return true;
  }
  return false;
}

/// @brief 記号セット2かどうかを判定します。
/// @param character UTF-8の文字
/// @return 記号セット2の場合true、そうでない場合はfalseを返します。
constexpr bool isSymbolSet2(const char8 character)
{
  constexpr auto MIN = convertCharToCharCode(':');
  constexpr auto MAX = convertCharToCharCode('@');
  const auto code = convertCharToCharCode(character);
  if (code >= MIN && code <= MAX)
  {
    return true;
  }
  return false;
}

/// @brief 記号セット3かどうかを判定します。
/// @param character UTF-8の文字
/// @return 記号セット3の場合true、そうでない場合はfalseを返します。
constexpr bool isSymbolSet3(const char8 character)
{
  constexpr auto MIN = convertCharToCharCode('[');
  constexpr auto MAX = convertCharToCharCode('`');
  const auto code = convertCharToCharCode(character);
  if (code >= MIN && code <= MAX)
  {
    return true;
  }
  return false;
}

/// @brief 記号セット4かどうかを判定します。
/// @param character UTF-8の文字
/// @return 記号セット4の場合true、そうでない場合はfalseを返します。
constexpr bool isSymbolSet4(const char8 character)
{
  constexpr auto MIN = convertCharToCharCode('{');
  constexpr auto MAX = convertCharToCharCode('~');
  const auto code = convertCharToCharCode(character);
  if (code >= MIN && code <= MAX)
  {
    return true;
  }
  return false;
}

int main()
{
  // 記号セット1であること
  assert(isSymbolSet1('!') == true);
  assert(isSymbolSet1('+') == true);
  assert(isSymbolSet1('/') == true);
  // 記号セット1以外であること
  assert(isSymbolSet1('A') == false);
  assert(isSymbolSet1('@') == false);
  assert(isSymbolSet1('a') == false);
  assert(isSymbolSet1('|') == false);

  // 記号セット2であること
  assert(isSymbolSet2(':') == true);
  assert(isSymbolSet2('=') == true);
  assert(isSymbolSet2('@') == true);
  // 記号セット2以外であること
  assert(isSymbolSet2('A') == false);
  assert(isSymbolSet2('!') == false);
  assert(isSymbolSet2('a') == false);
  assert(isSymbolSet2('|') == false);

   // 記号セット3であること
   assert(isSymbolSet3('[') == true);
   assert(isSymbolSet3('^') == true);
   assert(isSymbolSet3('`') == true);
   // 記号セット3以外であること
   assert(isSymbolSet3('A') == false);
   assert(isSymbolSet3('!') == false);
   assert(isSymbolSet3('a') == false);
   assert(isSymbolSet3('|') == false);

   // 記号セット4であること
   assert(isSymbolSet4('{') == true);
   assert(isSymbolSet4('|') == true);
   assert(isSymbolSet4('~') == true);
   // 記号セット4以外であること
   assert(isSymbolSet4('A') == false);
   assert(isSymbolSet4('!') == false);
   assert(isSymbolSet4('a') == false);
   assert(isSymbolSet4('_') == false);

  return 0;
}