#pragma once

#include <string>

#include "IMessageSink.hpp"

class Greeter {
public:
    explicit Greeter(IMessageSink& sink);
    void greet(const std::string& name);

private:
    IMessageSink& sink_;
};
