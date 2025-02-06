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
  /// @return 正常に数値を追加できた場合true、追加できなかった場合falseを返します。
  bool add(std::vector<int> &numbers, std::string number);

  /// @brief 値を数値リストから削除する。
  /// @param numbers 数値リスト
  /// @param number 削除する数値
  /// @return 正常に数値を削除できた場合true、削除できなかった場合falseを返します。
  bool remove(std::vector<int> &numbers, std::string number);

  /// @brief 数値リストの値を更新する。
  /// @param numbers 数値リスト
  /// @param number1 更新前の数値
  /// @param number2 更新後の数値
  /// @return 正常に数値を更新できた場合true、更新できなかった場合falseを返します。
  bool update(std::vector<int> &numbers, std::string number1, std::string number2);

  /// @brief 目的の値を数値リストから探索する。
  /// @param numbers 数値リスト
  /// @param number 探索する数値
  /// @return 正常に数値を検索できた場合true、検索できなかった場合falseを返します。
  bool find(std::vector<int> &numbers, std::string number);

  /// @brief 数値リストを昇順にソートする。
  /// @param numbers 数値リスト
  void sortAsc(std::vector<int> &numbers);

  /// @brief 数値リストを降順にソートする。
  /// @param numbers 数値リスト
  void sortDesc(std::vector<int> &numbers);

  /// @brief 数値リストを表示する。
  /// @param numbers 数値リスト
  void print(std::vector<int> &numbers);

  /// @brief 数値リストのEXIT制御
  /// @param isChanged 数値リストがファイルに書き込まれていない場合True、書き込まれている場合False。
  /// @return 数値リストアプリケーションを終了する場合True、終了しない場合はFalseを返す。
  bool exit(bool isChanged);
}