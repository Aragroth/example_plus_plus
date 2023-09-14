#ifndef ScreenManager_H_
#define ScreenManager_H_

class ScreenManager {
public:
  ScreenManager();

  void DisplayMessage(const std::string &message) const;

  void DisplayList( std::vector<std::string> &items);
  
  std::string GetUserInput(const std::string &prompt);
};


#endif
