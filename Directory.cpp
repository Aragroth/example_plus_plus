#include <filesystem>
#include <iostream>
#include <vector>

#include "FileSystemItem.hpp"

#include "Directory.hpp"

namespace fs = std::filesystem;

Directory::Directory(const fs::path &path) : FileSystemItem(path) {}

std::vector<FileSystemItem> Directory::ListContents() const {
  std::vector<FileSystemItem> contents;

  try {
    if (IsDirectory()) {
      for (const auto &entry : fs::directory_iterator(GetFullPath())) {
        contents.emplace_back(entry);
      }
    }
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  return contents;
}
