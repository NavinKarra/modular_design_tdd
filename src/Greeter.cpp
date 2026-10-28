#include "Greeter.hpp"

Greeter::Greeter(IMessageSink& sink) : sink_(sink) {}

void Greeter::greet(const std::string& name) {
    sink_.send("Hello, " + name + "!");
}
