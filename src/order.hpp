#pragma once
#include "IBasket.hpp"

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