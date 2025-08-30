#ifndef FAMILYDISCOUNT_H
#define FAMILYDISCOUNT_H
#include "DiscountStrategy.h"
#include "Order.h"

using namespace std;
class Order;
class FamilyDiscount : public DiscountStrategy{
    public:
        FamilyDiscount(Order* order);
        virtual int applyDiscount(double totalPrice);
        virtual string getDiscountName();
};
#endif