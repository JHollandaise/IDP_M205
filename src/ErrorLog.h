//
// Created by Joseph Holland  on 07/11/2017.
//

#ifndef ERRORLOG_H
#define ERRORLOG_H

// this class stores and handles all errors in operation
class ErrorLog {

public:
    ErrorLog();

    enum class ErrorType {MOTOR_SPEED};

    void Log(ErrorType errorType);




private:
    void printError();

    void SaveToFIle();

    bool debugMode;
};


#endif ERRORLOG_H
