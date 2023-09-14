#ifndef FileExplorer_H_
#define FileExplorer_H_

#include <string>

class FileExplorer {
public:
  FileExplorer(const std::string &path);

  std::string GetCurrentPath();

  void ListCurrentDirectory();

  void ChangeDirectory(const std::string &newPath);

private:
  Directory current_dir;
};

#endif
