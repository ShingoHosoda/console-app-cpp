#pragma once
#include <iostream>
#include <tuple>
#include "Todo.hpp"
namespace app
{
  struct TodoLess
  {
    constexpr bool operator()(const Todo &todo1, const Todo &todo2) const noexcept
    {
      return std::tie(todo1.id, todo1.title, todo1.dueDate, todo1.completed) < std::tie(todo2.id, todo2.title, todo2.dueDate, todo2.completed);
    }
  };
}
