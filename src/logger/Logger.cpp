#include "Logger.h"
#include <iostream>
#include <string>

using namespace std;

void Logger::printFlagMacro() {
#ifdef FLAG_MACRO
    cout << "FLAG_MACRO defined" << endl;
#endif
}

void Logger::printValueMacro() {
#ifdef VALUE_MACRO
    cout << "VALUE_MACRO defined: " << VALUE_MACRO << endl;
#endif
}

void Logger::printStringMacro() {
#ifdef STRING_MACRO
    cout << "STRING_MACRO defined: " << STRING_MACRO << endl;
#endif
}

void Logger::configNewOuputStreams() {
    const auto path = string(LOGS_PATH) + "/output.log";
    this->logFile = ofstream(path.c_str());
    auto* originalCoutBuffer = cout.rdbuf();

    this->dualBuffer = new DualStreamBuffer(originalCoutBuffer, logFile.rdbuf());
    cout.rdbuf(dualBuffer);
}

void Logger::close() {
    logFile.close();
    delete dualBuffer;
}
