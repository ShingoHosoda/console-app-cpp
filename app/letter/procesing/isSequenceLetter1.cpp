/**
 * 連続する数字列や文字列の判定（1）
 */
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

/// @brief 連続する数字列や文字列の判定
/// @param letter 文字列。
/// @return 連続する数字列もしくは文字列の場合True、そうでない場合はFalseを返します。
bool isSequenceLetter1(const std::string letter)
{
  bool flag = true;
  auto len = letter.size() - 1;
  for (int i = 0; i < len; i++)
  {
    auto charCode = convertCharToCharCode(letter[i + 1]) - convertCharToCharCode(letter[i]);
    if (charCode != 1)
    {
      flag = false;
    }
  }
  return flag;
}

int main()
{
  // 連続する数字列でないこと
  assert(isSequenceLetter1("98765") == false);
  assert(isSequenceLetter1("00112") == false);
  assert(isSequenceLetter1("43210") == false);

  // 連続する数字列であること
  assert(isSequenceLetter1("01234") == true);
  assert(isSequenceLetter1("12345") == true);
  assert(isSequenceLetter1("56789") == true);

  // 連続する文字列でないこと
  assert(isSequenceLetter1("JIHGF") == false);
  assert(isSequenceLetter1("ZYXWVUTSRQPONMLKJIHGFEDCBA") == false);
  assert(isSequenceLetter1("zyxwvutsrqponmlkjihgfedcba") == false);

  // 連続する文字列であること
  assert(isSequenceLetter1("ABCDE") == true);
  assert(isSequenceLetter1("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == true);
  assert(isSequenceLetter1("abcdefghijklmnopqrstuvwxyz") == true);

  return 0;
}