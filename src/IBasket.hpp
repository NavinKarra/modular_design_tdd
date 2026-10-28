#pragma once

class IBasket 
{
    public:
        virtual ~IBasket() = default;
        virtual void pay() = 0;
};
