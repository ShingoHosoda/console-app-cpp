#pragma once
#include <iostream>
#include <cassert>
#include <string>
#include <fstream>
#include <sstream>
#include <random>
namespace app
{
  /// @brief TODO
  struct Todo
  {
    std::string id;
    std::string title;
    std::string dueDate;
    bool completed;

    /// @brief デフォルトコンストラクタ-1
    Todo() = default;

    /// @brief デフォルトコンストラクタ-2
    /// @param
    Todo(const Todo &) = default;

    /// @brief コンストラクター
    /// @param _id TODOのID
    /// @param _title TODOのタイトル
    /// @param _dueDate TODOの期限日
    /// @param _completed TODOが完了したかどうか
    Todo(std::string _id, std::string _title, std::string _dueDate, bool _completed) noexcept : id{_id}, title{_title}, dueDate{_dueDate}, completed{_completed} {}

    [[nodiscard]]
    friend constexpr bool operator==(Todo &todo1, Todo &todo2)
    {
      return (todo1.id) == (todo2.id) && (todo1.title) == (todo2.title) && (todo1.dueDate) == (todo2.dueDate) && (todo1.completed) == (todo2.completed);
    }

    template <class CharType>
    friend std::basic_ostream<CharType> &operator<<(std::basic_ostream<CharType> &output, const Todo &todo)
    {
      return output << todo.id << CharType(',') << CharType(' ') << todo.title << CharType(',') << CharType(' ') << todo.dueDate << CharType(',') << CharType(' ') << todo.completed;
    }
  };

  /// @brief TODOリストに新しいTODOを追加します。
  /// @param todos TODOリスト。
  /// @return 正常にTODOを追加した場合True、追加できなかった場合falseを返します。
  bool add(std::vector<Todo> &todos);

  /// @brief TODOリストからTODOを削除します。
  /// @param todos TODOリスト。
  /// @return 正常にTODOを削除した場合True、削除できなかった場合はFalseを返します。
  bool remove(std::vector<Todo> &todos);

  /// @brief TODOリストを更新する。
  /// @param todos TODOリスト。
  /// @return 正常にTODOを更新できた場合True、更新できなかった場合False。
  bool update(std::vector<Todo> &todos);

  /// @brief タイトル名からTODOを検索します。
  /// @param todos TODOリスト
  std::vector<Todo> findByTitle(const std::vector<Todo> &todos);

  /// @brief 期限日からTODOを検索します。
  /// @param todos TODOリスト
  std::vector<Todo> findByDueDate(const std::vector<Todo> &todos);

  /// @brief 完了済みかどうかTODOを検索します。
  /// @param todos TODOリスト
  std::vector<Todo> findByCompleted(const std::vector<Todo> &todos);

  /// @brief TODOリストをファイルに書き込みます。
  /// @param todos TODOリスト
  /// @return 正常に書き込まれた場合True、ファイルが開けないもしくは書き込みが行えなかった場合はFalseを返します。
  bool writeTSV(const std::vector<Todo> &todos);

  /// @brief TODOリストをファイルを読み込みます。
  /// @param todos TODOリスト
  /// @return 正常に読み込めた場合True、ファイルが開けなかった場合Falseを返します。
  bool readTSV(const std::vector<Todo> &todos);

  /// @brief 登録されているTODOを出力します。
  /// @param todos TODOリスト
  void print(const std::vector<Todo> &todos);

  /// @brief TODOアプリケーションのEXIT制御
  /// @param isChanged TODOがファイルに書き込まれていない場合True、書き込まれている場合False
  /// @return TODOアプリケーションを終了する場合True、終了しない場合はFalseを返す。
  bool exit(bool isChanged);
  
  /// @brief IDを生成する。
  /// @param candidateCharacters 生成候補の文字列。
  /// @param length 文字列の長さ。
  /// @return 生成したIDを返す。
  std::string generateID(const std::string &candidateCharacters, std::size_t length);
}
