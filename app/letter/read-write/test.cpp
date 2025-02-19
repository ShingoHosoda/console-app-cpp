#include <iostream>
#include <vector>
#include <cassert>
#include "readLetter.hpp"
/// @brief 1行手紙の読み込みテスト
void TestReadOneLineLetter()
{
  std::cout << "テスト開始" << std::endl;
  std::vector<std::string> letter;
  std::string inputPath{"data/input/one-line-letter.txt"};
  assert(letter::readLetter(inputPath, letter) == true);
  std::vector<std::string> oneLineLetter2{{"Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum."}};
  auto index = 0;
  for (const auto &oneLineLetter1 : letter)
  {
    assert(oneLineLetter1 == oneLineLetter2[index]);
    index += 1;
  }
  std::cout << "テスト成功" << std::endl;
}

/// @brief テキストファイルの読み込みテスト
void TestReadLetter()
{
  std::cout << "テスト開始" << std::endl;
  std::vector<std::string> letter;
  std::string inputPath{"data/input/private-text-letter.txt"};
  assert(letter::readLetter(inputPath, letter) == true);
  std::vector<std::string> oneLineLetter2{
      {"PRIVATE advertisement no one knows (two today). Write me first"},
      {"through lough. Disgrace you left behind cannot get over. Will"},
      {"endeavour to stay where you left us till I hear from you, give"},
      {"your advice. Your unhappy wife not well."}};
  auto index = 0;
  for (const auto &oneLineLetter1 : letter)
  {
    assert(oneLineLetter1 == oneLineLetter2[index]);
    index += 1;
  }
  std::cout << "テスト成功" << std::endl;
}

int main()
{
  TestReadOneLineLetter();
  TestReadLetter();
  return 0;
}