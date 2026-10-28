#pragma once

#include "IBasket.hpp"
#include "IItem.hpp"
#include <vector>


class Basket : public IBasket
{
    public:
        Basket(std::vector<IItem*> items)  {
            this->items = items;
        }
        void pay()
        {

        }
        double calculateOrderTotal()
        {
            double total = 0;
            for (auto item : items) {
                total += item->calculateSubtotal();
            }
            return total;
        }

        std::vector<IItem*> items;

};