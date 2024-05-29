#include <iostream>
#include "logger/Logger.h"
#include "math/Circle.h"
#include "file/FileReader.h"

using namespace std;

int main() {
    Logger logger;
    logger.configNewOuputStreams();

    Logger::printFlagMacro();
    Logger::printValueMacro();
    Logger::printStringMacro();

    const auto circle = Circle(10);
    cout << circle.getArea() << endl;
    cout << circle.getPerimeter() << endl;

    const auto file = FileReader((string(RES_PATH) + "/data.txt").c_str());
    cout << file.readContent() << endl;

    logger.close();

    return 0;
}
