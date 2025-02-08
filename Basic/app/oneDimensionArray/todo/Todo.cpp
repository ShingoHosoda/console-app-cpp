#include "Todo.hpp"

std::string app::generateID(const std::string &candidateCharacters, std::size_t length)
{
  assert(!candidateCharacters.empty());
  std::random_device engine;
  std::uniform_int_distribution<std::size_t> dist(0, candidateCharacters.size() - 1);
  std::string password;
  for (std::size_t i = 0; i < length; i++)
  {
    std::size_t randomIndex = dist(engine);
    char randomCharacter = candidateCharacters[randomIndex];
    password += randomCharacter;
  }

  return password;
}

bool app::add(std::vector<Todo> &todos)
{
  Todo todo;
  std::istringstream stream{};
  std::string tmp{};
  std::cout << "TODOリストに新しいTODOを追加します。\n";

  std::string candidateCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  std::size_t length = 8;
  std::string id1 = app::generateID(candidateCharacters, length);
  std::string id2 = app::generateID(candidateCharacters, length);
  todo.id = id1 + "-" + id2;

  std::cout << "TODOのタイトルを入力してください。: ";
  std::getline(std::cin, todo.title);

  std::cout << "TODOの期限を入力してください。: ";
  std::getline(std::cin, todo.dueDate);

  std::cout << "TODOが完了済みかどうか。: ";
  std::getline(std::cin, tmp);
  stream.str(tmp);
  stream >> todo.completed;
  if (!stream)
  {
    std::cout << "入力値が正しくありません。TODOを追加できませんでした。\n";
    return false; // 正常に追加できなかった。
  }
  else
  {
    std::cout << "新しいTODOを追加します。\n";
    todos.push_back(todo);
    return true; // 正常に追加できた。
  }
}

bool app::remove(std::vector<Todo> &todos)
{
  std::cout << "TODOを削除します。\n";
  std::string title;
  std::cout << "タイトルを入力してください。: ";
  std::getline(std::cin, title);
  auto iterator = std::find_if(std::cbegin(todos), std::cend(todos), [title](Todo todo)
                               { return todo.title == title; });
  if (iterator == std::cend(todos))
  {
    std::cout << "指定されたTODOは存在しません。\n";
    return false;
  }
  else
  {
    todos.erase(iterator);
    std::cout << "指定されたTODOは削除しました。\n";
    return true;
  }
}

bool app::update(std::vector<Todo> &todos)
{
  return false;
}

std::vector<Todo> app::findByTitle(const std::vector<Todo> &todos)
{
}

void app::findByDueDate(const std::vector<Todo> &todos)
{
}

void app::findByCompleted(const std::vector<Todo> &todos)
{
}

bool app::writeTSV(const std::vector<Todo> &todos)
{
  return false;
}

bool app::readTSV(const std::vector<Todo> &todos)
{
  return false;
}

void app::print(const std::vector<Todo> &todos)
{
  std::cout << "登録されているTODOを出力します。\n";
  for (auto &todo : todos)
  {
    std::cout << std::boolalpha << todo << "\n";
  }
}

bool app::exit(bool isChanged)
{
  return false;
}