#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
namespace letter
{
  /// @brief 手紙の本文のみ読み込む。
  /// @param path ファイルパス。
  /// @param letter 手紙本文のデータ。
  /// @return 手紙本文のみ返す。
  [[nodiscard]]
  bool readLetter(const std::string path, std::vector<std::string> &letter);
}