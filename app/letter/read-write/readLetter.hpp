#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
namespace letter
{
  /// @brief 手紙の本文のみ読み込みます。
  /// @param path ファイルパス。
  /// @param letter 手紙本文のデータ。
  /// @return 読み込みが上手くいった場合true、そうでない場合はfalseを返します。
  [[nodiscard]]
  bool readLetter(const std::string path, std::vector<std::string> &letter);
}