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
  };

}