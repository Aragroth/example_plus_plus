#include <iostream>
#include <string>
#include <vector>

#include "CommandLineParser.hpp"

CommandLineParser::CommandLineParser(int argc, char *argv[]) {
  if (argc > 0) {
    command = argv[0];
  }
  for (int i = 1; i < argc; ++i) {
    arguments.push_back(argv[i]);
  }
}

std::string CommandLineParser::GetCommand() const { return command; }

const std::vector<std::string> &CommandLineParser::GetArguments() const {
  return arguments;
}
