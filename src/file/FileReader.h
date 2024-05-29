#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>

class FileReader {
private:
    std::unique_ptr<std::ifstream> file;
public:
    explicit FileReader(const char* filename);
    [[nodiscard]] std::string readContent() const;
};

#endif // FILEREADER_H
