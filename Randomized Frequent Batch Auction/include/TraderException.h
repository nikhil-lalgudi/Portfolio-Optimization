#ifndef TRADER_EXCEPTION_H
#define TRADER_EXCEPTION_H

#include <exception>
#include <string>

class TraderException : public std::exception {
private:
    std::string message;
public:
    explicit TraderException(const std::string& msg) : message(msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif
