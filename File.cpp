#include <filesystem>
#include <fstream>
#include <iostream>

#include "File.hpp"
#include "FileSystemItem.hpp"

namespace fs = std::filesystem;

File::File(const fs::path &path) : FileSystemItem(path) {}

std::string File::ReadContents() const {
  std::string contents;
  try {
    if (IsFile()) {
      std::ifstream file(GetFullPath());
      if (file.is_open()) {
        char c;
        while (file.get(c)) {
          contents += c;
        }
        file.close();
      }
    }
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  return contents;
}
