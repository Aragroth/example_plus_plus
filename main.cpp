#include "CommandLineParser.hpp"
#include "Directory.hpp"
#include "File.hpp"
#include "FileExplorer.hpp"
#include "FileManager.hpp"
#include "ScreenManager.hpp"

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char **argv) {
  ScreenManager screenManager;
  FileManager fileManager;

  CommandLineParser parser(argc, argv);
  const std::vector<std::string> &args = parser.GetArguments();
  std::string start_directory;
  if (args.size() > 0) {
    start_directory = args[0];
  } else {
    start_directory = std::string("./");
  }
  FileExplorer explorer(start_directory);

  screenManager.DisplayMessage("Welcome to the File Explorer!");

  while (true) {
    screenManager.DisplayMessage("Current Directory: " +
                                 explorer.GetCurrentPath());
    screenManager.DisplayMessage(
        "Options: 'ls' to list, 'cd <dir>' to change directory, "
        "'exit' to quit");

    std::string command = screenManager.GetUserInput("Enter your choice:");

    if (command == "ls") {
      explorer.ListCurrentDirectory();
    } else if (command == "cd") {
      std::string newDir = screenManager.GetUserInput("Enter your choice:");
      explorer.ChangeDirectory(newDir);
    } else if (command == "stat") {
      std::string name = screenManager.GetUserInput("Enter your choice:");
      FileSystemItem item(name);
      item.DisplayInfo();

    } else if (command == "read") {
      std::string name = screenManager.GetUserInput("Enter your choice:");
      File file(name);
      std::string fileContents = file.ReadContents();
      screenManager.DisplayMessage("Contents of the File:");
      screenManager.DisplayMessage(fileContents);

    } else if (command == "exit") {
      break;
    }

    if (command == "copy") {
      std::string source = screenManager.GetUserInput("Enter source filename:");
      std::string destination =
          screenManager.GetUserInput("Enter destination:");
      fileManager.CopyFile(source, destination);
    } else if (command == "move") {
      std::string source = screenManager.GetUserInput("Enter source filename:");
      std::string destination =
          screenManager.GetUserInput("Enter destination:");
      fileManager.MoveFile(source, destination);
    } else if (command == "delete") {
      std::string detele_file =
          screenManager.GetUserInput("Enter delete filename:");
      fileManager.DeleteFile(detele_file);
    }

    std::cerr << "Invalid command. Try again." << std::endl;
  }
}