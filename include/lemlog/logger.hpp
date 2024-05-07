#pragma once

#include <vector>
#include <memory>
#include "sink.hpp"

namespace LemLog {
class Logger {
public:
Logger() = default;
Logger(std::vector<std::shared_ptr<LemLog::Sink>> _sinks): sinks(_sinks) {}

private:
std::vector<std::shared_ptr<LemLog::Sink>> sinks;
};
}