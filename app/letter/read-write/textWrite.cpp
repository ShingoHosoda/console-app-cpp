#include "textWrite.hpp"

bool letter::textWrite(const std::string path, const std::vector<std::string> &letter)
{
  std::ofstream ofs(path);
  if (!ofs)
  {
    std::cout << "Not Found ファイルを書き込めませんでした。\n";
    return false;
  }

  auto index = 0;
  auto size = letter.size();
  for (const auto &text : letter)
  {
    if (index == size - 1)
    {
      ofs << text; // 最終列のみ改行しない
    }
    else
    {
      ofs << text << "\n";
    }
    index += 1;
  }

  return true;
}