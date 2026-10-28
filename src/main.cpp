#include <iostream>
#include <string>

#include "Greeter.hpp"

namespace {

class ConsoleSink : public IMessageSink {
public:
    void send(const std::string& message) override {
        std::cout << message << '\n';
    }
};

}  // namespace

int main() {
    ConsoleSink sink;
    Greeter greeter(sink);
    greeter.greet("CMake");
    return 0;
}
