#include <string>

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "order.hpp"


class MockBasket : public IBasket
{
    public:
        MOCK_METHOD (void, pay, (), (override));
};



TEST(OrderTests, PlacingOrderPaysForbasket) 
{
    MockBasket basket;
    Order order(basket);
    EXPECT_CALL(basket, pay()).Times(1);
    order.placeOrder();
}

