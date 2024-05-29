#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include "DualStreamBuffer.h"

class Logger {
private:
    std::ofstream logFile;
    DualStreamBuffer* dualBuffer = nullptr;
public:
    static void printFlagMacro();
    static void printValueMacro();
    static void printStringMacro();

    void configNewOuputStreams();
    void close();
};

#endif // LOGGER_H
