/**
 * 文字種の判定
 * 1. 大文字の判定 A - Z
 * 2. 小文字の判定 a - z
 * 3. 数字の判定   0 - 9
 * 4. 記号の判定
 *    記号セット1 ! - /
 *    記号セット2 : - @
 *    記号セット3 [ - `
 *    記号セット4 { - ~
 */
#include <iostream>
#include <cassert>
#include "isLetterType.hpp"
int main()
{
  std::string upperCaseData{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  std::string lowerCaseData{"abcdefghijklmnopqrstuvwxyz"};
  // 大文字かどうかの判定
  for (const auto &character : upperCaseData)
  {
    assert(letter::isUpperCase(character) == true);
  }

  // 大文字から小文字に変換
  auto index = 0;
  for (const auto &character : upperCaseData)
  {
    assert(letter::convertUpperCaseToLowerCase(character) == lowerCaseData[index]);
    index++;
  }

  //  小文字かどうかの判定
  for (const auto &character : lowerCaseData)
  {
    assert(letter::isLowerCase(character) == true);
  }

  // 小文字から大文字に変換
  index = 0;
  for (const auto &character : lowerCaseData)
  {
    assert(letter::convertLowerCaseToUpperCase(character) == upperCaseData[index]);
    index++;
  }

  // 数字かどうかの判定
  std::string numberData{"0123456789"};
  for (const auto &character : numberData)
  {
    assert(letter::isNumber(character) == true);
  }

  // 記号かどうかの判定1
  std::string symbolData1{"!\"#$%&'()*+,-./"};
  for (const auto &character : symbolData1)
  {
    assert(letter::isSymbol1(character) == true);
  }

  // 記号かどうかの判定2
  std::string symbolData2{":;<=>?@"};
  for (const auto &character : symbolData2)
  {
    assert(letter::isSymbol2(character) == true);
  }

  // 記号かどうかの判定3
  std::string symbolData3{"[\\]^_`"};
  for (const auto &character : symbolData3)
  {
    assert(letter::isSymbol3(character) == true);
  }

  // 記号かどうかの判定4
  std::string symbolData4{"{|}~"};
  for (const auto &character : symbolData4)
  {
    assert(letter::isSymbol4(character) == true);
  }

  return 0;
}