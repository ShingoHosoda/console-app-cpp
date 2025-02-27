#include <iostream>
#include <fstream>
constexpr int MIN = 33;
constexpr int MAX = 127;

// @brief UTF8の文字コードをUTF8の文字型に変換します。
/// @param characterCode UTF8の文字コード。
/// @return UTF8の文字型を返す。
constexpr char convertCharacterCodeToChar(int characterCode)
{
  return (char)(characterCode);
}

/// @brief 10進数の値をN進数に変換します。
/// @param decimal 10進数の値。
/// @param base 変換したい基数。
/// @return 基数変換後の数値を返します。
[[nodiscard]]
std::string convertBase10ToBaseN(unsigned long long decimal, const unsigned long long base)
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

int main()
{
  std::ofstream ofs("ascii.txt");
  // 制御文字以外の文字を出力します。
  unsigned long long base16 = 16;
  for (int charCode = MIN; charCode < MAX; charCode++)
  {
    unsigned long long decimal = (unsigned long long)charCode;
    std::cout << charCode << " " << convertBase10ToBaseN(decimal, base16) << " " << convertCharacterCodeToChar(charCode) << "\n";
    ofs << charCode << " " << convertBase10ToBaseN(decimal, base16) << " " << convertCharacterCodeToChar(charCode) << "\n";
  }
  return 0;
}