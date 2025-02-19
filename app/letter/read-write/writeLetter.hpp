#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
namespace letter
{
  /// @brief テキストファイルを書き込みます。
  /// @param path ファイルパス。
  /// @param letter テキストファイルのデータ。
  /// @return 書き込み上手くいった場合true、そうでない場合はfalseを返します。
  [[nodiscard]]
  bool writeLetter(const std::string path, const std::vector<std::string> &letter);
}