#pragma once
class IItem
{
    public:
      virtual ~IItem() = default;
      virtual double calculateSubtotal()  = 0;

};