#include "readLetter.hpp"

bool letter::readLetter(const std::string path, std::vector<std::string> &letter)
{
  std::ifstream ifs(path);
  if (!ifs)
  {
    std::cout << "Not Found ファイルを読み込めませんでした。\n";
    return false;
  }

  while (ifs.eof() == false)
  {
    std::string inputOneLineText;
    std::getline(ifs, inputOneLineText);
    std::istringstream stream(inputOneLineText);
    std::string text{};
    while (stream.eof() == false)
    {
      std::string word{}; // 単語を読み込む
      stream >> word;
      if (stream.eof() == false)
      {
        text += word + " "; // 単語は空白で区切る
      }
      else
      {
        text += word; // 最終列のみ空白を開けない
      }
    }
    // std::cout << text;
    letter.push_back(text);
  }
  return true;
}