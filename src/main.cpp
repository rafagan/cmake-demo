#include <iostream>
#include "logger/Logger.h"
#include "math/Circle.h"

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

    logger.close();

    return 0;
}
