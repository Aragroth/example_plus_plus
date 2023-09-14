#include <filesystem>
#include <fstream>
#include <iostream>

#include "FileManager.hpp"

namespace fs = std::filesystem;

FileManager::FileManager() {}

bool FileManager::CopyFile(const std::string &sourcePath,
                           const std::string &destinationPath) {
  try {
    fs::copy_file(sourcePath, destinationPath);
    std::cout << "File copied successfully." << std::endl;
    return true;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return false;
  }
}

bool FileManager::MoveFile(const std::string &sourcePath,
                           const std::string &destinationPath) {
  try {
    fs::rename(sourcePath, destinationPath);
    std::cout << "File/directory moved/renamed successfully." << std::endl;
    return true;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return false;
  }
}

bool FileManager::DeleteFile(const std::string &path) {
  try {
    fs::remove_all(path);
    std::cout << "File/directory deleted successfully." << std::endl;
    return true;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return false;
  }
}
