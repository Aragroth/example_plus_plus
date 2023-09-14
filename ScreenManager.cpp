#include <iostream>
#include <string>
#include <vector>

#include "ScreenManager.hpp"

ScreenManager::ScreenManager() {}

void ScreenManager::DisplayMessage(const std::string &message) const {
  std::cout << message << std::endl;
}

void ScreenManager::DisplayList(std::vector<std::string> &items) {
  int itemNumber = 1;
  for (const std::string &item : items) {
    std::cout << itemNumber << ". " << item << std::endl;
    itemNumber++;
  }
}

std::string ScreenManager::GetUserInput(const std::string &prompt) {
  std::string userInput;
  std::cout << prompt << " ";
  std::cin >> userInput;
  return userInput;
}
