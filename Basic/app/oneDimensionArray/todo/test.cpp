#include <iostream>
#include <cassert>
#include <string>
#include <random>
#include "Todo.hpp"
/// @brief IDの生成。
/// @param candidateCharacters 候補の文字
/// @param length IDの長さ。
/// @return 生成したIDを返す。
std::string createID(const std::string &candidateCharacters, std::size_t length)
{
  assert(!candidateCharacters.empty());
  std::random_device engine;
  std::uniform_int_distribution<std::size_t> dist(0, candidateCharacters.size() - 1);
  std::string password;
  for (std::size_t i = 0; i < length; i++)
  {
    std::size_t randomIndex = dist(engine);
    char randomCharacter = candidateCharacters[randomIndex];
    password += randomCharacter;
  }

  return password;
}
int main()
{

  return 0;
}