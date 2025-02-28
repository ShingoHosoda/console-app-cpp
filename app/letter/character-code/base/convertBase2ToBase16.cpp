/****************************************
 * 2進数を16進数に変換するプログラム
 * Nは8、16、32、64、256のどれか
 * 計算は符号なし64ビットで行います。
 * 2進数 -> 10進数 -> 16進数に変換します。
 ***************************************/
#include <iostream>
#include <algorithm>
#include <cassert>
using u32 = unsigned int;       // 符号なし32ビット
using u64 = unsigned long long; // 符号なし64ビット
constexpr u64 FOUR_BIT = 4;     // 4ビット
constexpr u64 BASE16 = 16;      // 16進数
/// @brief 2進数を10進数に変換します。
/// @param bits
/// @return
[[nodiscard]]
u64 convertBase2ToBase10(std::string &bits)
{
  u64 answer = 0;
  u64 powN = 1;
  u32 count = 0;
  std::reverse(bits.begin(), bits.end());
  for (const char &charBit : bits)
  {
    u32 bit = charBit - '0';
    u64 decimal = bit * powN;
    answer += decimal;
    powN *= 2;
    count++;
  }

  return answer;
}

/// @brief 10進数の値をN進数に変換します。
/// @param decimal 10進数の値。
/// @param base 変換したい基数。
/// @return 基数変換後の数値を返します。
[[nodiscard]]
std::string convertBase10ToBaseN(u64 decimal, const u64 base)
{
  constexpr char digits[] = "0123456789ABCDEF";
  std::string value{};
  do
  {
    value.push_back(digits[decimal % base]);
    decimal /= base;
  } while (decimal);

  std::reverse(std::begin(value), std::end(value));

  return value;
}

/// @brief 2進数から16進数に変換。
/// @param binary 2進数。
/// @param N 桁数。
/// @return 16進数に変換した値を返す。
[[nodiscard]]
std::string convertBase2ToBase16(const std::string binary, const u64 N)
{
  u64 bitsMax = N / FOUR_BIT;
  std::string answer;
  for (u64 i = 0; i < bitsMax; i++)
  {
    std::string fourBits = binary.substr(i * 4, FOUR_BIT); // 4ビットずつ取り出す
    auto decimal = convertBase2ToBase10(fourBits);
    auto hex = convertBase10ToBaseN(decimal, BASE16);
    answer += hex;
  }
  return answer;
}

int main()
{
  assert(convertBase2ToBase16("0000001111001111", 16) == "03CF");
  assert(convertBase2ToBase16("11000110001100110110010000000001", 32) == "C6336401");
  return 0;
}