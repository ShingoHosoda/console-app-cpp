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
  return false;
}

bool app::remove(std::vector<Todo> &todos)
{
  return false;
}

bool app::update(std::vector<Todo> &todos)
{
  return false;
}

void app::findByTitle(const std::vector<Todo> &todos)
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
}

bool app::exit(bool isChanged)
{
  return false;
}