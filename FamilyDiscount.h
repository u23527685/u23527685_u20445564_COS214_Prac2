#ifndef FAMILYDISCOUNT_H
#define FAMILYDISCOUNT_H
#include "DiscountStrategy.h"
using namespace std;

class FamilyDiscount : public DiscountStrategy{
    public:
        virtual int applyDiscount(double totalPrice, int pizzaCount);
        virtual string getDiscountName();
};
#endif