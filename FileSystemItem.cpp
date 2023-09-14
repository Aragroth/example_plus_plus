#include <filesystem>
#include <iostream>

#include "FileSystemItem.hpp"

namespace fs = std::filesystem;

FileSystemItem::FileSystemItem(const fs::path &path) : itemPath(path) {}

fs::path FileSystemItem::GetPath() { return itemPath; }

std::string FileSystemItem::GetName() const {
  return itemPath.filename().string();
}

std::string FileSystemItem::GetFullPath() const { return itemPath.string(); }

bool FileSystemItem::IsDirectory() const { return fs::is_directory(itemPath); }

bool FileSystemItem::IsFile() const { return fs::is_regular_file(itemPath); }

void FileSystemItem::DisplayInfo() const {
  std::cout << "Name: " << GetName() << std::endl;
  std::cout << "Path: " << GetFullPath() << std::endl;
  std::cout << (IsDirectory() ? "Type: Directory" : "Type: File") << std::endl;
}
