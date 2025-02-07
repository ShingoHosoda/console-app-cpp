#pragma once
#include <iostream>
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

}