/**
 * 連続する数字列や文字列の判定（2）
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

/// @brief 連続する数字列や文字列の判定1
/// @param letter 文字列。
/// @return 連続する数字列もしくは文字列の場合True、そうでない場合はFalseを返します。
bool isSequenceLetter1(const std::string letter)
{
  bool response = true;
  auto len = letter.size() - 1;
  for (int i = 0; i < len; i++)
  {
    auto charCode1 = convertCharToCharCode(letter[i]);
    auto charCode2 = convertCharToCharCode(letter[i + 1]);
    auto charCode = charCode2 - charCode1;
    if (charCode != 1)
    {
      response = false;
    }
  }
  return response;
}

/// @brief 連続する数字列や文字列の判定2
/// @param letter 文字列。
/// @return 連続する数字列もしくは文字列の場合True、そうでない場合はFalseを返します。
bool isSequenceLetter2(const std::string letter)
{
  bool response = true;
  auto len = letter.size() - 1;
  for (int i = 0; i < len; i++)
  {
    auto charCode1 = convertCharToCharCode(letter[i]);
    auto charCode2 = convertCharToCharCode(letter[i + 1]);
    auto charCode = charCode1 - charCode2;
    if (charCode != 1)
    {
      response = false;
    }
  }
  return response;
}

int main()
{
  // 連続する数字列でないこと
  assert(isSequenceLetter1("112233") == false && isSequenceLetter2("332211") == false);
  assert(isSequenceLetter1("567890") == false && isSequenceLetter2("098765") == false);

  // 連続する数値であること
  assert(isSequenceLetter1("012345") == true && isSequenceLetter2("543210") == true);
  assert(isSequenceLetter1("0123456789") == true && isSequenceLetter2("9876543210") == true);

  // 連続す文字列でないこと
  assert(isSequenceLetter1("AABBCCDD") == false && isSequenceLetter2("DDCCBBAA") == false);
  assert(isSequenceLetter1("XYZABCDE") == false && isSequenceLetter2("EDCBAZYX") == false);

  // 連続する文字列であること
  assert(isSequenceLetter1("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == true && isSequenceLetter2("ZYXWVUTSRQPONMLKJIHGFEDCBA") == true);
  assert(isSequenceLetter1("abcdefghijklmnopqrstuvwxyz") == true && isSequenceLetter2("zyxwvutsrqponmlkjihgfedcba") == true);

  return 0;
}