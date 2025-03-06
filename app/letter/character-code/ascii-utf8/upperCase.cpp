/**
 * 文字コードから大文字を出力
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
  std::string upperCase{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  auto code = 65;
  for (const auto character : upperCase)
  {
    assert(converteCharCodeToChar(code) == character);
    code++;
  }

  assert(code == 91);
  return 0;
}