#include <string>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Greeter.hpp"
#include "IMessageSink.hpp"

using ::testing::InSequence;

class MockMessageSink : public IMessageSink {
public:
    MOCK_METHOD(void, send, (const std::string& message), (override));
};

TEST(GreeterTest, SendsGreetingToSink) {
    MockMessageSink sink;
    Greeter greeter(sink);

    EXPECT_CALL(sink, send("Hello, World!")).Times(1);

    greeter.greet("World");
}

TEST(GreeterTest, SendsGreetingsInCallOrder) {
    MockMessageSink sink;
    Greeter greeter(sink);

    {
        InSequence seq;
        EXPECT_CALL(sink, send("Hello, Alice!"));
        EXPECT_CALL(sink, send("Hello, Bob!"));
    }

    greeter.greet("Alice");
    greeter.greet("Bob");
}
