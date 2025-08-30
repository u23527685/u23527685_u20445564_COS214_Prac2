#ifndef FAMILYDISCOUNT_H
#define FAMILYDISCOUNT_H
#include "DiscountStrategy.h"

using namespace std;
class Order;
class FamilyDiscount : public DiscountStrategy{
    public:
        FamilyDiscount();
        virtual double applyDiscount(double totalPrice);
        virtual string getDiscountName();
};
#endif