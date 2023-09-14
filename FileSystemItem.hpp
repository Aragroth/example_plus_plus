#ifndef FileSystemItem_H_
#define FileSystemItem_H_

#include <filesystem>
namespace fs = std::filesystem;

class FileSystemItem {
public:
  FileSystemItem(const fs::path &path);

  fs::path GetPath();
  std::string GetName() const;

  std::string GetFullPath() const;

  bool IsDirectory() const;

  bool IsFile() const;

  void DisplayInfo() const;

private:
  fs::path itemPath;
};

#endif
