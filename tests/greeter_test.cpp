#include <string>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

class IBasket 
{
    public:
        virtual ~IBasket() = default;
        virtual void pay() = 0;
};
class MockBasket : public IBasket
{
    public:
        MOCK_METHOD (void, pay, (), (override));
};

class Order
{
        
    public:
        IBasket& m_basket;
        Order(IBasket& basket) : m_basket(basket) {}
        void placeOrder()
        {
            m_basket.pay();
        }
};

TEST(OrderTests, PlacingOrderPaysForbasket) 
{
    MockBasket basket;
    Order order(basket);
    EXPECT_CALL(basket, pay()).Times(1);
    order.placeOrder();
}

