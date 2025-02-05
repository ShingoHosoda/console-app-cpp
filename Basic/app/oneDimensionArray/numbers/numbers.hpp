#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
namespace app
{
  /// @brief 数字かどうか確認する。
  /// @param s 文字列
  /// @return 数字の場合Trueを返す、数字でない場合はFalseを返す。
  bool isNumber(std::string &s);
  
  /// @brief 値を数値リストに追加する。
  /// @param numbers 数値リスト
  /// @param number 追加する数値
  void add(std::vector<int> &numbers, std::string number);

  /// @brief 値を数値リストから削除する。
  /// @param numbers 数値リスト
  /// @param number 削除する数値
  void remove(std::vector<int> &numbers, std::string number);

  /// @brief 数値リストの値を更新する。
  /// @param numbers 数値リスト
  /// @param number1 更新前の数値
  /// @param number2 更新後の数値
  void update(std::vector<int> &numbers, std::string number1, std::string number2);

  /// @brief 目的の値を数値リストから探索する。
  /// @param numbers 数値リスト
  /// @param number 探索する数値
  void find(std::vector<int> &numbers, std::string number);

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