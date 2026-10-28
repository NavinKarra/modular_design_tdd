#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "basket.hpp"
#include "IItem.hpp"

class MockItem : public IItem {
public:
    MOCK_METHOD(double, calculateSubtotal, (), (override));

};

TEST(basketTests, calculatingTotal)
{
    MockItem item1, item2;
    std::vector<IItem*> items = {&item1, &item2};
    Basket basket(items);


    EXPECT_CALL(item1, calculateSubtotal()).WillOnce(testing::Return(15.0));
    EXPECT_CALL(item2, calculateSubtotal()).WillOnce(testing::Return(4.99));

    EXPECT_DOUBLE_EQ(basket.calculateOrderTotal(), 19.99);
}