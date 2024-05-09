#pragma once

#include <cstdlib>
#include <string>

namespace LemLog {
enum class Level { 
    INFO, 
    DEBUG, 
    WARN, 
    ERROR, 
    FATAL
};

inline std::string level_format(Level level) {
    switch (level) {
        case Level::INFO: return "INFO";
        case Level::DEBUG: return "DEBUG";
        case Level::WARN: return "WARN";
        case Level::ERROR: return "ERROR";
        case Level::FATAL: return "FATAL";
        default: std::exit(EXIT_FAILURE); // TODO: change handling (?)
    }
}

struct Message {
    std::string text;
    Level level;
    uint32_t time;
};
}