#ifndef File_H_
#define File_H_

#include "FileSystemItem.hpp"

#include <filesystem>
namespace fs = std::filesystem;

class File : public FileSystemItem {
public:
  File(const fs::path &path);

  std::string ReadContents() const;
};

#endif
