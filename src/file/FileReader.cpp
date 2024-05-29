#include "FileReader.h"

#include <string>
#include <sstream>
#include <memory>

using namespace std;

FileReader::FileReader(const char* filename)
    : file(std::make_unique<std::ifstream>(filename))
{
    if (!file->is_open()) {
        throw ios_base::failure(string("Failed to open file: ") + filename);
    }
}

string FileReader::readContent() const {
    stringstream buffer;
    buffer << file->rdbuf();
    return buffer.str();
}