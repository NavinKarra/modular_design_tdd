#pragma once

#include <string>

class IMessageSink {
public:
    virtual ~IMessageSink() = default;
    virtual void send(const std::string& message) = 0;
};
