#include <iostream>
#include "ErrorLog.h"


void ErrorLog::Log(ErrorLog::ErrorType errorType) {
    if (debugMode) std::cout << error_strings.at(errorType) << std::endl;
}
