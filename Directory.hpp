#ifndef Directory_H_
#define Directory_H_

#include <filesystem>
#include <iostream>
#include <vector>

#include "FileSystemItem.hpp"

namespace fs = std::filesystem;


class Directory : public FileSystemItem {
public:
  Directory(const fs::path &path);

  std::vector<FileSystemItem> ListContents() const;
};

#endif



