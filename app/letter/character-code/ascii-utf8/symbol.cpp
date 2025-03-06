/**
 * 文字コードから記号を出力
 */
#include <iostream>
#include <cassert>
using char8 = char; // UTF-8
/// @brief UTF-8の文字コードを文字に変換します。
/// @param code UTF-8の文字コード。
/// @return UTF-8の文字を返します。
constexpr char8 converteCharCodeToChar(const int code)
{
  return (char8)code;
}

int main()
{
  std::string symbol1{"!\"#$%&'()*+,-./"};
  auto characterCode1 = 33;
  for (const auto character : symbol1)
  {
    assert(converteCharCodeToChar(characterCode1) == character);
    characterCode1++;
  }
  assert(characterCode1 == 48);

  std::string symbol2{":;<=>?@"};
  auto characterCode2 = 58;
  for (const auto character : symbol2)
  {
    assert(converteCharCodeToChar(characterCode2) == character);
    characterCode2++;
  }
  assert(characterCode2 == 65);

  std::string symbol3{"[\\]^_`"};
  auto characterCode3 = 91;
  for (const auto character : symbol3)
  {
    assert(converteCharCodeToChar(characterCode3) == character);
    characterCode3++;
  }
  assert(characterCode3 == 97);

  std::string symbol4{"{|}~"};
  auto characterCode4 = 123;
  for (const auto character : symbol4)
  {
    assert(converteCharCodeToChar(characterCode4) == character);
    characterCode4++;
  }
  assert(characterCode4 == 127);
  return 0;
}