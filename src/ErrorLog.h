#ifndef ERRORLOG_H
#define ERRORLOG_H

#include <vector>
#include <map>
#include <string>

// this class stores and handles all errors in operation
class ErrorLog {

public:
    ErrorLog();

    const enum class ErrorType {MOTOR_SPEED,ERROR_TEST};

    const std::map<ErrorType,std::string> error_strings = {{ErrorType::MOTOR_SPEED, "Motor speed not valid"}};

    void Log(ErrorType errorType);
    void Log(std::string);



private:

    // @TODO Implement error log functionality
    void printError();

    void SaveToFIle();

    bool debugMode;

};


#endif ERRORLOG_H
