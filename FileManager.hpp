#ifndef FileManager_H_
#define FileManager_H_

class FileManager {
public:
  FileManager();

  bool CopyFile(const std::string &sourcePath,
                const std::string &destinationPath);

  bool MoveFile(const std::string &sourcePath,
                const std::string &destinationPath);

  bool DeleteFile(const std::string &path);
};


#endif
