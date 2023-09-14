
#include <cstdint>
#include <filesystem>
#include <fstream>

#include "Directory.hpp"
#include "FileExplorer.hpp"
#include "FileSystemItem.hpp"

namespace fs = std::filesystem;

FileExplorer::FileExplorer(const std::string &path) : current_dir(path) {}

std::string FileExplorer::GetCurrentPath() { return current_dir.GetPath(); }

void FileExplorer::ListCurrentDirectory() {
  try {
    for (const auto &entry : fs::directory_iterator(current_dir.GetPath())) {
      if (fs::is_directory(entry.status())) {
        std::cout << "[D] " << entry.path().filename() << std::endl;
      } else if (fs::is_regular_file(entry.status())) {
        std::cout << "[F] " << entry.path().filename() << std::endl;
      }
    }
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}

void FileExplorer::ChangeDirectory(const std::string &newPath) {
  try {
    fs::path newDir(newPath);
    if (fs::is_directory(newDir)) {
      current_dir = Directory(newDir);
      std::cout << "Changed directory to: " << current_dir.GetFullPath()
                << std::endl;
    } else {
      std::cerr << "Error: Not a valid directory." << std::endl;
    }
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}
