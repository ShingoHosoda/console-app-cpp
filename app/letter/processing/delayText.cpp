/*********************************
 * テキストをN文字分右にずらす（大文字のみ）
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

/// @brief 平文をずらします。
/// @param planeText 平文
/// @param delay ずらす数
/// @return ずらした平文を返します。
std::string delayText(std::string planeText, int delay)
{
  std::string delayText = "";
  for (auto &character : planeText)
  {
    if (isUpperCase(character))
    {
      auto charNumber = convertCharToCharCode(character) - convertCharToCharCode('A');
      auto delayCharNumber = (charNumber + delay) % 26;
      auto charCode = delayCharNumber + convertCharToCharCode('A');
      delayText += convertCharCodeToChar(charCode);
    }
    else
    {

      delayText += character;
    }
  }
  return delayText;
}

int main()
{
  constexpr auto delay = 3;
  assert(delayText("HELLO WORLD", delay) == "KHOOR ZRUOG");
  assert(delayText("CAESAR", delay) == "FDHVDU");
  assert(delayText("SECURITY", delay) == "VHFXULWB");
  return 0;
}