/**
 * 同一の数字列もしくは文字列の判定をします。
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

/// @brief 同一の数字列もしくは文字列の判定をします。
/// @param letter 文字列。
/// @return 同一の数字列もしくは文字列の場合True、そうでない場合はFalseを返します。
bool isEqualsLetter(const std::string letter)
{
  bool flag = true;
  auto len = letter.size() - 1;
  for (int i = 0; i < len; i++)
  {
    auto charCode1 = convertCharToCharCode(letter[i]);
    auto charCode2 = convertCharToCharCode(letter[i + 1]);
    if (charCode1 != charCode2)
    {
      flag = false;
    }
  }
  return flag;
}

int main()
{
  // 同一の数字列でないこと
  assert(isEqualsLetter("01234") == false);
  assert(isEqualsLetter("01122") == false);
  assert(isEqualsLetter("43210") == false);

  // 同一の数字列であること
  assert(isEqualsLetter("11111") == true);
  assert(isEqualsLetter("22222") == true);
  assert(isEqualsLetter("33333") == true);

  // 同一の文字列でないこと
  assert(isEqualsLetter("ABCD") == false);
  assert(isEqualsLetter("XYZ1") == false);
  assert(isEqualsLetter("DCBA") == false);

  // 同一の文字列でないこと
  assert(isEqualsLetter("AAAA") == true);
  assert(isEqualsLetter("BBBB") == true);
  assert(isEqualsLetter("CCCC") == true);
  return 0;
}