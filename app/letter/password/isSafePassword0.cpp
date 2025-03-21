/***************************
 * パスワードの強度判定（0）
 * パスワードの文字がすべて同じかどうかを判定。
 * パスワードの文字がすべて異なる場合"Safe"と出力。
 * パスワードの文字がすべて同じ場合"Dangerous"と出力。
 ***************************/
#include <iostream>
#include <cassert>

/// @brief パスワードがすべて同一の文字どうかを判定します。
/// @param password パスワード。
/// @return パスワードがすべて同一の文字の場合True、そうでない場合はFalseを返します。
bool isEqualsLetter(const std::string password)
{
  auto flag = true;
  auto length = password.size() - 1;
  for (int i = 0; i < length; i++)
  {
    if (password[i] != password[i + 1])
    {
      flag = false;
    }
  }
  return flag;
}

/// @brief パスワードが安全かどうか文字列を返します。
/// @param password パスワード。
/// @return 安全の場合Safe、そうでない場合Dangerousを返します。
std::string isSafePassword(std::string password)
{
  if (!isEqualsLetter(password))
  {
    return "Safe";
  }

  return "Dangerous";
}

int main()
{
  // 安全な場合
  assert(isSafePassword("0123456789") == "Safe");
  assert(isSafePassword("ABCDEFG") == "Safe");
  // 安全でない場合
  assert(isSafePassword("1111111111") == "Dangerous");
  assert(isSafePassword("AAAAA") == "Dangerous");

  return 0;
}