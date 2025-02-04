#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
namespace app
{
  /// @brief 値を数値リストに追加する。
  /// @param numbers 数値リスト
  void add(std::vector<int> &numbers);

  /// @brief 値を数値リストから削除する。
  /// @param numbers 数値リスト
  void remove(std::vector<int> &numbers);

  /// @brief 数値リストの値を更新する。
  /// @param numbers 数値リスト
  void update(std::vector<int> &numbers);

  /// @brief 目的の値を数値リストから探索する。
  /// @param numbers 数値リスト
  void find(std::vector<int> &numbers);

  /// @brief 数値リストを昇順にソートする。
  /// @param numbers 数値リスト
  void sortAsc(std::vector<int> &numbers);

  /// @brief 数値リストを降順にソートする。
  /// @param numbers 数値リスト
  void sortDesc(std::vector<int> &numbers);

  /// @brief 数値リストを表示する。
  /// @param numbers 数値リスト
  void print(std::vector<int> &numbers);
}