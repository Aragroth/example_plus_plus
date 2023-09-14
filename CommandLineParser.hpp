#ifndef COMMANDLINEPARSER_H_
#define COMMANDLINEPARSER_H_

#include <string>
#include <vector>

class CommandLineParser {
public:
  CommandLineParser(int argc, char *argv[]);
  std::string GetCommand() const;
  const std::vector<std::string> &GetArguments() const;

private:
  std::string command;
  std::vector<std::string> arguments;
};

#endif