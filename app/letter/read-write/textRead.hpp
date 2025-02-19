#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
namespace letter
{
  /// @brief テキストファイルを読み込みます。
  /// @param path ファイルパス。
  /// @param letter テキストファイルのデータ。
  /// @return 読み込みが上手くいった場合true、そうでない場合はfalseを返します。
  [[nodiscard]]
  bool textRead(const std::string path, std::vector<std::string> &letter);
}