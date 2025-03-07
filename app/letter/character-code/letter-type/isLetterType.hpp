#pragma once
#include <iostream>
namespace letter
{
  using char8 = char;
  constexpr char8 UPPER_CASE_MIN = 'A';
  constexpr char8 UPPER_CASE_MAX = 'Z';
  constexpr char8 LOWER_CASE_MIN = 'a';
  constexpr char8 LOWER_CASE_MAX = 'z';
  constexpr char8 NUMBER_MIN = '0';
  constexpr char8 NUMBER_MAX = '9';
  constexpr char8 SYMBOL_MIN1 = '!';
  constexpr char8 SYMBOL_MAX1 = '/';
  constexpr char8 SYMBOL_MIN2 = ':';
  constexpr char8 SYMBOL_MAX2 = '@';
  constexpr char8 SYMBOL_MIN3 = '[';
  constexpr char8 SYMBOL_MAX3 = '`';
  constexpr char8 SYMBOL_MIN4 = '{';
  constexpr char8 SYMBOL_MAX4 = '~';

  /// @brief UTF-8の文字を文字コードに変換する。
  /// @param character UTF-8の文字。
  /// @return UTF-8の文字コードを返します。
  [[nodiscard]]
  constexpr int convertCharToCharCode(const char8 character)
  {
    return (int)character;
  }

  /// @brief UTF-8の文字を大文字かどうか判定する。
  /// @param character UTF-8の文字。
  /// @return 大文字の場合true、そうでない場合はfalseを返す。
  [[nodiscard]]
  constexpr bool isUpperCase(const char8 character)
  {
    constexpr auto charCodeMin = convertCharToCharCode(UPPER_CASE_MIN);
    constexpr auto charCodeMax = convertCharToCharCode(UPPER_CASE_MAX);
    const auto charCode = convertCharToCharCode(character);
    if (charCode >= charCodeMin && charCode <= charCodeMax)
    {
      return true;
    }
    return false;
  }

  /// @brief UTF-8の文字を小文字かどうか判定する。
  /// @param character UTF-8の文字。
  /// @return 小文字の場合true、そうでない場合はfalseを返す。
  [[nodiscard]]
  constexpr bool isLowerCase(const char8 character)
  {
    constexpr auto charCodeMin = convertCharToCharCode(LOWER_CASE_MIN);
    constexpr auto charCodeMax = convertCharToCharCode(LOWER_CASE_MAX);
    const auto charCode = convertCharToCharCode(character);
    if (charCode >= charCodeMin && charCode <= charCodeMax)
    {
      return true;
    }
    return false;
  }

  /// @brief UTF-8の文字を数字かどうか判定する。
  /// @param character UTF-8の文字。
  /// @return 数字の場合true、そうでない場合はfalseを返す。
  [[nodiscard]]
  constexpr bool isNumber(const char8 character)
  {
    constexpr auto charCodeMin = convertCharToCharCode(NUMBER_MIN);
    constexpr auto charCodeMax = convertCharToCharCode(NUMBER_MAX);
    const auto charCode = convertCharToCharCode(character);
    if (charCode >= charCodeMin && charCode <= charCodeMax)
    {
      return true;
    }
    return false;
  }

  /// @brief UTF-8の文字を記号かどうか判定する。
  /// @param character UTF-8の文字。
  /// @return 記号の場合true、そうでない場合はfalseを返す。
  [[nodiscard]]
  constexpr bool isSymbol1(const char8 character)
  {
    constexpr auto charCodeMin = convertCharToCharCode(SYMBOL_MIN1);
    constexpr auto charCodeMax = convertCharToCharCode(SYMBOL_MAX1);
    const auto charCode = convertCharToCharCode(character);
    if (charCode >= charCodeMin && charCode <= charCodeMax)
    {
      return true;
    }
    return false;
  }

  /// @brief UTF-8の文字を記号かどうか判定する。
  /// @param character UTF-8の文字。
  /// @return 記号の場合true、そうでない場合はfalseを返す。
  [[nodiscard]]
  constexpr bool isSymbol2(const char8 character)
  {
    constexpr auto charCodeMin = convertCharToCharCode(SYMBOL_MIN2);
    constexpr auto charCodeMax = convertCharToCharCode(SYMBOL_MAX2);
    const auto charCode = convertCharToCharCode(character);
    if (charCode >= charCodeMin && charCode <= charCodeMax)
    {
      return true;
    }
    return false;
  }

  /// @brief UTF-8の文字を記号かどうか判定する。
  /// @param character UTF-8の文字。
  /// @return 記号の場合true、そうでない場合はfalseを返す。
  [[nodiscard]]
  constexpr bool isSymbol3(const char8 character)
  {
    constexpr auto charCodeMin = convertCharToCharCode(SYMBOL_MIN3);
    constexpr auto charCodeMax = convertCharToCharCode(SYMBOL_MAX3);
    const auto charCode = convertCharToCharCode(character);
    if (charCode >= charCodeMin && charCode <= charCodeMax)
    {
      return true;
    }
    return false;
  }

  /// @brief UTF-8の文字を記号かどうか判定する。
  /// @param character UTF-8の文字。
  /// @return 記号の場合true、そうでない場合はfalseを返す。
  [[nodiscard]]
  constexpr bool isSymbol4(const char8 character)
  {
    constexpr auto charCodeMin = convertCharToCharCode(SYMBOL_MIN4);
    constexpr auto charCodeMax = convertCharToCharCode(SYMBOL_MAX4);
    const auto charCode = convertCharToCharCode(character);
    if (charCode >= charCodeMin && charCode <= charCodeMax)
    {
      return true;
    }
    return false;
  }
}