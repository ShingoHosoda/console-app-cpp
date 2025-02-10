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

  std::cout << "TODOの期限を入力してください: ";
  std::getline(std::cin, todo.dueDate);

  std::cout << "TODOが完了済みかどうか入力してください: ";
  std::getline(std::cin, tmp);
  stream.str(tmp);
  stream >> todo.completed;
  if (!stream)
  {
    std::cout << "入力値が正しくありません。TODOを追加できませんでした。\n";
    return false; // 正常に追加できなかった。
  }

  std::cout << "新しいTODOを追加します。\n";
  todos.push_back(todo);
  return true; // 正常に追加できた。
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

  todos.erase(iterator);
  std::cout << "指定されたTODOは削除しました。\n";
  return true;
}

bool app::update(std::vector<Todo> &todos)
{
  std::cout << "TODOを更新します。" << std::endl;
  std::cout << "タイトル名を入力してください: ";
  std::string title{};
  std::getline(std::cin, title);
  for (auto &todo : todos)
  {
    if (todo.title == title)
    {
      std::string newTitle{};
      std::cout << "新しいタイトルを入力してください: ";
      std::getline(std::cin, newTitle);
      todo.title = newTitle;

      std::string dueDate{};
      std::cout << "新しい期限日を入力してください: ";
      std::getline(std::cin, dueDate);
      todo.dueDate = dueDate;

      std::istringstream stream{};
      std::string tmp{};
      std::cout << "TODOが完了済みかどうか入力してください: ";
      std::getline(std::cin, tmp);
      stream.str(tmp);
      stream >> todo.completed;

      return true;
    }
  }
  std::cout << "指定されたTODOは存在しません。\n";
  return false;
}

std::vector<app::Todo> app::findByTitle(const std::vector<Todo> &todos)
{
  std::vector<Todo> results;
  std::cout << "タイトル名からTODOを検索を行い出力します。\n";
  std::cout << "タイトル名を入力してください。\n";
  std::string title{};
  std::getline(std::cin, title);
  for (auto &todo : todos)
  {
    if (todo.title = title)
    {
      results.push_back(todo);
    }
  }
  return results;
}

std::vector<app::Todo> app::findByDueDate(const std::vector<Todo> &todos)
{
  std::vector<Todo> results;
  std::cout << "期限日からTODOを検索を行い出力します。\n";
  std::cout << "期限日を入力してください。\n";
  std::string dueDate{};
  std::getline(std::cin, dueDate);
  for (auto &todo : todos)
  {
    if (todo.dueDate = dueDate)
    {
      results.push_back(todo);
    }
  }
  return results;
}

std::vector<app::Todo> app::findByCompleted(const std::vector<Todo> &todos)
{
  std::vector<Todo> results;
  std::cout << "完了済みかどうかTODOを検索を行い出力します。\n";
  std::cout << "完了済みかどうかを入力してください。\n";
  std::string input;
  std::getline(std::cin, input);
  std::istringstream stream(input);
  bool completed{};
  stream >> completed;
  for (auto &todo : todos)
  {
    if (todo.completed = completed)
    {
      results.push_back(todo);
    }
  }
  return results;
}

bool app::writeTSV(const std::vector<Todo> &todos, const std::string &path)
{
  std::ofstream ofs(path);
  if (!ofs)
  {
    std::cout << "TODOファイルが開けませんでした。\n";
    return false;
  }

  auto count = 0;
  auto len = todos.size();
  for (auto &todo : todos)
  {
    if (count == len - 1)
    {
      ofs << todo.id << " " << todo.title << " " << todo.dueDate << " " << todo.completed;
    }
    else
    {
      ofs << todo.id << " " << todo.title << " " << todo.dueDate << " " << todo.completed << "\n";
    }
    count += 1;
  }

  if (!ofs)
  {
    std::cout << "TODOをファイルに書き込めませんでした。\n";
    return false;
  }

  std::cout << "TODOをファイルに書き込みました。\n";
  return true;
}

bool app::readTSV(std::vector<Todo> &todos, const std::string &path)
{
  std::cout << "TODOファイルを読み込みます。\n";
  std::ifstream ifs(path);
  if (!ifs)
  {
    std::cout << "TODOファイルが開けませんでした。\n";
    return false;
  }

  todos.clear(); // メモリ上のデータをすべて消す。

  while (ifs.eof() == false)
  {
    std::string text;
    std::getline(ifs, text);
    std::istringstream stream(text);
    std::string id, title, dueDate;
    bool isCompleted;
    stream >> id >> title >> dueDate >> isCompleted;
    todos.push_back({id, title, dueDate, isCompleted});
  }

  return true;
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