#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include "message.hpp"

namespace LemLog {
class Sink {
    public:
    virtual void sendMessage(Message message) = 0;
    virtual ~Sink() {}
};
class StdoutSink : public Sink {
    public:
    virtual void sendMessage(Message message) {
        std::cout << formatMessage(message);
    }
    private:
    std::string formatMessage(Message message) {
        switch (message.level) {
            case Level::DEBUG:
                return "[" + std::to_string(message.time) + "ms] DEBUG: " + message.text;
            case Level::INFO:
                return "[" + std::to_string(message.time) + "ms] INFO: " + message.text;
            case Level::WARN:
                return "[" + std::to_string(message.time) + "ms] WARN: " + message.text;
            case Level::ERROR:
                return "[" + std::to_string(message.time) + "ms] ERROR: " + message.text;
            case Level::FATAL:
                return "[" + std::to_string(message.time) + "ms] FATAL: " + message.text;
            default:
                std::exit(EXIT_FAILURE); // TODO: change handling (?)
        }
    }
};
}